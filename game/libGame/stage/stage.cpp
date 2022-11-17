#include "./stage.hpp"
#include "../item/item.hpp"

Stage::Stage(){
  this->level_ = 0; 
  this->enemy_ = Enemy(this->level_);
  update_level();
}

void Stage::update_level(){
  this->level_++;
  // Atualizar inimigo
  this->enemy_ = Enemy(this->level_);
  // Atualizar drops
  srand(time(0));
  vector<Item*> items = Item::getItems();
  cout << rand() % 3 << " Size: " << items.size() << endl;
  this->drops[0] = items[rand() % 3];
  this->drops[1] = items[rand() % 3];
  this->drops[2] = items[rand() % 3];
}

Item* Stage::get_drop(){
  srand(time(0));
  return this->drops[rand() % 3];
}
