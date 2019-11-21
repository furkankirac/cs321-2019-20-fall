#include <iostream>
#include <vector>

struct Fibonacci
{
    int v1 = 0;
    int v2 = 1;
    auto operator() () {
        auto v = v1+v2;
        v1 = v2;
        v2 = v;
        return v;
    }
};

int main(int argc, char* argv[])
{
    auto fo = Fibonacci{};
//    auto fo = [v1=0, v2=1]() mutable {
//        auto v = v1+v2;
//        v1 = v2;
//        v2 = v;
//        return v;
//    };

        std::cout << fo() << std::endl;

    return 0;
}
