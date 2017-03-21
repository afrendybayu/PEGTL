// Copyright (c) 2014-2017 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/taocpp/PEGTL/

#ifndef TAOCPP_PEGTL_INCLUDE_UTF8_HH
#define TAOCPP_PEGTL_INCLUDE_UTF8_HH

#include "config.hh"

#include "internal/rules.hh"
#include "internal/peek_utf8.hh"
#include "internal/result_on_found.hh"

namespace TAOCPP_PEGTL_NAMESPACE
{
   namespace utf8
   {
      struct any : internal::any< internal::peek_utf8 > {};
      template< char32_t ... Cs > struct not_one : internal::one< internal::result_on_found::FAILURE, internal::peek_utf8, Cs ... > {};
      template< char32_t Lo, char32_t Hi > struct not_range : internal::range< internal::result_on_found::FAILURE, internal::peek_utf8, Lo, Hi > {};
      template< char32_t ... Cs > struct one : internal::one< internal::result_on_found::SUCCESS, internal::peek_utf8, Cs ... > {};
      template< char32_t Lo, char32_t Hi > struct range : internal::range< internal::result_on_found::SUCCESS, internal::peek_utf8, Lo, Hi > {};
      template< char32_t ... Cs > struct ranges : internal::ranges< internal::peek_utf8, Cs ... > {};

   } // namespace utf8

} // namespace TAOCPP_PEGTL_NAMESPACE

#endif
