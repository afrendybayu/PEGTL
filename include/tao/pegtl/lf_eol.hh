// Copyright (c) 2016-2017 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/taocpp/PEGTL/

#ifndef TAOCPP_PEGTL_INCLUDE_LF_EOL_HH
#define TAOCPP_PEGTL_INCLUDE_LF_EOL_HH

#include "config.hh"

namespace TAOCPP_PEGTL_NAMESPACE
{
   struct lf_eol
   {
      static constexpr int ch = '\n';

      template< typename Input >
      static eol_pair match( Input & in )
      {
         eol_pair p = { false, in.size( 1 ) };
         if ( p.second ) {
            if ( in.peek_char() == '\n' ) {
               in.bump_to_next_line();
               p.first = true;
            }
         }
         return p;
      }
   };

} // namespace TAOCPP_PEGTL_NAMESPACE

#endif
