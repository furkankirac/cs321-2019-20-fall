#include <iostream>

template<typename T>
struct Node
{
    Node<T>* next;
    T value;

    Node(const T& value) : next{nullptr}, value{value} { }
};

template<typename T>
struct List
{
    Node<T>* head;

    List() : head{} { }
    List(const List<T>& other) : head{new Node<T>(other.head->value)}
    {
        auto* node_ptr = other.head->next;
        while(node_ptr)
        {
            push_back(node_ptr->value);
            node_ptr = node_ptr->next;
        }
    }

    // returns a pointer to the last node of the list
    Node<T>* get_tail()
    {
        auto* node_ptr = head;
        while(node_ptr && node_ptr->next)
            node_ptr = node_ptr->next;
        return node_ptr;
    }

    // insert a node allocated from the heap, storing "value",
    // to the beginning of the list
    void push_front(const T& value)
    {
        auto* new_node = new Node<T>(value);
        new_node->next = head;
        head = new_node;
    }

    // insert a node allocated from the heap, storing "value",
    // to the end of the list
    void push_back(const T& value)
    {
        auto* new_node = new Node<T>(value);
        auto* tail = get_tail();
        if(tail)
            tail->next = new_node;
        else
            head = new_node;
    }
};

template<typename KeyType, typename ValueType>
struct Pair
{
    KeyType key;
    ValueType value;
};

int main(int argc, char* argv[])
{
    auto ints = List<int>{};
    ints.push_back(10);
    ints.push_back(20);
    for(auto* ptr=ints.head; ptr != nullptr; ptr=ptr->next)
        std::cout << ptr->value << std::endl;

    auto math_values = List<Pair<double, const char*>>{};
    math_values.push_back({3.14159, "Pi"});
    math_values.push_back({2.71828, "Euler Number"});
    math_values.push_back({2.61803, "Phi (GoldenRatio)"});
    for(auto* ptr=math_values.head; ptr != nullptr; ptr=ptr->next)
        std::cout << ptr->value.key << ", " << ptr->value.value << std::endl;

//    10
//    20
//    3.14159, Pi
//    2.71828, Euler Number
//    2.61803, Phi (GoldenRatio)

    return 0;
}
