#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "character.hpp"

using namespace std;

// virtual void attack();
Character::Character(string n, string c): 
      name_(n),
      life_(900),
      strength_(10),
      defense_(10),
      items_({}),
      class_(c)
      {
        cout << "New "<<this->class_<<" ["<<this->name_<<"]" << endl;
      };

void Character::operator <<(Item* i){
    items_.push_back(i);
}

void Character::list_items(){
    vector<Item*>::iterator it;
    cout << "ITEMS: " << endl;
    for(auto n_item: items_){
    stringstream ss;
    ss << "\t NAME ("+n_item->getClass()+"): "+ n_item->getName() + "\n";
    ss << "\t Description: " + n_item->describe() << endl;
    cout << ss.str() << endl;
    }
    
}

void Character::attack(Character &opponent, Weapon* weapon) {
  float new_life = opponent.getLife() - (
      (opponent.getDefense()) + 
      (weapon->getDamage()*this->strength_*0.2)
      );
  cout << this->name_ << " attacked " << opponent.getName()
    << " (" << opponent.getLife() << "HP -> " << new_life  << "HP)\n";
  opponent.setLife(new_life);
}

void Character::show_status(){
  cout << this->name_ << " (" << this->class_ << ")\n" <<
    "\t" << "Life: " << this->life_ << "\n" <<
    "\t" << "Defense: " << this->defense_ << "\n" <<
    "\t" << "Strength: " << this->strength_ << "\n";
}
