// Copyright (c) 2014-2017 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/taocpp/PEGTL/

#ifndef TAOCPP_PEGTL_INCLUDE_UNIT_TESTS_TEST_FAILED_HH
#define TAOCPP_PEGTL_INCLUDE_UNIT_TESTS_TEST_FAILED_HH

#include <iostream>

#include <tao/pegtl/internal/demangle.hh>

#define TEST_FAILED( MeSSaGe )                          \
   do {                                                 \
      std::cerr << "pegtl: unit test failed for [ "     \
                << internal::demangle< Rule >()         \
                << " ] "                                \
                << MeSSaGe                              \
                << " in line [ "                        \
                << line                                 \
                << " ] file [ "                         \
                << file << " ]"                         \
                << std::endl;                           \
      ++failed;                                         \
   } while ( 0 )

#endif
