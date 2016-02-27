/*=============================================================================
    Copyright (c) 2016 Paul Fultz II
    print.cpp
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include "example.h"

using namespace fit;

// ADL Lookup for ranges
namespace adl {

using std::begin;
using std::end;

template<class R>
auto adl_begin(R&& r) FIT_RETURNS(begin(r));
template<class R>
auto adl_end(R&& r) FIT_RETURNS(end(r));
}

// Iterate over a tuple
FIT_STATIC_LAMBDA_FUNCTION(for_each_tuple) = [](const auto& sequence, auto f)
{
    return unpack(by(f))(sequence);
};

// Recursively print everything
#ifdef _MSC_VER
template<class Self, class T>
auto print_with_cout(Self, const T& x) -> decltype(std::cout << x, void())
{
    std::cout << x << std::endl;
}

template<class Self, class T>
auto print_with_range(Self self, const T& range) -> decltype(self(*adl::adl_begin(range)), void())
{
    for(const auto& x:range) self(x);
}

template<class Self, class T>
auto print_with_tuple(Self self, const T& tuple) -> decltype(for_each_tuple(tuple, self), void())
{
    for_each_tuple(tuple, self);
}

FIT_STATIC_FUNCTION(simple_print) = fix(conditional(
    FIT_LIFT(print_with_cout),
    FIT_LIFT(print_with_range),
    FIT_LIFT(print_with_tuple)
));
#else
FIT_STATIC_LAMBDA_FUNCTION(simple_print) = fix(conditional(
    [](auto, const auto& x) -> decltype(std::cout << x, void())
    {
        std::cout << x << std::endl;
    },
    [](auto self, const auto& range) -> decltype(self(*adl::adl_begin(range)), void())
    {
        for(const auto& x:range) self(x);
    },
    [](auto self, const auto& tuple) // -> decltype(for_each_tuple(tuple, self), void())
    {
        for_each_tuple(tuple, self);
    }
));
#endif

// Make print function varidiac
FIT_STATIC_LAMBDA_FUNCTION(print) = by(simple_print);

int main()
{
    print(5, "Hello world");
    print(5);
    std::vector<int> v = { 1, 2, 3, 4 };
    print(v);

    auto t = std::make_tuple(1, 2, 3, 4);
    print(t);

    // auto m = std::make_tuple(3, v, t);
    // print(m);
}
