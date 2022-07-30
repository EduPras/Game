#include "libGame/item/items.hpp"
#include "libGame/character/character.hpp"

#include <iostream>
#include <vector>

using namespace std;

int Item::no_items = 0;

int main(){
  vector<Item*> items;
  items.push_back(new Sword(10, 0.9, "Ice"));
  items.push_back(new Rock("Death ring", 5, 10));
  Character c = Character("Hero");
  c << (items[0]);
  c << (items[1]);
  c.list_items();
  cout << Item::getNumberOfItems() << " items\n";
  return 0;
}
