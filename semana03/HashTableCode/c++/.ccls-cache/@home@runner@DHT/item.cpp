#include "item.h"

const int Item::NULL_VALUE = -2;

Item::Item() {
  this->id = this->NULL_VALUE;
  this->product = "";
}

Item::Item(int id) {
  this->id = id;
  this->product = "";
}

Item::Item(int id, string product) {
  this->id = id;
  this->product = product;
}

int Item::getId() const {
  return this->id;
}

string Item::getProduct() const {
  return this->product;
}