#include <iostream>

// pure functions != free functions
// pure functions are better. eliminate state if possible.

// compile-time pure functions are represented by template meta programming in C++
// and also "constexpr" keyword. But let's skip constexpr for now.
// struct Divide<u, v>; // explicit specialization for v=0
// struct Sum<first, second>;

// variadic templates
// struct Sum<first, second, ...>; ???
// 1) recursive version
// 2) fold expressions

// template<...> printAll

template<int a, int b> struct Divide        { static const int value = a / b; };
template<int k>        struct Divide<k, 0>  { static const int value = 0; };

template<int a, int b> struct Sum           { static const int value = a + b; };

template<int first, int ... rest>
struct SumAll
{
    static const int value = first + SumAll<rest...>::value;
};

template<int first>
struct SumAll<first>
{
    static const int value = first;
};

// make this SumAll work as your homework.

int main(int argc, char* argv[])
{
    std::cout << Divide<10, 2>::value << std::endl;
    std::cout << Divide<10, 0>::value << std::endl;
    std::cout << Sum<10, 20>::value << std::endl;
    std::cout << Sum<Sum<10, 20>::value, 30>::value << std::endl;
    std::cout << SumAll<10, 20, 30, 40, 50>::value << std::endl;

    return 0;
}
