#include <iostream>
#include <vector>

#include <range/v3/all.hpp>

using namespace ranges;

// to_string
// multiply_by
// vector<double>, vector<char>
// accumulate(view, init)
// action::sort
// action::unique
// [a, b] = views::cartesian_product
// inner_product, views::generate

template<typename LEFT, typename RIGHT>
auto operator |(const LEFT& left, const RIGHT& right)
{
    return right(left);
}

//auto to_string()
//{
//    return [](const auto& value) {
//        return std::to_string(value);
//    };
//}

auto to_string = [] { return [](const auto& value) { return std::to_string(value); }; };

//template<typename T>
//auto multiply_by(T what)
//{
//    return [=](auto value) {
//        return value * what;
//    };
//}

auto multiply_by = [](auto what) { return [=](auto value) { return value * what; }; };

int main(int argc, char* argv[])
{
//    auto s = to_string()(5.3);

    auto s = 5.3 | to_string();
    std::cout << s << std::endl;

    auto m = multiply_by(100);
    auto result = 2.5 | m;
    std::cout << result << std::endl;

    return 0;
}
