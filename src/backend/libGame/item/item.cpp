#include "./item.hpp"
/*
Item::Item(string s): name_(s) {
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
};*/
