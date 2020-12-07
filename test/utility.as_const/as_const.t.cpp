// This test code is based on LLVM and has been modified for this library.
//
// LLVM is licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for more information.
//
// See LICENSE for the license of the modified code.
#include <utility_cpp11/utility.hpp>

#include <catch2/catch.hpp>

struct S {int i;};
bool operator==(const S& x, const S& y) { return x.i == y.i; }
bool operator==(const volatile S& x, const volatile S& y) { return x.i == y.i; }

template<typename T>
void test(T& t)
{
    STATIC_REQUIRE(std::is_const<typename std::remove_reference<decltype(bp11::as_const                  (t))>::type>::value);
    STATIC_REQUIRE(std::is_const<typename std::remove_reference<decltype(bp11::as_const<               T>(t))>::type>::value);
    STATIC_REQUIRE(std::is_const<typename std::remove_reference<decltype(bp11::as_const<const          T>(t))>::type>::value);
    STATIC_REQUIRE(std::is_const<typename std::remove_reference<decltype(bp11::as_const<volatile       T>(t))>::type>::value);
    STATIC_REQUIRE(std::is_const<typename std::remove_reference<decltype(bp11::as_const<const volatile T>(t))>::type>::value);

    REQUIRE(bp11::as_const(t) == t);
    REQUIRE(bp11::as_const<               T>(t) == t);
    REQUIRE(bp11::as_const<const          T>(t) == t);
    REQUIRE(bp11::as_const<volatile       T>(t) == t);
    REQUIRE(bp11::as_const<const volatile T>(t) == t);
}

TEST_CASE("utility.as_const/as_const")
{
    int i = 3;
    double d = 4.0;
    S s{2};
    test(i);
    test(d);
    test(s);
}
