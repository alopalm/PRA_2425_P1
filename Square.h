#ifndef SQUARE_H
#define SQUARE_H
#include <stdexcept>
#include <ostream>
#include "Point2D.h"
#include "Rectangle.h"

 class Square : public Rectangle{
 
 	private:
		static bool check(Point2D* vertices);
	public:
 		Square();
		Square(std::string color, Point2D* vertices);
		void set_vertices(Point2D* vertices) override;
		friend std::ostream& operator<<(std::ostream &out, const Square &square);
 		double area() const override;
    		double perimeter() const override;
		void translate(double incX, double incY) override;
		void print() override; 
 };

#endif
