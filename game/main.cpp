#include "libGame/item/items.hpp"
#include "libGame/item/item.hpp"
#include "libGame/character/characters.hpp"
#include "libGame/stage/stage.hpp"
#include "libGame/game/game.hpp"

#include <iostream>
#include <vector>

using namespace std;

vector<Item*> Item::all_items_ = {};

int main(){
  vector<Item*> items = {
    new Sword(10, 0.9, "Ice"),
    new Sword(108, 0.8, "Leaf"),
    new Rod(10, 0.9, "Fireblood"),
    new Shadow(10, 7, "Ring of power"),
    new Rod(10, 0.7, "Colossus"),
    new Rock(10, 97, "Ring of defense")
  };
  Game g("Eduardo");
  Stage* stg;
  cout << g.get_hero()->getName() << endl;
  stg = g.get_stage();
  stg->list_drops();
}
/*
 *  try{
    //cout  << stg.get_drop()->getName() << endl;
    vector<Item*> items;

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
  */
