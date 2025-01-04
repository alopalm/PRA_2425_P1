#include"Drawing.h"
#include"Square.h"
#include"Circle.h"
#include "ListLinked.h"

Drawing::Drawing(){
	shapes = new ListLinked<Shape*>();


}
Drawing::~Drawing(){
	if (shapes != nullptr) {
    for (int i = 0; i < shapes->size(); ++i) {
        delete shapes->get(i);
    }
    delete shapes;
}}
void Drawing::add_front(Shape* shape){
	shapes->prepend(shape);

}
void Drawing::add_back(Shape* shape){
	 shapes->append(shape);
}
void Drawing::print_all(){

	 if (shapes->empty()) {
        std::cout << "El dibujo no contiene figuras." << std::endl;
        return;
    }

    for (int i = 0; i < shapes->size(); ++i) {
        std::cout << "Shape:  " << i + 1 << ": ";
        shapes->get(i)->print();
    	std::cout << std::endl;
    }

}
double Drawing::get_area_all_circles(){
	double total_area = 0.0;

    for (int i = 0; i < shapes->size(); ++i) {
        Shape* shape = shapes->get(i);
        Circle* circle = dynamic_cast<Circle*>(shape);
        if (circle != nullptr) {//Si la figura es de tipo Circle, el resultado del dynamic_cast será un puntero válido
            total_area += circle->area();
        }
    }

    return total_area;

}
void Drawing::move_squares(double incX, double incY){

	for (int i = 0; i < shapes->size(); ++i) {
        
        Shape* shape = shapes->get(i);
        Square* square = dynamic_cast<Square*>(shape);
        if (square != nullptr) {
            // Si es un Square, llama a su método translate
            square->translate(incX, incY);
        }
	}
}
