#include "object.h"

void Object::setMass(double m) { mass = m; }

void Object::setX(double d) { x = d; }

void Object::setY(double d) { y = d; }

void MovingObject::setVelocity(double v) { velocity = v; }

void Star::setName(std::string s) { name = s; }

void Planet::setName(std::string s) { name = s; }
