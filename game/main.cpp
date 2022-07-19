#include <iostream>
#include "libGame/item/item.hpp"
#include "libGame/character/character.hpp"

using namespace std;

int main(){
  Item *s = new Sword(10, 0.9, "Ice");
  Character *c = new Character("Hero");
  c->pick(s);
  c->list_items();
  delete s;
  delete c;
  return 0;
}
