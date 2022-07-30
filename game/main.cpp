#include "libGame/item/items.hpp"
#include "libGame/character/character.hpp"

#include <iostream>
#include <vector>

using namespace std;

int main(){
  vector<Item*> items;
  items.push_back(new Sword(10, 0.9, "Ice"));
  items.push_back(new Rock("Death ring", 5, 10));
  Character *c = new Character("Hero");
  c->pick(items[0]);
  c->pick(items[1]);
  cout << items[0]->describe() << endl;
  cout << items[1]->describe() << endl;
  c->list_items();
  delete c;
  return 0;
}
