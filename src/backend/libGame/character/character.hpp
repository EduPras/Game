#ifndef CHARACTER
#define CHARACTER

#include <iostream>
#include <string>
#include <vector>
#include "../item/item.hpp"
#include "../item/items.hpp"
#include "../item/weapon/weapon.hpp"

using namespace std;
class Character {
  protected:
    string name_;
    float life_;
    int strength_, defense_;
    Weapon* main_weapon;
    Ring* ring_;

  public:
    Character (string n);
    ~Character (){
      cout << "Deleting character :"<< this->name_ <<"...\n";
    }
    void attack(Character* opponent, Weapon* weapon);
    
    //void operator <<(Item* i);
    //void list_items();

    // getters
    string getName() { return this->name_; }
    Weapon* getWeapon(){ return this->main_weapon;}
    Ring* getRing(){return this->ring_;}
    float getLife() { return this->life_; }
    int getStrength() { return this->strength_; }
    int getDefense() { return this->defense_; }

    // setters
    void setLife(float l){ this->life_ = l; }
    void setWeapon(Weapon* w){ this->main_weapon = w; }
    void setRing(Ring* r){ this->ring_ = r; }
};

#endif
