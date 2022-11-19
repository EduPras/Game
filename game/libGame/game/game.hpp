#ifndef GAME_HPP
#define GAME_HPP

#include "../stage/stage.hpp"
#include "../character/characters.hpp" 

class Game {
  private:
    Stage stage_;
    Hero hero_;
    int turn_;
    Character *attacker_;
    vector<Item*> items_;
  public:
    Game(string n): 
      hero_(n), turn_(0), stage_() {};
    Character* get_hero(){ return &hero_; };
    Stage* get_stage(){ return &stage_; };
    int get_turn(){ return this->turn_; };


};

#endif
