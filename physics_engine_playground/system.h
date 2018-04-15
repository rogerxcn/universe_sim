#ifndef SYSTEM_H_
#define SYSTEM_H_

#include "object.h"

class System {
public:
    System() : name("The System") {}
    System(std::string n) : name(n) {}
    ~System();

    std::string getName() { return name; }

    void setName(std::string);
    void addStar(Star*);
    void addPlanet(Planet*);
    void addMovingObject(MovingObject*);

    void step()

private:
    std::string name;
    std::vector<Star*> stars;
    std::vector<Planet*> planets;
    std::vector<MovingObject*> mos;
};

#endif
