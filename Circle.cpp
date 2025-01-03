#include "Circle.h"
#include<stdexcept>
#include<string>
#include<iostream>
#include<cmath>
using namespace std;

    Circle::Circle(): Shape("red"), center(0.0, 0.0), radius(1.0) {
}
    Circle::Circle(const std::string color,Point2D center, double radius): Shape(color), center(center), radius(radius) {
    if (radius <= 0) {
        throw std::invalid_argument("El radio debe ser mayor que cero.");
    }
}
    Point2D Circle::get_center() const{
    	return center;
    
    }
    void Circle::set_center(Point2D p){
    	this->center = p;
    
    }
    double Circle::get_radius() const{
    	return radius;
    
    }
    void Circle::set_radius(double r){
    	this->radius = r;
    
    }
    std::ostream& operator<<(std::ostream &out, const Circle &c){
	    out << "Circle: center=(" <<c.center.x << ", " << c.center.y
        << "), radius=" << c.radius                                       << ", color=" << c.color
        << ", area=" << c.area()
        << ", perimeter=" << c.perimeter();
	return out;
    }

    double Circle::area() const{
    	return 2 * pow(radius,2);
    
    }
    double Circle::perimeter() const{
   	return 2 * M_PI * radius; 
    }
    void Circle::translate(double incX, double incY){
    
    	 center.x += incX;
    	 center.y += incY;
    }

    void Circle::print() {
	    std::cout << "Circle: center=(" << center.x << ", " << center.y
        << "), radius=" << radius
        << ", color=" << color
        << ", area=" << area()
        << ", perimeter=" << perimeter();
}
