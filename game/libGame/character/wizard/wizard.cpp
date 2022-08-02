#include "wizard.hpp"
#include <string>

using namespace std;

void Wizard::magic_attack(Character &opponent){
  opponent.setLife(opponent.getLife() - this->magic*0.1);
}
