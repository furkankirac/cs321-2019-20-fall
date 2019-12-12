#include <iostream>
#include <vector>

// parameter packs, pack expansions, fold expressions
// higher order functions: none_of, all_of, any_of, if_then

struct DivisibleBy
{
    int by_what;
    DivisibleBy(int by_what) : by_what{by_what} { }
    bool operator() (int x) const { return x % by_what == 0; }
};

auto divisible_by = [](int by_what) {
    return DivisibleBy{by_what};
//    return [by_what](int x) { return x % by_what == 0; };
};

auto less_than = [](int from_what) {
    return [from_what](int x) { return x < from_what; };
};

template<typename ... Predicates>
inline bool all_of(int x, Predicates ... ps)
{
    return (ps(x) && ...); // fold expression (C++17)
}

template<typename ... Predicates>
inline bool any_of(int x, Predicates ... ps)
{
    return (ps(x) || ...); // fold expression (C++17)
}

template<typename ... Predicates>
inline bool none_of(int x, Predicates ... ps)
{
    return (!ps(x) && ...); // fold expression (C++17)
}

template<typename ... Predicates>
inline auto one_of(Predicates ... ps)
{
    return [=](int x) {
        return (ps(x) + ...) == 1; // fold expression (C++17)
    };
}

template<typename Predicate, typename Action>
auto if_then(Predicate p, Action a)
{
    return [=](int x) {
        if(p(x))
            a();
    };
}

int main(int argc, char* argv[])
{
//    struct DivisibleBy7
//    {
//        bool operator() (int x) const { return x % 7 == 0; }
//    };

    auto divisible_by_7 = [](int x) { return x % 7 == 0; };
//    auto divisible_by_7 = DivisibleBy7{};

    auto is_odd = [](int x) { return x % 2 != 0; };
    auto less_than_20 = [](int x) { return x < 20; };

    auto r1 = all_of(14, divisible_by_7, is_odd);
    std::cout << (r1 ? "true" : "false") << std::endl;

    auto r2 = all_of(21, divisible_by_7, is_odd);
    std::cout << (r2 ? "true" : "false") << std::endl;

    auto r3 = all_of(7, divisible_by_7, is_odd, less_than_20);
    std::cout << (r3 ? "true" : "false") << std::endl;

    auto r4 = all_of(7, divisible_by(7), is_odd, less_than(20));
    std::cout << (r4 ? "true" : "false") << std::endl;

    auto r5 = one_of(divisible_by(7), is_odd, less_than(20))(14);
    std::cout << (r5 ? "true" : "false") << std::endl;

    return 0;
}
