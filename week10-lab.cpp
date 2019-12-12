#include <iostream>
#include <vector>

// 1a) write a higher order function called "filter" that filters the contents of
// any container with push_back method via consulting a lambda.
// lambda is used to ask about the container item's eligibility.
// if the item is eligible, it stays, otherwise it is ignored.
// a lambda returning either true or false is called a "predicate"
// at the end, a new container of the same type with eligible items are returned.

// 1b) use your "filter" function on a std::vector<std::string> instance to
// filter the strings with a length of at least 4 chars.
// 1c) use a lifted function "with_min_length(4)" to do the same thing.

// 2a) write a higher order function called "for_each" that iterates over all items in
// the container and passes them to a lambda.
// 2b) use for_each with a lambda that prints the item to std::cout.
// 2c) print the original container v and filtered container returned in (1a) question

// 3a) write a higher order function called "transform" that iterates over all items and
// changes them to something else via a lambda. lambda does not return anything.
// lambda must change the item directly in-place.
// 3b) use this function to transform all strings stored in the container to <oldvalue>
// container will be "<live>", "<long>", "<and>", "<prosper>" after transform is called.
// 3c) print transformed container using for_each.

template<typename CONTAINER, typename LAMBDA>
inline auto filter(const CONTAINER& container, LAMBDA lambda)
{
    auto C = CONTAINER{};
    for(const auto& item : container)
        if(lambda(item))
            C.push_back(item);
    return C;
}

template<typename CONTAINER, typename LAMBDA>
inline void for_each(const CONTAINER& container, LAMBDA lambda)
{
    for(const auto& item : container)
        lambda(item);
}

template<typename CONTAINER, typename LAMBDA>
inline void transform(CONTAINER& container, LAMBDA lambda)
{
    for(auto& item : container)
        lambda(item);
}

auto with_min_length(size_t min_len)
{
    return [=](const std::string& s) {
        return s.length() >= min_len;
    };
}

int main(int argc, char* argv[])
{
    auto v1 = std::vector<std::string>{"Live", "long", "and", "prosper"};
    auto v2 = filter(v1, [](const std::string& s) { return s.length() >= 4; });
    auto v3 = filter(v1, with_min_length(4));

    auto printer = [](const std::string& s) { std::cout << s << std::endl; };
    for_each(v1, printer);
    std::cout << std::endl;
    for_each(v2, printer);
    std::cout << std::endl;
    for_each(v3, printer);
    std::cout << std::endl;

    transform(v1, [](std::string& s) {
        s =  "<" + s + ">";
    });
    for_each(v1, printer);
}
