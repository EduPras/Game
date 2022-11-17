#include "libGame/item/items.hpp"
#include "libGame/character/characters.hpp"

#include <iostream>
#include <vector>

using namespace std;

vector<Item*> Item::all_items_ = {};

int main(){
  try{
    vector<Item*> items;
    items.push_back(new Sword(10, 0.9, "Ice"));
    items.push_back(new Sword(10, 0.8, "Ice"));
    items.push_back(new Rod(10, 0.7, "Colossus"));
    items.push_back(new Rock("Death ring", 5, 10));
    Character c = Hero("Garrosh");
    Character w = Enemy("Guldan");
    c << (items[0]);
    c << (items[2]);
    c.show_status();
    w.show_status();
    w.attack(c, (Weapon *)items[1]);
    cout << Item::getNumberOfItems() << " items\n";
  }catch(string msg){
    cout << msg;
  }
  return 0;
}
