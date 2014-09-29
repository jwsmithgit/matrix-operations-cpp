/* 
 * File:   Point3d.h
 * Author: jacob
 *
 * Created on January 26, 2014, 9:13 AM
 */

#ifndef POINT3D_H
#define	POINT3D_H

#include <string>

class Point3d {
public:
    Point3d();
    Point3d(const Point3d& orig);
    virtual ~Point3d();
    Point3d(int a, int b, int c);
    int get_x();
    int get_y();
    int get_z();
    void set_x(int a);
    void set_y(int a);
    void set_z(int a);
    std::string getString();
    void rotate_x(int angle);
    void rotate_y(int angle);
    void rotate_z(int angle);
    void translate(int tx, int ty, int tz);
    void scale(double sx, double sy, double sz);
        
private:
    int x, y, z;

};

#endif	/* POINT3D_H */

