# utility-cpp11

![CMake and CTest CI](https://github.com/nakat-t/utility-cpp11/workflows/CMake%20and%20CTest%20CI/badge.svg)

Backport of &lt;utility&gt; in C++14/17/20 to C++11.

`std::integer_sequence`, `std::make_index_sequence`, `std::exchange` and others are available in C++11.

## Example

```cpp
#include <utility_cpp11/utility.hpp>

// Backported symbols for C++11 are defined in the bp11:: namespace.
// If the standard library is available, each definition of bp11:: will be an alias to std.

int main()
{
    int x = 0;
    int y = bp11::exchange(x, 42);

    assert(x == 42);
    assert(y == 0);
}
```

## Install

utility-cpp11 is a single header-only library. Copy `utility.hpp` into your project.

## Dependencies

utility-cpp11 depends on the C++ standard library only. (I use [catch2](https://github.com/catchorg/Catch2) for unit test)

## Backport status list

| Item | Defined in | Status |
|---|---|---|
| swap | C++11 | Available in `std` |
| forward | C++11 | Available in `std` |
| move<br />move_if_noexcept | C++11 | Available in `std` |
| exchange | C++14 | ✓ |
| as_const | C++17 | ✓ |
| declval | C++11 | Available in `std` |
| cmp_equal<br />cmp_not_equal<br />cmp_less<br />cmp_greater<br />cmp_less_equal<br />cmp_greater_equal | C++20 | ✓ |
| in_range | C++20 | ✓ |
| integer_sequence<br />index_sequence<br />make_integer_sequence<br />make_index_sequence<br />index_sequence_for | C++14 | ✓ |
| pair<br />make_pair | C++11 | Available in `std` |
| piecewise_construct | C++11 | Available in `std` |
| in_place | C++17 | No |
| rel_ops operators | Deprecated in C++20 | No |

## Test

We are testing in the following environment:

| compiler | -std options |
|---|---|
| gcc-4.8 | -std=c++11, -std=c++14 |
| gcc-4.9 | -std=c++11, -std=c++14 |
| gcc-5 | -std=c++11, -std=c++14, -std=c++17 |
| gcc-6 | -std=c++11, -std=c++14, -std=c++17 |
| gcc-7 | -std=c++11, -std=c++14, -std=c++17 |
| gcc-8 | -std=c++11, -std=c++14, -std=c++17 |
| gcc-9 | -std=c++11, -std=c++14, -std=c++17 |
| gcc-10 | -std=c++11, -std=c++14, -std=c++17, -std=c++20 |
| clang-7 (libc++) | -std=c++11, -std=c++14, -std=c++17 |
| clang-8 (libc++) | -std=c++11, -std=c++14, -std=c++17 |
| clang-9 (libc++) | -std=c++11, -std=c++14, -std=c++17 |
| clang-10 (libc++) | -std=c++11, -std=c++14, -std=c++17 |
| clang-11 (libc++) | -std=c++11, -std=c++14, -std=c++17, -std=c++20 |
| msvc14 (Visual Studio 2015 Update 3) | No /std option |
| msvc141 (Visual Studio 2017 Update 9) | /std:c++14, /std:c++17 |
| msvc142 (Visual Studio 2019 Update 8) | /std:c++14, /std:c++17 |

The test cases are from [LLVM libcxx](https://libcxx.llvm.org/), which has been modified to use this library instead of std and to work with [catch2](https://github.com/catchorg/Catch2).

## License

Copyright (c) 2020 nakat-t

See [LICENSE file](./LICENSE) for license information.

### Test code license

Some of test codes are based on LLVM and has been modified for this library.  
See also the [LLVM license](https://llvm.org/LICENSE.txt) for these files.
