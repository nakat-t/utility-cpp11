// This test code is based on LLVM and has been modified for this library.
//
// LLVM is licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for more information.
//
// See LICENSE for the license of the modified code.
#include <utility_cpp11/utility.hpp>

#include <type_traits>

#include <catch2/catch.hpp>

TEST_CASE("test/intseq.make/make_integer_seq")
{
    STATIC_REQUIRE(std::is_same<bp11::make_integer_sequence<int, 0>, bp11::integer_sequence<int>>::value);
    STATIC_REQUIRE(std::is_same<bp11::make_integer_sequence<int, 1>, bp11::integer_sequence<int, 0>>::value);
    STATIC_REQUIRE(std::is_same<bp11::make_integer_sequence<int, 2>, bp11::integer_sequence<int, 0, 1>>::value);
    STATIC_REQUIRE(std::is_same<bp11::make_integer_sequence<int, 3>, bp11::integer_sequence<int, 0, 1, 2>>::value);

    STATIC_REQUIRE(std::is_same<bp11::make_integer_sequence<unsigned long long, 0>, bp11::integer_sequence<unsigned long long>>::value);
    STATIC_REQUIRE(std::is_same<bp11::make_integer_sequence<unsigned long long, 1>, bp11::integer_sequence<unsigned long long, 0>>::value);
    STATIC_REQUIRE(std::is_same<bp11::make_integer_sequence<unsigned long long, 2>, bp11::integer_sequence<unsigned long long, 0, 1>>::value);
    STATIC_REQUIRE(std::is_same<bp11::make_integer_sequence<unsigned long long, 3>, bp11::integer_sequence<unsigned long long, 0, 1, 2>>::value);
}
