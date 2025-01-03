#include"Shape.h"
#include "Point2D.h"
#include <string>
#include <stdexcept>

Shape::Shape():color("red"){}
Shape::Shape(std::string color){
                        if ( color != "red" && color != "blue" && color !="green"){
                                        throw std::invalid_argument("Argumento inválido, ese color no esta disponible");
                                        }
			this->color = color;
                }
std::string Shape::get_color() const{
                        return color;
                }
void Shape::set_color(std::string c){

                        if ( c!="red" && c != "blue" && c != "green"){
                                        throw std::invalid_argument("Argumento inválido, ese color no esta disponible");
                                        }

                        this->color = c;
                                        
                }
