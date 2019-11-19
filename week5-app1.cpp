#include <iostream>
#include <vector>
#include <map>

// Archetype containers std::vector and std::map
// std::vector  : push_back, init list, n elements with value v, element access, iterating over a vector
// std::map     : key-value pairs. insert key, value pairs: map_name.insert({key, element}) --> accepts pairs!


template <typename T>
void printVec(const T& vec){
    std::cout<< "[ ";
    for (const auto& x : vec)
        std::cout << x << " ";
    std::cout<< "]\n";
}

template <typename T>
void printMap(T map){
    for( auto const& [key, val] : map )
    {
        std::cout << key         // string (key)
                  << ':'
                  << val        // string's value
                  << std::endl ;
    }
}

int main(int argc, char* argv[])
{
    std::vector<std::string> v1;
    v1.push_back("string1");
    v1.push_back("string2");
    printVec(v1);

    std::vector<int> v2{1,3,4,5,1,2,5};
    printVec(v2);

    std::vector<float> v3(3, 3.33f);
    printVec(v3);


    std::map<std::string,int> m1;
    m1.insert({"size",5});
    m1.insert({"volume",7});
    printMap(m1);
    m1.insert({"size",7}); // Can not insert, does not raise Error
    std::cout<< "size:" <<m1["size"] << std::endl;
    m1["size"] = 7;
    std::cout<<"size:" <<m1["size"] << std::endl;

    return 0;
}
