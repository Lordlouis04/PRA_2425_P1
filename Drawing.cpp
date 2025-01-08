#include "Drawing.h"
#include "ListLinked.h"
#include "List.h"
#include "Shape.h"
#include "Circle.h"
#include "Square.h"
#include "Rectangle.h"


Drawing::Drawing(){


    shapes = new ListLinked<Shape*>;


}
Drawing::~Drawing(){
    delete[] shapes;
}
void Drawing::add_front(Shape* shape){
    shapes->append(shape);
}
void Drawing::add_back(Shape* shape){
    shapes->prepend(shape);
}
void Drawing::print_all(){

    
     for (int i = 0; i < shapes->size(); i++) {
       
    
        Shape* shape = shapes->get(i);
        shape->print();
    }
}
    
    
    


    

double Drawing::get_area_all_circles(){
    
    double areat=0;
    for (int i = 0; i < shapes->size(); i++) {
        Shape* s = shapes->get(i);    
        if(Circle* h = dynamic_cast<Circle*>(s)){
            areat += h->area();
        }
    }
    return areat;
    	

    }
void Drawing::move_squares(double incX, double incY){
    
     for (int i = 0; i < shapes->size(); i++) {
        Shape* s = shapes->get(i);
        if(Square* h = dynamic_cast<Square*>(s)){
            h->translate(incX,incY);
    
    }
    }




}
