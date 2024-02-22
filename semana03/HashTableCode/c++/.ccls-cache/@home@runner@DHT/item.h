#include <iostream>
#include <string>
using namespace std;

class Item {
  private:
    int id;
    string product;
  public:
    Item();
    Item(int id);
    Item(int id, string product);
    int getId() const;
    string getProduct() const;
    static const int NULL_VALUE;
};