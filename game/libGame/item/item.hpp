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
  Item(string s): name_(s) {
    vector<Item*>::iterator it;
    stringstream ss;
    if(all_items_.empty()) {
      all_items_.push_back(this);
    }
    else{
      for(it = all_items_.begin(); it != all_items_.end(); it++){
        if((*it)->name_ == s){
          cout << (*it)->name_ << " -> " << s << endl;
          ss << "Unable to create item: \"" << s << "\"(Its name already exists)\n";
          throw ss.str();
          break;
        }
      }
      cout << "Creating Item...\n";
      all_items_.push_back(this);
    }
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
  static int getNumberOfItems(){ return all_items_.size(); };
  static vector<Item*> getItems(){ return all_items_; }
};


#endif
