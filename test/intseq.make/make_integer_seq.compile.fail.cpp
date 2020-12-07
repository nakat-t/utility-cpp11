// This test code is based on LLVM and has been modified for this library.
//
// LLVM is licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for more information.
//
// See LICENSE for the license of the modified code.
#include <utility_cpp11/utility.hpp>

#include <type_traits>

int main(int, char**)
{
#if !utility_cpp11_HAS_INTEGER_SEQUENCE
    typedef bp11::make_integer_sequence<int, -3> MakeSeqT;
    MakeSeqT i;
#else
#   error test skip
#endif

    return 0;
}
