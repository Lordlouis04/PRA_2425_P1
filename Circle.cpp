#include "Circle.h"
#define PI 3.141592
using namespace std;

Circle::Circle() : center(Point2D(0,0)), Shape(), radius(1) {}

Circle::Circle(string color, Point2D center, double radius)
    : Shape(color), center(center), radius(radius) {}

Point2D Circle::get_center() const {
    return center;
}

void Circle::set_center(Point2D p) {
    center = p;
}

double Circle::get_radius() const {
    return radius;
}

void Circle::set_radius(double r) {
    radius = r;
}

ostream& operator<<(ostream &out, const Circle &c) {
    out << "Color: " << c.get_color() <<endl
        << "Centro: " << c.get_center() <<endl
        << "Radio: " << c.get_radius() <<endl;
    return out;
}

double Circle::area() const {
    return PI * pow(get_radius(), 2);
}

double Circle::perimeter() const {
    return 2 * PI * get_radius();
}

void Circle::translate(double incX, double incY) {
    center.x += incX;
    center.y += incY;
}

void Circle::print() {
    cout << (*this) << endl;
}

