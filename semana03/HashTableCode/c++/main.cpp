#include <iostream>
#include "hash.h"

void testCase01(Hash& hashTable2) {
  //Add two items to create a collision
  cout << "test case 01" << endl;
  Item newItem = Item(7, "Caneta Bic"); //7 % 7 = 0
  Item newItem2 = Item(14, "Caixa 16x4 caneta bic"); // 14 % 7 = 0
  hashTable2.insertItem(newItem);
  hashTable2.insertItem(newItem2);
  hashTable2.print();
  cout << endl;
}

void testCase02() {
  //Remove a Item that suffered a collision
  Hash hashTable(7);
  testCase01(hashTable);
  hashTable.deleteItem(Item(14));
  cout << "test case 02" << endl;
  hashTable.print();
  cout << endl;  
}

void testCase03() {
  //Find a item that suffered a collision
  Hash hashTable(7);
  testCase01(hashTable);
  bool found = false;
  Item newItem(14);
  cout << "test case 03" << endl;
  cout << "Product name: " << hashTable.retrieveItem(newItem, found) << endl;
  cout << endl;
}

void testCase04() {
  //Insert a item that will collide with the previous item with id -2
  cout << "test case 04" << endl;
  Hash hashTable(7);
  Item newItem(-2, "Caneta Bic");
  hashTable.insertItem(newItem);
  hashTable.insertItem(Item(14, "Bazuca"));
  hashTable.print();
  cout << "" << endl;  
}

void testCase05() {
  //Insert a item with null id that will collide with the next one
  cout << "test case 05" << endl;
  Hash hashTable(10);
  Item newItem(-2, "Caneta Bic");
  hashTable.insertItem(Item(2, "Bazuca"));
  hashTable.insertItem(newItem);
  hashTable.print();
  cout << endl;  
}

int main() {
  Hash hashTable2(7);
  //testCase01(hashTable2);
  //testCase02();
  //testCase03();
  //testCase04();
  testCase05();
}