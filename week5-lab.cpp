#include <iostream>
#include <vector>
#include <map>


// We may not ask for sell item for the moment.


enum class item_archetypes { drink, fruit, snack, tech, apparel };

struct Item
{
    item_archetypes itemtype;
    std::string item_name;
    double price;
    int id;
};

struct Bank{

    double balance=0;
    std::vector<double> transaction_hist;

    void updateBalance(const double price){
        transaction_hist.push_back(price);
        balance += price;
    }

};

class Store
{
  private:
    std::map<item_archetypes, std::vector<Item>> item_list;
    Bank bank;

  public:
    void printStore(){

        // Print archetype --> item names
        // Bank information --> balance & transaction

    }

    void sellItem(Item item){

        for( auto store_item : item_list[item.itemtype])
        {
            if(item.id == store_item.id){
                bank.updateBalance(item.price);
            }else
                std::cout << "item not found!" << std::endl;
        }

    }

    void buyItem(const Item item){

        item_list[item.itemtype].push_back(item);
        bank.updateBalance(item.price);
    }

    Store(Bank bank): bank{bank}    {}

};

int main()
{
    Item I{item_archetypes::drink, "coke", 5, 0};
    return 0;
}
