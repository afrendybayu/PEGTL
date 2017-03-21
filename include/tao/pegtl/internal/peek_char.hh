// Copyright (c) 2014-2017 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/taocpp/PEGTL/

#ifndef TAOCPP_PEGTL_INCLUDE_INTERNAL_PEEK_CHAR_HH
#define TAOCPP_PEGTL_INCLUDE_INTERNAL_PEEK_CHAR_HH

#include <cstddef>

#include "input_pair.hh"

namespace TAOCPP_PEGTL_NAMESPACE
{
   namespace internal
   {
      struct peek_char
      {
         using data_t = char;
         using pair_t = input_pair< char >;

         template< typename Input >
         static pair_t peek( Input & in, const std::size_t o = 0 )
         {
            return { in.peek_char( o ), 1 };
         }
      };

   } // namespace internal

} // namespace TAOCPP_PEGTL_NAMESPACE

#endif
