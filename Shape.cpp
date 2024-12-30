#include "Shape.h"
using namespace std;

Shape::Shape(){
    color="red";
}

Shape::Shape(string col){
    if(col != "red" &&  col != "blue" && col != "green"){
           throw std::invalid_argument("color invalido");
       }
    color=col;
}

string Shape::get_color() const{
    return color;
}

void Shape::set_color(string col){ 
    color=col;	
}
