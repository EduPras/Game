#include "warrior.hpp"
#include <string>

using namespace std;

void Warrior::increase_defense(){
  cout << "The defense of " << this->name_ << " increased 10%!\n";
  this->defense_  += (this->defense_)/10; 
}


