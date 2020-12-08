// This test code is based on LLVM and has been modified for this library.
//
// LLVM is licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for more information.
//
// See LICENSE for the license of the modified code.
#include <utility_cpp11/utility.hpp>

#include <string>

#include <catch2/catch.hpp>

#if utility_cpp11_HAS_CONSTEXPR14
constexpr bool test_constexpr() {
    int v = 12;

    if (12 != bp11::exchange(v,23) || v != 23)
        return false;

    if (23 != bp11::exchange(v,static_cast<short>(67)) || v != 67)
        return false;

    if (67 != bp11::exchange<int, short>(v, {}) || v != 0)
        return false;
    return true;
    }
#endif



TEST_CASE("utility.exchange/exchange")
{
    {
    int v = 12;
    REQUIRE ( bp11::exchange ( v, 23 ) == 12 );
    REQUIRE ( v == 23 );
    REQUIRE ( bp11::exchange ( v, static_cast<short>(67) ) == 23 );
    REQUIRE ( v == 67 );

    REQUIRE ((bp11::exchange<int, short> ( v, {} )) == 67 );
    REQUIRE ( v == 0 );

    }

    {
    bool b = false;
    REQUIRE ( !bp11::exchange ( b, true ));
    REQUIRE ( b );
    }

    {
    const std::string s1 ( "Hi Mom!" );
    const std::string s2 ( "Yo Dad!" );
    std::string s3 = s1; // Mom
    REQUIRE ( bp11::exchange ( s3, s2 ) == s1 );
    REQUIRE ( s3 == s2 );
    REQUIRE ( bp11::exchange ( s3, "Hi Mom!" ) == s2 );
    REQUIRE ( s3 == s1 );

    s3 = s2; // Dad
    REQUIRE ( bp11::exchange ( s3, {} ) == s2 );
    REQUIRE ( s3.size () == 0 );

    s3 = s2; // Dad
    REQUIRE ( bp11::exchange ( s3, "" ) == s2 );
    REQUIRE ( s3.size () == 0 );
    }

#if utility_cpp11_HAS_CONSTEXPR14
    STATIC_REQUIRE(test_constexpr());
#endif
}
