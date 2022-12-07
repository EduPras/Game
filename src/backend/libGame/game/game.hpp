#ifndef GAME_HPP
#define GAME_HPP

#include "../stage/stage.hpp"
#include "../character/characters.hpp" 

class Game {
  private:
    Stage stage_;
    Hero hero_;
    int turn_;
  public:
    Game(string n): 
      hero_(n), turn_(0), stage_(0) {};
    Character* get_hero(){ return &hero_; };
    Stage* get_stage(){ return &stage_; };
    int get_turn(){ return this->turn_; };
    ~Game(){}
};

#endif
