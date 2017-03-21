// Copyright (c) 2014-2017 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/taocpp/PEGTL/

#ifndef TAOCPP_PEGTL_INCLUDE_INTERNAL_IF_THEN_ELSE_HH
#define TAOCPP_PEGTL_INCLUDE_INTERNAL_IF_THEN_ELSE_HH

#include "../config.hh"

#include "sor.hh"
#include "seq.hh"
#include "not_at.hh"
#include "skip_control.hh"

#include "../apply_mode.hh"
#include "../rewind_mode.hh"

#include "../analysis/generic.hh"

namespace TAOCPP_PEGTL_NAMESPACE
{
   namespace internal
   {
      template< typename Cond, typename Then, typename Else >
      struct if_then_else
      {
         using analyze_t = analysis::generic< analysis::rule_type::SOR, seq< Cond, Then >, seq< not_at< Cond >, Else > >;

         template< apply_mode A, rewind_mode M, template< typename ... > class Action, template< typename ... > class Control, typename Input, typename ... States >
         static bool match( Input & in, States && ... st )
         {
            auto m = in.template mark< M >();
            using m_t = decltype( m );

            if ( Control< Cond >::template match< A, rewind_mode::REQUIRED, Action, Control >( in, st ... ) ) {
               return m( Control< Then >::template match< A, m_t::next_rewind_mode, Action, Control >( in, st ... ) );
            }
            return m( Control< Else >::template match< A, m_t::next_rewind_mode, Action, Control >( in, st ... ) );
         }
      };

      template< typename Cond, typename Then, typename Else >
      struct skip_control< if_then_else< Cond, Then, Else > > : std::true_type {};

   } // namespace internal

} // namespace TAOCPP_PEGTL_NAMESPACE

#endif
