// This test code is based on LLVM and has been modified for this library.
//
// LLVM is licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for more information.
//
// See LICENSE for the license of the modified code.
#include <utility_cpp11/utility.hpp>

struct S {int i;};

int main(int, char**)
{
    bp11::as_const(S{});

  return 0;
}
