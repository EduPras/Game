#include <iostream>
#include "libGame/item/items.hpp"
#include "libGame/character/character.hpp"

using namespace std;

int main(){
  Item *s = new Sword(10, 0.9, "Ice");
  Character *c = new Character("Hero");
  c->pick(s);
  cout << s->describe() << endl;
  c->list_items();
  delete s;
  delete c;
  return 0;
}
