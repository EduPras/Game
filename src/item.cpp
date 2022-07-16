#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <typeinfo>
#include "item.hpp"

using namespace std;

// Item
string Item::describe() {
  return "Unavailable item!";
}
string Item::getClass () {
    return "Item";
}
string Item::getName () {
  return this->name;
}

// Weapon : Item
string Weapon::getClass() {
  return "Weapon";
}

// Sword : Weapon
Sword::Sword(int d, float c, string s) {
    this->damage = d;
    this->critic = c;
    this->name = s;
} 
string Sword::describe(){
    stringstream s;
    string str;
    s << "This is a sword with damage: ";
    s << this->damage;
    s << " and critic: ";
    s << this->critic;
    str = s.str();
    return str;
}
string Sword::getClass() {
  return "Sword";
}
