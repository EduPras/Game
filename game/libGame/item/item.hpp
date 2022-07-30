#ifndef ITEM
#define ITEM

#include <string>
#include <iostream>

using namespace std;

class Item {
  static int no_items;
protected:
  string name_;
  Item(string s): name_(s) {
    no_items++;
  };
public:
  ~Item(){
    cout << "Deleting...\n";
  }
  string getName() {
    return this->name_;
  };
  virtual string getClass() {
    return "Just a regular item...";
  };
  virtual string describe() {
    return "What is this?";
  }
  static int getNumberOfItems(){ return no_items; }
};


#endif
