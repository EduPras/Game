#include "./stage.hpp"
#include "../item/item.hpp"

Stage::Stage(){
  this->level_ = 0; 
  this->enemy_ = Enemy(this->level_);
  this->update_level();
}

void Stage::update_level(){
  this->level_++;
  // Atualizar inimigo
  this->enemy_ = Enemy(this->level_);
  // Atualizar drops
  srand(time(0));
  vector<Item*> items = Item::getItems();
  if(items.size() > 3){
    this->drops_[0] = items[rand() % 3];
    this->drops_[1] = items[rand() % 3];
    this->drops_[2] = items[rand() % 3];   
  }
}

Item* Stage::get_drop(){
  srand(time(0));
  return this->drops_[rand() % 3];
}

void Stage::list_drops(){
  cout << "Drops (lvl " << this->level_ << "): " << endl;
  for(int i = 0; i < 3; i++)
    cout << "\t["<< i+1 <<"]: " << drops_[i]->getName()<< endl;
}
