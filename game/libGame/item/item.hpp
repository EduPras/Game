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
  virtual string getClass() = 0;
  virtual string describe() = 0;
  static int getNumberOfItems(){ return no_items; }
};


#endif
