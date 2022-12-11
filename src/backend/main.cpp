#include "libGame/item/items.hpp"
#include "libGame/item/item.hpp"
#include "libGame/character/characters.hpp"
#include "libGame/stage/stage.hpp"
#include "libGame/game/game.hpp"

#include <iostream>
#include <vector>

using namespace std;


/*vector<Item*> Item::all_items_ = {};

vector<Item*> create_items(){
  vector<Item*> items = {
    new Sword(10, 0.9, "Ice"),
    new Sword(108, 0.8, "Leaf"),
    new Rod(10, 0.9, "Fireblood"),
    new Shadow(10, 7, "Ring of power"),
    new Rod(10, 0.7, "Colossus"),
    new Rock(10, 97, "Ring of defense")
  };
  system("clear");
  return items;
}

void close_game(vector<Item*> *items){
  cout << "Closing game..." << endl;
  for(auto it = items->begin(); it != items->end(); it++)
    delete *it;
}

int main(){
  //vector<Item*> items = create_items();
  Game g("Eduardo");
  //g.get_stage()->update_level();
  //close_game(&items);
  int c = getchar();
}
