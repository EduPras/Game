#include "./rod.hpp"
#include <sstream>

string Rod::describe(){
    stringstream s;
    s << "This is a rod with damage: ";
    s << damage_;
    s << " and spell damage: ";
    s << spell_damage;
    return s.str();
}