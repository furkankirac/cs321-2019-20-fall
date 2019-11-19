#include <iostream>

// function objects, lambda functions
// containers and iterator protocol/interface
// std::accumulate

template<typename T>
inline void swap_by_ptr(T* first, T* second)
{
    auto temp = *first;
    *first = *second;
    *second = temp;
}

template<typename T>
inline void swap_by_ref(T& first, T& second)
{
    auto temp = first;
    first = second;
    second = temp;
}


int func1(double a) { return (int)a; }
int func2(double a) { return (int)(a*2.5); }

//typedef int (*foo_ptr)(int);
using foo_ptr = int (*)(double);

int main(int argc, char* argv[])
{
//    auto ptr = foo_ptr{};
    foo_ptr ptr;

    ptr = &func1;
    ptr(5.0); // calls func1(5.0)
    ptr(3.0); // calls func1(3.0)
    ptr = &func2;
    ptr(5.0); // calls func2(5.0)

    auto i = 10, j = 20;

    swap_by_ptr<int>(&i, &j);

    std::cout << i << std::endl;
    std::cout << j << std::endl;

    swap_by_ref<int>(i, j);

    std::cout << i << std::endl;
    std::cout << j << std::endl;

    auto k = 3.14, m = 2.7;
    swap_by_ref<double>(k, m);

    return 0;
}
