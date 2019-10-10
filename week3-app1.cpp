#include <iostream>

// function / operator overloading
// const, east/west const, const correctness

// OOP:
// ctor/dtor
// copy-ctor, copy-assignment
// move-ctor, move-assignment
// inheritance

// user-defined literals

// almost always auto - aaa rule: move type to the right
// unified/universal initialization

double get_pi()                 { return 3.14152; }
double get_pi(const int precision)
{
    if(precision == 1)
        return 3.1;
    if(precision == 2)
        return 3.14;
    return 3.14152;
}

struct Float
{
    float value;
    //...
};

class Int
{
    int value; // this attrib. is private, it's none of the outside caller's business to touch it

public:
    Int(int value) : value(value) { }

    // auto return type below is available in C++14 onwards
    auto operator+(const Int other) { return Int(value + other.value); }

    int get_value() const // touch the internals through here
    {
        return this->value;
    }

//    Int operator+(Float other) { /*...*/ }
};

//Int add(Int v1, Int v2) { return Int(v1.value + v2.value); }
//Int operator+(Int v1, Int v2) { return Int(v1.value + v2.value); }


int main(int argc, char* argv[])
{
    const auto p = 3.14;

    auto pi = get_pi();
    auto pi_1 = get_pi(1);

    auto a = Int(10);
    auto b = Int(20);
//    auto c = add(a, b);
    auto c = a + b;
//    auto c = a.operator+(b);

    // we need free function version of op-overloading
    // because left object and even right thing do not belong to us
    // we can't change their internals
//    "Hello" + std::string("World");


    std::cout << c.get_value() << std::endl;

    return 0;
}
