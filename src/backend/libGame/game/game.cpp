#include "./game.hpp"

void Game::hit_enemy(){
    this->hero_.attack(
        *(this->stage_.get_enemy()),
        hero_.getWeapon()
    );
}