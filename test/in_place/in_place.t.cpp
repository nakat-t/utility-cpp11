#include <utility_cpp11/utility.hpp>

#include <type_traits>

#include <catch2/catch.hpp>

#define COMPILE_OK( stmt ) do { stmt; SUCCEED( #stmt ); } while(0)

TEST_CASE("in_place/in_place")
{
    REQUIRE(std::is_object<bp11::in_place_t>::value);
    REQUIRE(std::is_object<bp11::in_place_type_t<int>>::value);
    REQUIRE(std::is_object<bp11::in_place_index_t<1>>::value);
    COMPILE_OK(bp11::in_place_t obj = bp11_in_place);
    COMPILE_OK(bp11::in_place_type_t<int> obj = bp11_in_place_type(int));
    COMPILE_OK(bp11::in_place_index_t<1> obj = bp11_in_place_index(1));
}
