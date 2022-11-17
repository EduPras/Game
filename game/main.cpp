#include "libGame/item/items.hpp"
#include "libGame/character/characters.hpp"
#include "libGame/stage/stage.hpp"

#include <iostream>
#include <vector>

using namespace std;

vector<Item*> Item::all_items_ = {};

int main(){
  try{
    //cout  << stg.get_drop()->getName() << endl;
    vector<Item*> items;
    items.push_back(new Sword(10, 0.9, "Ice"));
    items.push_back(new Sword(10, 0.8, "Ice 2"));
    items.push_back(new Rod(10, 0.7, "Colossus"));
    items.push_back(new Rod(10, 0.7, "Colossus 2"));
    Stage *stg =  new Stage();
    cout <<  "Stg: " << stg->get_drop()->getName() << endl;
    Character c = Hero("Garrosh");
    c << (items[0]);
    c << (items[2]);
    c.show_status();
    cout << Item::getNumberOfItems() << " items\n";
  }catch(string msg){
    cout << msg;
  }
  return 0;
}
