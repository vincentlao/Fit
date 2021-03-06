#include <fit/is_callable.hpp>
#include <ciso646>
#include "test.hpp"

template<int N>
struct callable_rank : callable_rank<N-1>
{};

template<>
struct callable_rank<0>
{};

FIT_STATIC_TEST_CASE()
{
    struct is_callable_class
    {
        void operator()(int) const
        {
        }
    };
    struct callable_test_param {};

    void is_callable_function(int)
    {
    }

    struct is_callable_rank_class
    {
        void operator()(int, callable_rank<3>) const
        {
        }

        void operator()(int, callable_rank<4>) const
        {
        }
    };

    static_assert(fit::is_callable<is_callable_class, int>::value, "Not callable");
    static_assert(fit::is_callable<is_callable_class, long>::value, "Not callable");
    static_assert(fit::is_callable<is_callable_class, double>::value, "Not callable");
    static_assert(fit::is_callable<is_callable_class, const int&>::value, "Not callable");
    static_assert(fit::is_callable<is_callable_class, const long&>::value, "Not callable");
    static_assert(fit::is_callable<is_callable_class, const double&>::value, "Not callable");
    static_assert(not fit::is_callable<is_callable_class, callable_test_param>::value, "callable failed");
    static_assert(not fit::is_callable<is_callable_class>::value, "callable failed");
    static_assert(not fit::is_callable<is_callable_class, int, int>::value, "callable failed");

    typedef void (*is_callable_function_pointer)(int);
    static_assert(fit::is_callable<is_callable_function_pointer, int>::value, "Not callable");
    static_assert(fit::is_callable<is_callable_function_pointer, long>::value, "Not callable");
    static_assert(fit::is_callable<is_callable_function_pointer, double>::value, "Not callable");
    static_assert(fit::is_callable<is_callable_function_pointer, const int&>::value, "Not callable");
    static_assert(fit::is_callable<is_callable_function_pointer, const long&>::value, "Not callable");
    static_assert(fit::is_callable<is_callable_function_pointer, const double&>::value, "Not callable");
    static_assert(not fit::is_callable<is_callable_function_pointer, callable_test_param>::value, "callable failed");
    static_assert(not fit::is_callable<is_callable_function_pointer>::value, "callable failed");
    static_assert(not fit::is_callable<is_callable_function_pointer, int, int>::value, "callable failed");

    static_assert(fit::is_callable<is_callable_rank_class, int, callable_rank<3>>::value, "Not callable");
    static_assert(fit::is_callable<is_callable_rank_class, long, callable_rank<3>>::value, "Not callable");
    static_assert(fit::is_callable<is_callable_rank_class, double, callable_rank<3>>::value, "Not callable");
    static_assert(fit::is_callable<is_callable_rank_class, const int&, callable_rank<3>>::value, "Not callable");
    static_assert(fit::is_callable<is_callable_rank_class, const long&, callable_rank<3>>::value, "Not callable");
    static_assert(fit::is_callable<is_callable_rank_class, const double&, callable_rank<3>>::value, "Not callable");

    static_assert(fit::is_callable<is_callable_rank_class, int, callable_rank<4>>::value, "Not callable");
    static_assert(fit::is_callable<is_callable_rank_class, long, callable_rank<4>>::value, "Not callable");
    static_assert(fit::is_callable<is_callable_rank_class, double, callable_rank<4>>::value, "Not callable");
    static_assert(fit::is_callable<is_callable_rank_class, const int&, callable_rank<4>>::value, "Not callable");
    static_assert(fit::is_callable<is_callable_rank_class, const long&, callable_rank<4>>::value, "Not callable");
    static_assert(fit::is_callable<is_callable_rank_class, const double&, callable_rank<4>>::value, "Not callable");

    static_assert(fit::is_callable<is_callable_rank_class, int, callable_rank<5>>::value, "Not callable");
    static_assert(fit::is_callable<is_callable_rank_class, long, callable_rank<5>>::value, "Not callable");
    static_assert(fit::is_callable<is_callable_rank_class, double, callable_rank<5>>::value, "Not callable");
    static_assert(fit::is_callable<is_callable_rank_class, const int&, callable_rank<5>>::value, "Not callable");
    static_assert(fit::is_callable<is_callable_rank_class, const long&, callable_rank<5>>::value, "Not callable");
    static_assert(fit::is_callable<is_callable_rank_class, const double&, callable_rank<5>>::value, "Not callable");

    static_assert(fit::is_callable<is_callable_rank_class, int, callable_rank<6>>::value, "Not callable");
    static_assert(fit::is_callable<is_callable_rank_class, long, callable_rank<6>>::value, "Not callable");
    static_assert(fit::is_callable<is_callable_rank_class, double, callable_rank<6>>::value, "Not callable");
    static_assert(fit::is_callable<is_callable_rank_class, const int&, callable_rank<6>>::value, "Not callable");
    static_assert(fit::is_callable<is_callable_rank_class, const long&, callable_rank<6>>::value, "Not callable");
    static_assert(fit::is_callable<is_callable_rank_class, const double&, callable_rank<6>>::value, "Not callable");

    static_assert(not fit::is_callable<is_callable_rank_class, int, callable_rank<1>>::value, "callable failed");
    static_assert(not fit::is_callable<is_callable_rank_class, long, callable_rank<1>>::value, "callable failed");
    static_assert(not fit::is_callable<is_callable_rank_class, double, callable_rank<1>>::value, "callable failed");
    static_assert(not fit::is_callable<is_callable_rank_class, const int&, callable_rank<1>>::value, "callable failed");
    static_assert(not fit::is_callable<is_callable_rank_class, const long&, callable_rank<1>>::value, "callable failed");
    static_assert(not fit::is_callable<is_callable_rank_class, const double&, callable_rank<1>>::value, "callable failed");

    static_assert(not fit::is_callable<is_callable_rank_class, callable_test_param, callable_test_param>::value, "callable failed");
    static_assert(not fit::is_callable<is_callable_rank_class, callable_rank<3>, callable_test_param>::value, "callable failed");
    static_assert(not fit::is_callable<is_callable_rank_class, callable_rank<4>, callable_test_param>::value, "callable failed");
    static_assert(not fit::is_callable<is_callable_rank_class, callable_test_param, callable_rank<3>>::value, "callable failed");
    static_assert(not fit::is_callable<is_callable_rank_class, callable_test_param, callable_rank<4>>::value, "callable failed");
    static_assert(not fit::is_callable<is_callable_rank_class>::value, "callable failed");
    static_assert(not fit::is_callable<is_callable_rank_class, int, int>::value, "callable failed");
};

FIT_STATIC_TEST_CASE()
{
    typedef int(callable_rank<0>::*fn)(int);

    static_assert(fit::is_callable<fn, callable_rank<0>&, int>::value, "Failed");
    static_assert(fit::is_callable<fn, callable_rank<1>&, int>::value, "Failed");
    static_assert(!fit::is_callable<fn, callable_rank<0>&>::value, "Failed");
    static_assert(!fit::is_callable<fn, callable_rank<0> const&, int>::value, "Failed");
};

FIT_STATIC_TEST_CASE()
{
    typedef int(callable_rank<0>::*fn)(int);

    typedef callable_rank<0>* T;
    typedef callable_rank<1>* DT;
    typedef const callable_rank<0>* CT;
    typedef std::unique_ptr<callable_rank<0>> ST;

    static_assert(fit::is_callable<fn, T&, int>::value, "Failed");
    static_assert(fit::is_callable<fn, DT&, int>::value, "Failed");
    static_assert(fit::is_callable<fn, const T&, int>::value, "Failed");
    static_assert(fit::is_callable<fn, T&&, int>::value, "Failed");
    static_assert(fit::is_callable<fn, ST, int>::value, "Failed");
    static_assert(!fit::is_callable<fn, CT&, int>::value, "Failed");

};

FIT_STATIC_TEST_CASE()
{
    typedef int(callable_rank<0>::*fn);

    static_assert(!fit::is_callable<fn>::value, "Failed");
};

FIT_STATIC_TEST_CASE()
{
    typedef int(callable_rank<0>::*fn);

    static_assert(fit::is_callable<fn, callable_rank<0>&>::value, "Failed");
    static_assert(fit::is_callable<fn, callable_rank<0>&&>::value, "Failed");
    static_assert(fit::is_callable<fn, const callable_rank<0>&>::value, "Failed");
    static_assert(fit::is_callable<fn, callable_rank<1>&>::value, "Failed");
};

FIT_STATIC_TEST_CASE()
{
    typedef int(callable_rank<0>::*fn);

    typedef callable_rank<0>* T;
    typedef callable_rank<1>* DT;
    typedef const callable_rank<0>* CT;
    typedef std::unique_ptr<callable_rank<0>> ST;

    static_assert(fit::is_callable<fn, T&>::value, "Failed");
    static_assert(fit::is_callable<fn, DT&>::value, "Failed");
    static_assert(fit::is_callable<fn, const T&>::value, "Failed");
    static_assert(fit::is_callable<fn, T&&>::value, "Failed");
    static_assert(fit::is_callable<fn, ST>::value, "Failed");
    static_assert(fit::is_callable<fn, CT&>::value, "Failed");

};

FIT_STATIC_TEST_CASE()
{
    typedef void(*fp)(callable_rank<0>&, int);

    static_assert(fit::is_callable<fp, callable_rank<0>&, int>::value, "Failed");
    static_assert(fit::is_callable<fp, callable_rank<1>&, int>::value, "Failed");
    static_assert(!fit::is_callable<fp, const callable_rank<0>&, int>::value, "Failed");
    static_assert(!fit::is_callable<fp>::value, "Failed");
    static_assert(!fit::is_callable<fp, callable_rank<0>&>::value, "Failed");
};

FIT_STATIC_TEST_CASE()
{
    typedef void(&fp)(callable_rank<0>&, int);

    static_assert(fit::is_callable<fp, callable_rank<0>&, int>::value, "Failed");
    static_assert(fit::is_callable<fp, callable_rank<1>&, int>::value, "Failed");
    static_assert(!fit::is_callable<fp, const callable_rank<0>&, int>::value, "Failed");
    static_assert(!fit::is_callable<fp>::value, "Failed");
    static_assert(!fit::is_callable<fp, callable_rank<0>&>::value, "Failed");
};
