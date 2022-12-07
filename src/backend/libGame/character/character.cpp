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
