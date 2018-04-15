#include "common.h"
#include "object.h"
#include "system.h"

int main(int argc, char const *argv[]) {
    std::cout << "---[DEBUG] Unit test for objects.---" << '\n';

    Star Sun(1.989e30, 0, 0, "Sun");
    std::cout << "Created a star: " << Sun.getName() << '\n';
    std::cout << '\n';

    Planet Earth(5.972e24, 0, 0, "Earth", 460, &Sun);
    std::cout << "Created a planet: " << Earth.getName() << '\n';
    std::cout << "Its centering star is " << Earth.getCenterStar()->getName() << '\n';
    std::cout << '\n';

    System SolarSystem("Solar System");
    std::cout << "Created a system: " << SolarSystem.getName() << '\n';
    SolarSystem.addStar(&Sun);
    SolarSystem.addPlanet(&Earth);
    std::cout << '\n';
    
    return 0;
}
