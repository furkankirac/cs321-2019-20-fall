#include <iostream>

struct Lambda
{
    int& k;
    Lambda(int& k) : k{k} { }
    auto operator() ()
    {
        std::cout << k << std::endl;
        ++k;
    };
};

int main(int argc, char* argv[])
{
    auto k = 10;
    auto lambda = [&k]() mutable
    {
        std::cout << k << std::endl;
        ++k;
    };

//    auto lambda = Lambda{k};

    lambda();
    lambda();
    lambda();
    lambda();

    k = 20;

    lambda();
    lambda();
    lambda();
    lambda();

    std::cout << k << std::endl;

    return 0;
}
