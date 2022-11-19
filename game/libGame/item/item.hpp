#ifndef ITEM
#define ITEM

#include <string>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Item {
  static vector<Item*> all_items_;
protected:
  string name_;
  Item(string s);
public:
  virtual ~Item(){
    cout << "Deleting [ITEM]: "<< this->name_ <<"...\n";
  }
  string getName() {
    return this->name_;
  };
  virtual string getClass() = 0;
  virtual string describe() = 0;
  static int getNumberOfItems(){ return all_items_.size(); };
  static vector<Item*> getItems(){ return all_items_; }

};


#endif
