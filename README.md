# utility-cpp11

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
| swap | C++11 | Not needed. |
| forward | C++11 | Not needed. |
| move<br />move_if_noexcept | C++11 | Not needed. |
| exchange | C++14 | ✓ |
| as_const | C++17 | ✓ |
| declval | C++11 | Not needed. |
| cmp_equal<br />cmp_not_equal<br />cmp_less<br />cmp_greater<br />cmp_less_equal<br />cmp_greater_equal | C++20 | ✓ |
| in_range | C++20 | ✓ |
| integer_sequence<br />index_sequence<br />make_integer_sequence<br />make_index_sequence<br />index_sequence_for | C++14 | ✓ |
| pair<br />make_pair | C++11 | Not needed. |
| piecewise_construct | C++11 | Not needed. |
| in_place | C++17 | Not planned. |
| rel_ops operators | Deprecated in C++20 | Not planned. |

## Test

Tested in gcc, clang and msvc with all `-std` options.

The test cases are from [LLVM libcxx](https://libcxx.llvm.org/), which has been modified to use this library instead of std and to work with [catch2](https://github.com/catchorg/Catch2).

## License

Copyright (c) 2020 nakat-t

See [LICENSE file](./LICENSE) for license information.

### Test code license

Some of test codes are based on LLVM and has been modified for this library.  
See also the [LLVM license](https://llvm.org/LICENSE.txt) for these files.
