#include <iostream>
#include <vector>

// OOP:
// ctor/dtor
// copy-ctor, copy-assignment
// move-ctor, move-assignment
// inheritance

// user-defined literals

// almost always auto - aaa rule: move type to the right
// unified/universal initialization

struct Vector
{
    int size;
    int* values;

    Vector() : size(0), values(nullptr) { }
    Vector(size_t size) : size(size), values(new int[size])
    {
        for(int i=0; i<size; ++i)
            values[i] = 0;
    }
    ~Vector() { delete[] values; }

    int& at(size_t index) { return values[index]; }

    // below we separated operator[] for read and write
    // although this operator is symmetric in its behavior during read and write
    // that is not always the case. Consider accessing a node of a linked list like this
    // reading a node's value is very simple function, but writing to a node can be complex
    // they are in fact two different functions. in the example below difference is not reflected
    // but dividing them into two different functions is indeed necessary

    // subscript operator that writes to values
    int& operator[](size_t index) { return values[index]; }

    // subscript operator that promises read-only access
    int& operator[](size_t index) const { return values[index]; }
};

int main(int argc, char* argv[])
{
    std::vector<int> V1(10);
    for(int i=0; i<10; ++i)
        V1[i] = i;

    std::vector<int> V2;
    V2 = V1;

    auto v1 = Vector(10);
    v1.at(0) = 1000;
    v1[1] = 2000;

    auto v2 = Vector();
    v2 = v1; // this causes (may cause) a run-time error later. same memory block will be freed twice

    std::cout << v1.at(1) << std::endl;

    return 0;
}
