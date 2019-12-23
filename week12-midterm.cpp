#include <iostream>
#include <vector>

inline auto less_than(double threshold)
{
    return [=](double value) {
        return value < threshold;
    };
}

inline auto greater_than(double threshold)
{
    return [=](double value) {
        return value > threshold;
    };
}

inline auto multiply_by(double coef)
{
    return [=](double value) {
        return value * coef;
    };
}


template<typename Predicate, typename Action>
inline auto if_then(Predicate p, Action a)
{
    return [=](double& value) {
        if(p(value))
            value = a(value);
    };
}

template<typename ... Preds>
inline auto all_of(Preds ... preds)
{
    return [=](double value) {
        return (preds(value) && ...);
    };
}

template<typename Container, typename Action>
inline void transform(Container& container, Action action)
{
    for(auto& item : container)
        action(item);
}

template<typename Action>
inline auto transform_(Action action)
{
    return [=](auto& container) {
        for(auto& item : container)
            action(item);
    };
}

template<typename Container, typename Predicate>
inline auto filter(const Container& container, Predicate pred)
{
    auto v = Container{};
    for(const auto& item : container)
        if(pred(item))
            v.push_back(item);

    return v;
}

auto odd_generator = [k=1]() mutable { auto r = k; k += 2; return r; };

int main(int argc, char* argv[])
{
    auto v = std::vector<double>{};
    for(int i=0; i<5; ++i)
        v.push_back(odd_generator() * 2.5);
    // v contains {2.5, 7.5, 12.5, 17.5, 22.5} here

    // not lifted transform function eagerly accepts the container instance v
    // transform(v, if_then(all_of(greater_than(2.0), less_than(15.0)), multiply_by(20)));
    // v contains {50.0, 150.0, 250.0, 17.5, 22.5} here

    // examining what are predicates and what are actions
    auto pred1 = greater_than(2.0);
    auto pred2 = less_than(15.0);
    auto pred3 = all_of(pred1, pred2);
    auto action1 = multiply_by(20);
    auto action2 = if_then(pred3, action1);
    // we apply a lifted version of transform, which doesn't get the container to work on eagerly
    auto transform1 = transform_(action2);
    transform1(v); // it is now called with a container instance to work on
    // equivalently we could do
    // transform_(action2)(v);

    auto v_new = filter(v, greater_than(100));

    for(auto d : v)
        std::cout << d << std::endl;

    std::cout << std::endl;

    for(auto d : v_new)
        std::cout << d << std::endl;

    return 0;
}
