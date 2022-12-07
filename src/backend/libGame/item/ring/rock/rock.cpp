#include "rock.hpp"
#include <sstream>

string Rock::describe(){
    stringstream s;
    s << "This is a ring with glow: ";
    s << glow_;
    s << " and increases chearacter's life by: ";
    s << life_;
    return s.str();
}
