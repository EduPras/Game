#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "character.hpp"

using namespace std;

Character::Character(string n): 
      name_(n),
      life_(100),
      strength_(10),
      defense_(10) {}

/*
void Character::operator <<(Item* i){
    items_.push_back(i);
} */
/*
void Character::list_items(){
    vector<Item*>::iterator it;
    cout << "ITEMS: " << endl;
    for(auto n_item: items_){
    stringstream ss;
    ss << "\t NAME ("+n_item->getClass()+"): "+ n_item->getName() + "\n";
    ss << "\t Description: " + n_item->describe() << endl;
    cout << ss.str() << endl;
    }
    
}*/

void Character::attack(Character* opponent, Weapon* weapon) {
  float new_life = opponent->getLife() - (
      (weapon->getDamage()*this->strength_*0.2) * ((1 - (opponent->getDefense())/100))
      );
  opponent->setLife(new_life);
}
