#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include "Point2D.h"

    class Shape{
    	protected:
		std::string color;
	
	public:
		Shape():color("red"){}
		Shape(std::string color){
			if ( color != "red" && color != "blue" && color !="green"){
					throw std::invalid_argument("Argumento inválido, ese color no esta disponible");
					}  
		
		}
		std::string get_color() const{
			return color;
		}
		void set_color(std::string c){
		
			if ( c!="red" && c != "blue" && c != "green"){
					throw std::invalid_argument("Argumento inválido, ese color no esta disponible");
					}  
			else {
			
			color = c;
					}
		}
		
		virtual double area() const = 0;
		virtual double perimeter() const = 0;
		virtual void translate(double incX, double incY) = 0;
		virtual void print() = 0;


    
    
    };

#endif
