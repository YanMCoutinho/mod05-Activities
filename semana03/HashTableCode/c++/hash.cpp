#include "hash.h"

Hash::Hash(int max_items) {
  this->max_items = max_items;
  this->length = 0;
  this->table = new Item[max_items];
}

Hash::~Hash() { delete[] table; }

bool Hash::IsFull() const { return (this->length == this->max_items); }

int Hash::getLength() const { return this->length; }

string Hash::retrieveItem(Item &item, bool &found) {

  for (int i = 0; i < this->max_items; i++) {
    int newKey = (item.getId() + i) > (this->max_items - 1)
                     ? (item.getId() + i - this->max_items)
                     : (item.getId() + i);
    Item newItem(newKey);
    int location = this->getHash(newItem);
    Item searchedItem = table[location];
    if (searchedItem.getId() == item.getId()) {
      found = true;
      return searchedItem.getProduct();
    }
  }

  found = false;
  return "";
}

void Hash::insertItem(Item item) {
  for (int i = 0; i < this->max_items; i++) {
    int newKey = (item.getId() + i) > (this->max_items - 1)
                     ? (item.getId() + i - this->max_items)
                     : (item.getId() + i);
    Item newItem(newKey);
    int location = this->getHash(newItem);
    Item searchedItem = table[location];

    if (searchedItem.getId() == Item::NULL_VALUE) {
      table[location] = item;
      this->length++;
      return;
    }
  }
}

void Hash::deleteItem(Item item) {
  for (int i = 0; i < this->max_items; i++) {
    int newKey = (item.getId() + i) > (this->max_items - 1)
                     ? (item.getId() + i - this->max_items)
                     : (item.getId() + i);
    Item newItem(newKey);
    int location = this->getHash(newItem);
    Item searchedItem = table[location];
    
    if (searchedItem.getId() == item.getId()) {
      Item nullItem(-2);
      table[location] = nullItem;
      this->length--;
      return;
    }
  }
}

void Hash::print() {
  for (int i = 0; i < this->max_items; i++) {
    cout << "location: " << i << " key: " << this->table[i].getId()
         << " value: " << this->table[i].getProduct() << endl;
  }
}

int Hash::getHash(Item item) { return (item.getId() % this->max_items); }