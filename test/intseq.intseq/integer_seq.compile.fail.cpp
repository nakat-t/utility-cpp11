// This test code is based on LLVM and has been modified for this library.
//
// LLVM is licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for more information.
//
// See LICENSE for the license of the modified code.
#include <utility_cpp11/utility.hpp>

int main(int, char**)
{
#if !utility_cpp11_HAS_INTEGER_SEQUENCE
//  Should fail to compile, since float is not an integral type
    using floatmix = bp11::integer_sequence<float>;
    floatmix::value_type I;
#else
#   error test skip
#endif
    return 0;
}
