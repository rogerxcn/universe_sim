#ifndef OBJECT_H_
#define OBJECT_H_

#include "common.h"

class Object {
public:
    Object(double m, double x, double y) :
            mass(m), x(x), y(y) {}

    double getMass() { return mass; }
    double getX() { return x; }
    double getY() { return y; }

    void setMass(double);
    void setX(double);
    void setY(double);

private:
    double mass;        // in kg
    double x;
    double y;
};

class MovingObject : public Object {
public:
    MovingObject(double m, double x, double y, double v = 0) :
            Object(m, x, y), velocity(v) {}

    double getVelocity() { return velocity; }

    void setVelocity(double);
private:
    double velocity;    // in m/s
};


class Star : public Object {
public:
    Star(double m, double x, double y, std::string n) :
            Object(m, x, y), name(n) {}

    std::string getName() { return name; }

    void setName(std::string);

private:
    std::string name;
};


class Planet : public MovingObject {
public:
    Planet(double m, double x, double y, std::string n, double v = 0, Star* s = nullptr) :
            MovingObject(m, x, y, v), name(n), center_star(s) {}

    std::string getName() { return name; }
    Star* getCenterStar() { return center_star; }

    void setName(std::string);
    void setStar(Star*);

private:
    std::string name;
    Star* center_star;
};

#endif
