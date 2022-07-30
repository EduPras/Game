#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "character.hpp"

using namespace std;

Character::Character (string n){
    this->name = n;
    this-> life = 900;
    this->strength = 10;
    this->defense = 10;
    items.clear();
    cout << "Personagem " << this->name << " criado" << endl;
};
// virtual void attack();
void Character::operator <<(Item* i){
    items.push_back(i);
}

void Character::list_items(){
    vector<Item*>::iterator it;
    cout << "ITEMS: " << endl;
    for(auto n_item: items){
    stringstream ss;
    ss << "\t NAME ("+n_item->getClass()+"): "+ n_item->getName() + "\n";
    ss << "\t Description: " + n_item->describe() << endl;
    cout << ss.str() << endl;
    }
    
}
