#include "libGame/item/items.hpp"
#include "libGame/character/characters.hpp"

#include <iostream>
#include <vector>

using namespace std;

int Item::no_items = 0;

int main(){
  vector<Item*> items;
  items.push_back(new Sword(10, 0.9, "Ice"));
  items.push_back(new Rod(10, 0.7, "Colossus"));
  items.push_back(new Rock("Death ring", 5, 10));
  Character c = Warrior("Garrosh");
  Character w = Wizard("Guldan");
  c << (items[0]);
  c << (items[2]);
  c.show_status();
  w.show_status();
  w.attack(c, (Weapon *)items[1]);
  cout << Item::getNumberOfItems() << " items\n";
  return 0;
}
