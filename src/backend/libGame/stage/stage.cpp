#include "./stage.hpp"
#include "../item/item.hpp"


void Stage::update_level(Character* c){
  this->level_++;
  // Atualizar inimigo
  delete enemy_;
  this->enemy_ = new Enemy(this->level_);

  // Atualizar drops
  srand(time(0));
  c->setWeapon(this->weapons[rand()%4]);
  c->setRing(this->rings[rand()%2]);
}
/*
Item* Stage::get_drop(){
  srand(time(0));
  return this->drops_[rand() % 3];
}

void Stage::list_drops(){
  cout << "Drops (lvl " << this->level_ << "): " << endl;
  for(int i = 0; i < 3; i++)
    cout << "\t["<< i+1 <<"]: " << drops_[i]->getName()<< endl;
}

Stage::~Stage(){
  delete this->enemy_;
}
*/