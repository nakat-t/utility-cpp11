// This test code is based on LLVM and has been modified for this library.
//
// LLVM is licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for more information.
//
// See LICENSE for the license of the modified code.
#include <utility_cpp11/utility.hpp>

#include <type_traits>
#include <cstddef>

#include <catch2/catch.hpp>

TEST_CASE("intseq.intseq/integer_seq")
{
//  Make a few of sequences
    using int3    = bp11::integer_sequence<int, 3, 2, 1>;
    using size1   = bp11::integer_sequence<std::size_t, 7>;
    using ushort2 = bp11::integer_sequence<unsigned short, 4, 6>;
    using bool0   = bp11::integer_sequence<bool>;

//  Make sure they're what we expect
    STATIC_REQUIRE ( std::is_same<int3::value_type, int>::value );
    STATIC_REQUIRE ( int3::size() == 3 );

    STATIC_REQUIRE ( std::is_same<size1::value_type, std::size_t>::value );
    STATIC_REQUIRE ( size1::size() == 1 );

    STATIC_REQUIRE ( std::is_same<ushort2::value_type, unsigned short>::value );
    STATIC_REQUIRE ( ushort2::size() == 2 );

    STATIC_REQUIRE ( std::is_same<bool0::value_type, bool>::value );
    STATIC_REQUIRE ( bool0::size() == 0 );
}
