#ifndef COMMON_HPP_
#define COMMON_HPP_

#include <GL/glut.h>
#include <cmath>
#include <iostream>
#include <cstring>
#include <windows.h>
#include <cstdio>
#include <TextureLoader.h>

#define PI 3.1415927

typedef struct Info {
    float   l_angle;
    float   l_rad;
    float   year;
    float   month;
    float   day;
    float   mercury_year;
    float   venus_year;
    float   mars_year;
    float   jupiter_year;
    float   saturn_year;
    float   uranus_year;
    float   neptune_year;
    float   sun_day;
    float   mercury_day;
    float   venus_day;
    float   mars_day;
    float   jupiter_day;
    float   saturn_day;
    float   uranus_day;
    float   neptune_day;


    double  x;
    double  y;
    double  axis_x;
    double  axis_y;
    double  axis_z;

    GLdouble angle;
} Info;

#endif
