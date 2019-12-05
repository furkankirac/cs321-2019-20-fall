// Higher order functions, lifting a function:
// call_twice
// greater_than -> count_if(begin, end, greater_than(5))
// compose functions

#include <iostream>
#include <vector>

template<typename FUNC>
void call_twice(FUNC func)
{
    func();
    func();
}

template<typename CONTAINER, typename LAMBDA>
inline size_t count_if(const CONTAINER& container, LAMBDA lambda)
{
    auto sum = size_t{};
    for(const auto& value : container)
        if(lambda(value))
            ++sum;
    return sum;
}

inline auto greater_than(int value)
{
    return [value](int k) { return k > value; };
//    struct Lambda
//    {
//        int value;
//        Lambda(int value) : value{value} { }

//        auto operator() (int k) const { return k > value; }
//    };
//    return Lambda{value};
}

template<typename F, typename G>
auto compose(F f, G g)
{
    return [=]() {
        return f(g());
    };
}

auto func_f = [](int k) { return k*2; };
//int func_f(int k) { return k*2; }

auto func_g = []() { return 10; };
//int func_g() { return 10; }

template<typename F, typename G>
auto operator |(F f, G g)
{
    return [=]() {
        return f(g());
    };
}

int main(int argc, char* argv[])
{
    auto composed = func_f | func_g;
//    auto composed = compose(func_f, func_g);
    auto z = composed();
    std::cout << z << std::endl;

    auto v = std::vector<int>{10, 20, 100, 1000};

// range-for does smt. below
//    for(auto it=v.begin(); it!=v.end(); ++it)
//    {
//        auto a = *it;
//    }

//    auto sum = 0;
//    for(int a : v)
//    {
//        if(a > 50)
//            ++sum;
//    }

//    auto sum = count_if(v, [](int value) { return value > 50; });
    auto sum = count_if(v, greater_than(50));

//    auto sum = std::count_if(v.begin(), v.end(), [](int value) { return value > 50; });

    std::cout << sum << std::endl;

    return 0;
}
