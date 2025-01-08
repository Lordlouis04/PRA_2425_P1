#include "Rectangle.h"


bool Rectangle::check(Point2D* vertices){
     
     return (Point2D::distance(vertices[0],vertices[1])==Point2D::distance(vertices[2],vertices[3]) && Point2D::distance(vertices[1],vertices[2])==Point2D::distance(vertices[3],vertices[0]));
         
}
Rectangle::Rectangle(): Shape() , vs(new Point2D[N_VERTICES]{
    Point2D(-1, 0.5),
    Point2D(1, 0.5),
    Point2D(1, -0.5),
    Point2D(-1, -0.5)}){}
Rectangle::Rectangle(std::string color, Point2D* vertices): Shape(color) {

    if(!(check(vertices))){
    
        throw std::invalid_argument("vertices erroneos");
        
    }
    vs = new Point2D[N_VERTICES];
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = vertices[i];
    }


}
Rectangle::Rectangle(const Rectangle &r): Shape(r.color) {
    vs = new Point2D[N_VERTICES];
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = r.vs[i];
    }
}
Rectangle::~Rectangle(){

   delete[] vs;

}
Point2D Rectangle::get_vertex(int ind) const{

    if(ind<0 || ind>=N_VERTICES){
     
        throw std::out_of_range("indice incorrecto");
    
    }
    return vs[ind];


}
Point2D Rectangle::operator[](int ind) const{
    return get_vertex(ind);
}
void Rectangle::set_vertices(Point2D* vertices){

    if(!(check(vertices))){

        throw std::invalid_argument("vertices erroneos");

    }
 for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = vertices[i];
    }    
}
Rectangle& Rectangle::operator=(const Rectangle &r){

    if (this != &r) {
        Shape::operator=(r);
        for (int i = 0; i < N_VERTICES; i++) {
            vs[i] = r.vs[i];
        }
    }
    return *this;
}


std::ostream& operator<<(std::ostream &out, const Rectangle &r){

    out<<"[Rectangle: "<<"color: "<<r.get_color()<<"  Vertices=  v0 "<<r[0]<<"  v1"<<r[1]<<"  v2 "<<r[2]<<" v3"<<r[3]<<std::endl;
    return out;



}
double Rectangle::area() const{

   return Point2D::distance(vs[0],vs[1])*Point2D::distance(vs[1],vs[2]);
}
double Rectangle::perimeter() const{

    return 2*Point2D::distance(vs[0],vs[1])+2*Point2D::distance(vs[1],vs[2]);


}
void Rectangle::translate(double incX,double incY){

     for(int i =0;i<4;i++){
         vs[i].x+=incX;
         vs[i].y+=incY;	 
     }

}
void Rectangle::print(){


std::cout<<(*this)<<std::endl;
}
