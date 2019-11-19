#include <iostream>
#include <string>
#include <vector>

enum Color { Red, Yellow, Orange, Blue };
enum Shape { Round, Curved };

struct Fruit
{
    std::string name;
    Color color;
    Shape shape;

    Fruit(const std::string& name, Color color, Shape shape)
        : name{name}, color{color}, shape{shape}
    { }

    Fruit(const Fruit& other)
        : name{name}, color{color}, shape{shape}
    { }

};

struct Toy
{
    std::string name;
    float price;

    Toy(const std::string& name, float price)
        : name{name}, price{price}
    { }
};

template<typename T>
struct Basket
{
    std::vector<T> items;

    void add(const T& item) { items.push_back(item); }

    const T& operator[](size_t index) const { return items[index]; }
    T& operator[](size_t index) { return items[index]; }
};

template<typename T>
void print_name(const T& item)
{
    std::cout << item.name << std::endl;
}

auto operator+(const Fruit& f, const Toy& t)
{
    return Fruit{f.name+t.name, f.color, f.shape};
}

int main(int argc, char* argv[])
{
    auto fruits = Basket<Fruit>{};
    fruits.add(Fruit{"Apple", Color::Red, Shape::Round});
    fruits.add(Fruit{"Banana", Color::Yellow, Shape::Curved});
    fruits.add(Fruit{"Blueberry", Color::Blue, Shape::Round});

    auto toys = Basket<Toy>{};
    toys.add(Toy{"Lego", 100.0});
    toys.add(Toy{"Barbie", 50.0});

    fruits[0] = Fruit{"Orange", Color::Orange, Shape::Round};

    print_name(fruits[0]);
    print_name(fruits[0]+toys[0]);

    return 0;
}
