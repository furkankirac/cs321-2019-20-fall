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

template<typename T>
struct Vector
{
    size_t size;
    T* values;

    // default c-tor
    Vector() : size(0), values(nullptr) { }

    // c-tor #1
    Vector(size_t size) : size(size), values(new T[size])
    {
        for(int i=0; i<size; ++i)
            values[i] = T();
    }

    // d-tor
    ~Vector() { delete[] values; }

    // copy c-tor
    Vector(const Vector<T>& other) : size(other.size), values(new T[size])
    {
        for(int i=0; i<size; ++i)
            values[i] = other.values[i];
    }

    // move c-tor
    Vector(Vector<T>&& other) : size(other.size), values(other.values)
    {
        other.values = nullptr;
    }


    // copy assignment
    Vector<T>& operator=(const Vector<T>& other)
    {
        size = other.size;
        delete[] values;
        values = new T[size];
        for(int i=0; i<size; ++i)
            values[i] = other.values[i];
        return *this;
    }

    // move assignment
    Vector<T>& operator=(Vector<T>&& other)
    {
        size = other.size;
        delete[] values;
        values = other.values;
        other.values = nullptr;
        return *this;
    }

    T& at(size_t index) { return values[index]; }

    // below we separated operator[] for read and write
    // although this operator is symmetric in its behavior during read and write
    // that is not always the case. Consider accessing a node of a linked list like this
    // reading a node's value is very simple function, but writing to a node can be complex
    // they are in fact two different functions. in the example below difference is not reflected
    // but dividing them into two different functions is indeed necessary

    // subscript operator that writes to values
    T& operator[](size_t index) { return values[index]; }

    // subscript operator that promises read-only access
    T& operator[](size_t index) const { return values[index]; }
};

Vector<int> doSomething()
{
    auto v = Vector<int>(1000);
    // ...
    return v;
}


int main(int argc, char* argv[])
{
    // k is being copy constructed from return value of doSomething()
    // hint: there is a mechanism called copy elison that partially solves this costly behavior but...
    auto k = doSomething(); // copy c-tor from returned value of doSomething()
    k = doSomething(); // copy assignment from returned value of doSomething()

    auto v1 = Vector<int>(10);

    v1.at(0) = 1000;
    v1[1] = 2000;

    auto v2 = Vector<int>();
    auto v3 = Vector<int>();

    v2 = v1; // copy assignment: why? v2 already exists, has been constructed. we assign on top of it

    v3 = v2 = v1; // chained copy assignment
//    v3.operator(v2.operator=(v1));

    auto v4 = Vector<int>(v1); // copy c-tor: why? v4 is being constructed right now from v1

//    auto v5 = (Vector&&)v4;
    auto v5 = std::move(v4); // move c-tor: why? v5 is being constructed right now stealing from v4

    std::cout << v1.at(1) << std::endl;

    return 0;
}
