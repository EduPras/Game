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
      defense_(10),
      weapon_(new Sword(8, 3, "Regular Sword")),
      class_(c)
      {
        cout << "New "<<this->class_<<" ["<<this->name_<<"]" << endl;
      };

void Character::setWeapon(Weapon* i){
  this->strength_ = this->strength_- this->weapon_->getDamage();
  this->weapon_  = i;
  this->strength_ += this->weapon_->getDamage();
}
void Character::attack(Character &opponent, Weapon* weapon) {
  float old_life = opponent.getLife();
  float new_life = old_life - (
      (opponent.getDefense()) + 
      (weapon->getDamage()*this->strength_*0.2)
      );
  cout << this->name_ << " attacked " << opponent.getName()
    << " (" << old_life<< "HP -> " << new_life  << "HP)\n";
  opponent.setLife(new_life);
}

void Character::show_status(){
  cout << this->name_ << " (" << this->class_ << ")\n" <<
    "\t" << "Life: " << this->life_ << "\n" <<
    "\t" << "Defense: " << this->defense_ << "\n" <<
    "\t" << "Strength: " << this->strength_ << "\n";
}
