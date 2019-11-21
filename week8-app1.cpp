#include <iostream>
#include <vector>

// function objects, lambda functions
// containers and iterator protocol/interface
// std::accumulate

struct FunctionObject
{
    float multiplier = 10.0f;
    float threshold = 15.0f;


    auto operator() (float a, float b) const
    {
        auto k = multiplier*(a + b);
        return k > threshold ? k : 0.0f;
//        if(k > threshold)
//            return k;
//        return 0.0f;
    }
};


template<typename Container, typename T, typename FUNC>
auto accumulate(const Container& v, T init, FUNC func)
{
    for(auto it = v.begin(); it != v.end(); ++it)
        init = func(init, *it);

    return init;
}

int main(int argc, char* argv[])
{
    auto v = std::vector<float>{1.1f, 2.2f, 3.3f};
//    auto fo = FunctionObject{};
//    auto result = accumulate(v, 0.0f, fo);

    auto multiplier = 25.5f;
    auto threshold = 15.0f;

    auto lambda = [multiplier, threshold](float a, float b) {
        auto k = multiplier*(a + b);
        return k > threshold ? k : 0.0f;
    };
    auto result = accumulate(v, 0.0f, lambda);

//    auto init = 0;
//    for(auto it = v.begin(); it != v.end(); ++it)
//        init = init + *it;

    std::cout << result << std::endl;

    return 0;
}
