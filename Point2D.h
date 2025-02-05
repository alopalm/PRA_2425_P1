#ifndef POINT2D_H
#define POINT2D_H
#include <ostream>
#include <cmath>
class Point2D{
    
	public:
		double x;
		double y;
		Point2D(double x= 0, double y=0);
		static double distance(const Point2D &a, const Point2D &b){
			return std::sqrt(std::pow(a.x - b.x, 2 ) + std::pow(a.y - b.y,2));
		
		}
		friend bool operator==( const Point2D &a, const Point2D &b){
			return( (a.x == b.x) && (a.y == b.y));
		}
		friend bool operator!=(const Point2D &a, const Point2D &b){
			return( (a.x != b.x) && (a.y != b.y));
		}
		friend std::ostream& operator<<(std::ostream &out, const Point2D &p){
		out<<"Punto bidimensional=>  ("<< p.x <<","<< p.y<<")";
		return out;
		}


};

#endif
