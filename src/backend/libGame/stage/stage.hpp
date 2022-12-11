#ifndef STAGE_HPP
#define STAGE_HPP

#include "../character/characters.hpp"
#include "../item/items.hpp"
#include <array>

class Stage {
  private:
    int level_;
    Enemy* enemy_;
    vector<Weapon*> weapons = {
    new Sword(30, 0.9, "Ice"),      //54
    new Sword(100, 0.8, "Leaf"),    //180
    new Rod(40, 0.9, "Fireblood"),  //72
    new Rod(20, 0.7, "Colossus")     //36
    };
    vector<Ring*> rings = {
    new Ring(100, 20, "Ring of life"),
    new Ring(50, 50, "Ring of defense")
  };
  
  public:
    Stage(int l): enemy_(new Enemy(1)), level_(l) {};
    ~Stage() {};
    //Item* get_drop();
    int get_level(){return this->level_;}
    //void list_drops();
    void update_level(Character* c);
    Enemy* get_enemy(){ return this->enemy_; };
}; 

#endif
