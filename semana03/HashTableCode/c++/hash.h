#include <iostream>
#include <string>
#include "item.h"
using namespace std;

class Hash {
  public:
    Hash(int max_items = 101);
    ~Hash();
    bool IsFull() const;
    int getLength() const;

    string retrieveItem(Item& item, bool& found);
    void insertItem(Item item);
    void deleteItem(Item item);
    void print();

  private:
    int getHash(Item item);
    int max_items;
    int length;
    Item* table;
};