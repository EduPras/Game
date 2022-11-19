#ifndef STAGE_HPP
#define STAGE_HPP

#include "../character/characters.hpp"
#include "../item/items.hpp"
#include <array>

class Stage {
  private:
    int level_;
    array<Item*, 3> drops_;
    Enemy enemy_;
  public:
    Stage();
    Item* get_drop();
    void list_drops();
    void update_level();
}; 

#endif
