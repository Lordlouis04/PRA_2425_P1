#ifndef POINT2D_H
#define POINT2D_H

#include <cmath>
#include <ostream>
class Point2D
{
 public:
    double x,y;
    Point2D(double x, double y);
    friend bool operator==(const Point2D &a,const Point2D &b);
    friend bool operator!=(const Point2D &a,const Point2D &b);
    friend std::ostream &operator<<(std::ostream &out, const Point2D &p);
    static double distance (const Point2D &a,const Point2D &b);

};
 #endif
