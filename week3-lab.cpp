#include <iostream>

struct House
{
    double area;
    double price;
    double price_per_msqr;


    bool operator<(const House house) const { return price_per_msqr<house.price_per_msqr; }
    bool operator>(const House house) const { return price_per_msqr>house.price_per_msqr; }
    bool operator==(const House house) { return price_per_msqr == house.price_per_msqr; }

    House(const double area, const double price) : area(area), price(price)
    {
        price_per_msqr = price/area;
    }


    void print() const{

        std::cout<< "price: " << price << "\narea "<< area <<"\nprice per msqr: " << price_per_msqr << std::endl;
    }

};

int main(int argc, char* argv[])
{

    House h1{10,100};
    House h2{10,10};
    h1.print();
    h2.print();

    if (h1==h2)
        std::cout << "Same houses!" << std::endl;
    else if(h1>h2)
        std::cout << "h1 is more expensive than h2" << std::endl;
    else
        std::cout << "h2 is more expensive than h1" << std::endl;


    return 0;
}
