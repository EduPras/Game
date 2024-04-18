#include "shadow.hpp"
#include <sstream>

string Shadow::describe(){
    stringstream s;
    s << "This is a ring with glow: ";
    s << glow_;
    s << " and increases chearacter's spell by: ";
    s << spell_;
    return s.str();
}
