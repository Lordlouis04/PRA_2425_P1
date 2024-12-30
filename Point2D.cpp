#include "Point2D.h"

Point2D::Point2D(double x=0, double y=0){
	this->x=x;
	this->y=y;
}
double Point2D::distance(const Point2D &a,const Point2D &b){
	double j=(b.x - a.x)*(b.x - a.x) + (b.y - a.y)*(b.y - a.y);
	double dist=sqrt(j);
	return dist;
}
bool operator==(const Point2D &a, const Point2D &b){
	return (a.x==b.x && a.y==b.y);
}
bool operator!=(const Point2D &a, const Point2D &b){
	return !(a==b);
}
std::ostream &operator<<(std::ostream &out, const Point2D &p){
	out<<"("<<p.x <<", "<<p.y<<")";
	return out;
}
