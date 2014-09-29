/* 
 * File:   Point3d.cpp
 * Jacob Smith
 * V00700979
 * CSC 305
 * Assignment 1
 */

#include "Point3d.h"
#include <sstream>
#include <math.h>

const double pi = 3.1415926;

// constructors
Point3d::Point3d() {
    x = 0;
    y = 0;
    z = 0;
}

Point3d::Point3d(const Point3d& orig) {
}

Point3d::~Point3d() {
}

Point3d::Point3d(int a, int b, int c){
    x = a;
    y = b;
    z = c;
}

// gtters
int Point3d::get_x(){
    return x;
}

int Point3d::get_y(){
    return y;
}

int Point3d::get_z(){
    return z;
}

// setters
void Point3d::set_x(int a){
    x = a;
}

void Point3d::set_y(int a){
    y = a;
}

void Point3d::set_z(int a){
    z = a;
}

// turns point into printible string
std::string Point3d::getString(){
    std::stringstream sstr;
    sstr << "["<<x<<"]\n["<<y<<"]\n["<<z<<"]\n";
    std::string str = sstr.str();
    return str;
}

// rotate point around x axis
void Point3d::rotate_x(int angle){
    double rangle = angle*pi/180;
    int ytemp = y;
    y = (int)round(((y*cos(rangle)) - (z*sin(rangle))));
    z = (int)round(((ytemp*sin(rangle)) + (z*cos(rangle))));
}

// rotate point around y axis
void Point3d::rotate_y(int angle){
    double rangle = angle*pi/180;
    int xtemp = x;
    x = (int)round(((x*cos(rangle)) + (z*sin(rangle))));
    z = (int)round((-(xtemp*sin(rangle)) + (z*cos(rangle))));
}

// rotate point around z axis
void Point3d::rotate_z(int angle){
    double rangle = angle*pi/180;
    int xtemp = x;
    x = (int)round(((x*cos(rangle)) - (y*sin(rangle))));
    y = (int)round(((xtemp*sin(rangle)) + (y*cos(rangle))));
}

// translate point
void Point3d::translate(int tx, int ty, int tz){
    x = x+tx;
    y = y+ty;
    z = z+tz;
}

// scale point
void Point3d::scale(double sx, double sy, double sz){
    x = (int)(sx*x);
    y = (int)(sy*y);
    z = (int)(sz*z);
}

