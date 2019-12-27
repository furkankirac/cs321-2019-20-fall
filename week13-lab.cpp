#include <iostream>
#include <vector>

#include <range/v3/all.hpp>

// define new namespace aliases for easy use of ranges library.
namespace rs = ranges;
namespace rv = ranges::view;
namespace ra = ranges::action;

auto to_roman(int value)
{
    auto roman = std::vector<std::pair<int, char const*>>{
        { 1000, "M" },  { 900, "CM" },
        { 500, "D" },   { 400, "CD" },
        { 100, "C" },   { 90, "XC" },
        { 50, "L" },    { 40, "XL" },
        { 10, "X" },    { 9, "IX" },
        { 5, "V" },     { 4, "IV" },
        { 1, "I" }
    };

    auto result = std::to_string(value) + "=";
    for (const auto& [d, r] : roman)
    {
        while (value >= d)
        {
            result += r;
            value -= d;
        }
    }

    return result;
}

int main(int argc, char* argv[])
{
    auto new_line = [] { std::cout << std::endl; };
    auto print = [](const auto& s) { std::cout << s << std::endl; };

    auto v = std::vector<double>{1.5, 2.7, 3.8, 4.2};
    { // sum all the numbers -> 12.2
        auto val = rs::accumulate(v, 0.0);
        print(val);
        new_line();
    }
    { // sum all numbers greater than 3.0 -> 8.0
        auto val = rs::accumulate(v | rv::filter([](double value) { return value > 3.0; }), 0.0);
        print(val);
        new_line();
    }
    { // sum all numbers between 1 and 100 -> 5050
        auto val = rs::accumulate(rv::ints(1, 101), 0.0);
        print(val);
        new_line();
    }
    { // for v={10, 50, 7, 30, 20, 5, 8, 3},
      // when going in the reverse direction, skip first two numbers and then multiply next 3 numbers that are divisible by 10 -> 100
        auto v = std::vector<int>{10, 50, 7, 30, 20, 5, 8, 3};
        auto val = rs::accumulate(
                    v | rv::reverse | rv::drop(2) | rv::filter([](int val) { return val % 10 == 0; }) | rv::take(3)
                    , 0);
        print(val);
        new_line();
    }
    { // for v={10, 50, 7, 30, 20, 5, 8, 3},
      // when going in the reverse direction, skip first two numbers and then multiply next 3 numbers that are divisible by 10 -> 100
        auto v = std::vector<int>{10, 50, 7, 30, 20, 5, 8, 3};
        auto val = rs::accumulate(
                    v | rv::reverse | rv::drop(2) | rv::filter([](int val) { return val % 10 == 0; }) | rv::take(3)
                    , 0);
        print(val);
        new_line();
    }
    {   // for v={5, 5, 10, 3, 3, 2},
        // multiply each unique number with its order in the sequence
        // after unique v becomes {5, 10, 3, 2};    5*1 + 10*2 + 3*3 + 2*4 = 42
        auto v = std::vector<int>{5, 5, 10, 3, 3, 2};
        auto val = rs::inner_product(v | rv::unique, rv::ints(1), 0);
        print(val);
        new_line();
    }

    // problem #1
    {   // pick any number from v1, and any number from v2, if their multiplication is greater than 100, print both of them
        auto v1 = std::vector<int>{10, 13, 24, 7, 8, 5};
        auto v2 = std::vector<int>{6, 5, 3, 16, 8, 7};
        for(const auto& [a, b]
            : rv::cartesian_product(v1, v2)
            | rv::filter([](auto v) { auto [first, second] = v; return first*second>100; })
            )
            std::cout << a << "*" << b << "=" << (a*b) << std::endl;

        new_line();
    }

    // problem #2: below is old-school code, convert it to ranges version

    // starting from 200 and going down to 101,
    // prints the first 3 numbers that can be divided by 7 as a roman number
    for (int n = 200, count=0; n >= 101 && count < 3; --n)
    {
        if (n % 7 == 0)
        {
            std::cout << to_roman(n) << std::endl;
            ++count;
        }
    }
    new_line();

    // equivalent ranges implementation
    auto is_divisible_by = [](int by_what) { return [=](int value) { return value % by_what == 0; }; };
    for (auto n : rv::ints(101, 201) | rv::reverse | rv::filter(is_divisible_by(7)) | rv::transform(to_roman) | rv::take(3))
        std::cout << n << std::endl;

    return 0;
}
