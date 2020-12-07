// Copyright (c) 2020 nakat-t
// See LICENSE file for license information.
#include <utility_cpp11/utility.hpp>

#include <cstdint>
#include <type_traits>

#include <catch2/catch.hpp>

template <typename T>
inline constexpr
typename std::make_unsigned<T>::type
to_unsigned(T t)
{
    using UT = typename std::make_unsigned<T>::type;
    return static_cast<UT>(t);
}

#define DO_TEST_EQUAL(expected, t, u) \
    STATIC_REQUIRE(bp11::cmp_equal    (t,  u) ==  expected); \
    STATIC_REQUIRE(bp11::cmp_not_equal(t,  u) == !expected);

#define DO_TEST_LESS(expected, t, u) \
    STATIC_REQUIRE(bp11::cmp_less         (t,  u) ==  expected); \
    STATIC_REQUIRE(bp11::cmp_greater      (u,  t) ==  expected); \
    STATIC_REQUIRE(bp11::cmp_less_equal   (u,  t) == !expected); \
    STATIC_REQUIRE(bp11::cmp_greater_equal(t,  u) == !expected);

TEST_CASE("utility.intcmp/intcmp")
{
    SECTION("cmp_equal,cmp_not_equal") {
        DO_TEST_EQUAL(true,   1,  1);
        DO_TEST_EQUAL(false,  1,  2);
        DO_TEST_EQUAL(true,  1U, 1U);
        DO_TEST_EQUAL(false, 1U, 2U);
        DO_TEST_EQUAL(true,   1, 1U);
        DO_TEST_EQUAL(false,  1, 2U);
        DO_TEST_EQUAL(false, -1, to_unsigned(-1));
        DO_TEST_EQUAL(true,  1U,  1);
        DO_TEST_EQUAL(false, 1U,  2);
        DO_TEST_EQUAL(false, to_unsigned(-1), -1);
    }

    SECTION("cmp_less,cmp_greater_equal,cmp_less_equal,cmp_greater_equal") {
        DO_TEST_LESS(true,   1,  2);
        DO_TEST_LESS(false,  1,  1);
        DO_TEST_LESS(false,  2,  1);
        DO_TEST_LESS(true,  1U, 2U);
        DO_TEST_LESS(false, 1U, 1U);
        DO_TEST_LESS(false, 2U, 1U);
        DO_TEST_LESS(true,   1, 2U);
        DO_TEST_LESS(false,  1, 1U);
        DO_TEST_LESS(false,  2, 1U);
        DO_TEST_LESS(true,  -1, 1U);
        DO_TEST_LESS(true,  -1, to_unsigned(-1));
        DO_TEST_LESS(true,  -2, to_unsigned(-1));
        DO_TEST_LESS(true,  1U, 2);
        DO_TEST_LESS(false, 1U, 1);
        DO_TEST_LESS(false, 2U, 1);
        DO_TEST_LESS(false, 1U, -1);
        DO_TEST_LESS(false, to_unsigned(-1), -1);
        DO_TEST_LESS(false, to_unsigned(-2), -1);
    }

    SECTION("in_range") {
        STATIC_REQUIRE( bp11::in_range<std::int8_t>( 127));
        STATIC_REQUIRE(!bp11::in_range<std::int8_t>( 128));
        STATIC_REQUIRE( bp11::in_range<std::int8_t>(-128));
        STATIC_REQUIRE(!bp11::in_range<std::int8_t>(-129));
        STATIC_REQUIRE( bp11::in_range<std::uint32_t>(std::int64_t(0L)));
        STATIC_REQUIRE(!bp11::in_range<std::uint32_t>(std::int64_t(-1L)));
        STATIC_REQUIRE( bp11::in_range<std::uint32_t>(std::int64_t(4294967295L)));
        STATIC_REQUIRE(!bp11::in_range<std::uint32_t>(std::int64_t(4294967296L)));
    }
}
