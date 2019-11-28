// functional programming: type constructor:
// templates in C++, std::vector, std::list, ...

// std::initializer_list, braces in detail { }, ranges, iterators, range-for
// uniform initialization, struct Point, int i{2.0}

// std::map

// && for r-value binding
// move constructor, move assignment

#include <iostream>
#include <vector>

struct Point
{
    int x;
    int y;
    int z;
    Point(int x) : x{x}, y{}, z{}           { std::cout << "int c-tor has been called\n"; }
    Point(int x, int y) : x{x}, y{y}, z{}   { std::cout << "int, int c-tor has been called\n";}

    Point(std::initializer_list<int> il)
    {
        if(il.size() == 1)
            x = *il.begin();
        else if(il.size() == 2)
        {
            auto ptr = il.begin();
            x = *ptr++;
            y = *ptr++;
        }
        else if(il.size() >= 3)
        {
            auto ptr = il.begin();
            x = *ptr++;
            y = *ptr++;
            z = *ptr++;
        }
        std::cout << "init-list based c-tor has been called.\n";
    }

    void incrementX() { ++x; }
    Point incrementedX() const { return Point(x+1, y); }
};

int main(int argc, char* argv[])
{
    auto p1 = Point{10, 20};
//    p1.incrementX();
    auto p2 = p1.incrementedX();
    auto p3 = Point(100);
    auto p4 = Point{1, 2, 3, 4, 5, 6, 7, 8};

    auto v1 = std::vector<int>{10, 20}; // container has 2 elements: 10 and 20
//    auto v1 = std::vector<int>(2);
//    v1[0] = 10;
//    v1[1] = 20;

    auto v2 = std::vector<int>(10, 20); // container has 10 elements all initialized to 20

    return 0;
}
