#ifndef STAGE_HPP
#define STAGE_HPP

#include "../character/characters.hpp"
#include "../item/items.hpp"
#include <array>

class Stage {
  private:
    int level_;
    array<Item*, 3> drops_;
    Enemy *enemy_;
  public:
    Stage(int l): enemy_(new Enemy()), level_(l) {};
    ~Stage();
    Item* get_drop();
    void list_drops();
    void update_level();
    Enemy* get_enemy(){ return this->enemy_; };
}; 

#endif
