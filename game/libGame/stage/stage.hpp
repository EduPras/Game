#ifndef STAGE_HPP
#define STAGE_HPP

#include "../character/character.hpp"
#include "../item/items.hpp"

class Stage {
  private:
    int level_;
    vector<Item*> drops;
    Character enemy_;
  public:
    Item* get_drop();
    void update_level();
}; 

#endif
