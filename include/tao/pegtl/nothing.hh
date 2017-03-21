// Copyright (c) 2014-2017 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/taocpp/PEGTL/

#ifndef TAOCPP_PEGTL_INCLUDE_NOTHING_HH
#define TAOCPP_PEGTL_INCLUDE_NOTHING_HH

#include <type_traits>

#include "config.hh"

namespace TAOCPP_PEGTL_NAMESPACE
{
   template< typename Rule > struct nothing {};

   template< template< typename ... > class Action, typename Rule >
   using is_nothing = std::is_base_of< nothing< Rule >, Action< Rule > >;

} // namespace TAOCPP_PEGTL_NAMESPACE

#endif
