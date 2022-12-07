#include "./sword.hpp"
#include <sstream>

string Sword::describe(){
    stringstream s;
    s << "This is a sword with damage: "; 
    s << this->damage_;
    s << " and critic: ";
    s << this->critic_;
    return s.str();
}
