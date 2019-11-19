#include <iostream>
#include <vector>

// function objects, lambda functions
// containers and iterator protocol/interface
// std::accumulate

struct Foo
{
    void operator+(const int a) const { }
    int operator() (double d) const { return d+1.0; }
};

struct Bar
{
    int operator() (double d) const { return d/2.0; }
};


template<typename FUNC>
auto algo(double value, FUNC func)
{
//    return func.operator()(value);
    return func(value);
}


template<typename FUNC>
auto go_over(const std::vector<int>& v, FUNC func, int init = 0)
{
    for(auto it = v.begin(); it != v.end(); ++it)
        init = func(init, *it);

    return init;
}

int main(int argc, char* argv[])
{
    auto foo = Foo{};

    foo + 5;
//    foo.operator+(5);

    auto result = foo(10.0);
//    auto result = foo.operator()(10.0);

    auto bar = Bar{};
    auto b = bar(10);

    std::cout << algo(10.0, Bar{}) << std::endl;

    auto l = [](double d) {
        return d+10.0;
    };
    auto result2 = algo(100.0, l);
    auto result3 = algo(100.0, [](double d) {
        return d+10.0;
    });
    std::cout << result2 << std::endl;
    std::cout << result3 << std::endl;

    auto v = std::vector<int>{1, 2, 3};
    auto result4 = go_over(v, [](int a, int b) { return a + b; });

//    auto init = 0;
//    for(auto it = v.begin(); it != v.end(); ++it)
//        init = init + *it;

    std::cout << result4 << std::endl;

    return 0;
}
