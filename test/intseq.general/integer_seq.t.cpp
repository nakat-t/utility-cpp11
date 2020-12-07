// This test code is based on LLVM and has been modified for this library.
//
// LLVM is licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for more information.
//
// See LICENSE for the license of the modified code.
#include <utility_cpp11/utility.hpp>

#include <tuple>
#include <type_traits>

#include <catch2/catch.hpp>

template <typename AtContainer, typename T, T... I>
auto extract ( const AtContainer &t, const bp11::integer_sequence<T, I...> )
-> decltype ( std::make_tuple ( std::get<I>(t)... ))
{     return  std::make_tuple ( std::get<I>(t)... ); }

TEST_CASE("intseq.general/integer_seq")
{
//  Make a couple of sequences
    using int3    = bp11::make_integer_sequence<int, 3>;     // generates int:    0,1,2
    using size7   = bp11::make_integer_sequence<size_t, 7>;  // generates size_t: 0,1,2,3,4,5,6
    using size4   = bp11::make_index_sequence<4>;            // generates size_t: 0,1,2,3
    using size2   = bp11::index_sequence_for<int, size_t>;   // generates size_t: 0,1
    using intmix  = bp11::integer_sequence<int, 9, 8, 7, 2>; // generates int:    9,8,7,2
    using sizemix = bp11::index_sequence<1, 1, 2, 3, 5>;     // generates size_t: 1,1,2,3,5

//  Make sure they're what we expect
    STATIC_REQUIRE ( std::is_same<int3::value_type, int>::value );
    STATIC_REQUIRE ( int3::size () == 3 );

    STATIC_REQUIRE ( std::is_same<size7::value_type, size_t>::value );
    STATIC_REQUIRE ( size7::size () == 7 );

    STATIC_REQUIRE ( std::is_same<size4::value_type, size_t>::value );
    STATIC_REQUIRE ( size4::size () == 4 );

    STATIC_REQUIRE ( std::is_same<size2::value_type, size_t>::value );
    STATIC_REQUIRE ( size2::size () == 2 );

    STATIC_REQUIRE ( std::is_same<intmix::value_type, int>::value );
    STATIC_REQUIRE ( intmix::size () == 4 );

    STATIC_REQUIRE ( std::is_same<sizemix::value_type, size_t>::value );
    STATIC_REQUIRE ( sizemix::size () == 5 );

    auto tup = std::make_tuple ( 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 );

//  Use them
    auto t3 = extract ( tup, int3() );
    STATIC_REQUIRE ( std::tuple_size<decltype(t3)>::value == int3::size ());
    REQUIRE ( t3 == std::make_tuple ( 10, 11, 12 ));

    auto t7 = extract ( tup, size7 ());
    STATIC_REQUIRE ( std::tuple_size<decltype(t7)>::value == size7::size ());
    REQUIRE ( t7 == std::make_tuple ( 10, 11, 12, 13, 14, 15, 16 ));

    auto t4 = extract ( tup, size4 ());
    STATIC_REQUIRE ( std::tuple_size<decltype(t4)>::value == size4::size ());
    REQUIRE ( t4 == std::make_tuple ( 10, 11, 12, 13 ));

    auto t2 = extract ( tup, size2 ());
    STATIC_REQUIRE ( std::tuple_size<decltype(t2)>::value == size2::size ());
    REQUIRE ( t2 == std::make_tuple ( 10, 11 ));

    auto tintmix = extract ( tup, intmix ());
    STATIC_REQUIRE ( std::tuple_size<decltype(tintmix)>::value == intmix::size ());
    REQUIRE ( tintmix == std::make_tuple ( 19, 18, 17, 12 ));

    auto tsizemix = extract ( tup, sizemix ());
    STATIC_REQUIRE ( std::tuple_size<decltype(tsizemix)>::value == sizemix::size ());
    REQUIRE ( tsizemix == std::make_tuple ( 11, 11, 12, 13, 15 ));
}
