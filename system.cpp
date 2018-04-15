#include "system.h"

void System::setName(std::string n) { name = n; }

void System::addStar(Star* s) { stars.push_back(s); }

void System::addPlanet(Planet* p) { planets.push_back(p); }

void System::addMovingObject(MovingObject* m) { mos.push_back(m); }
