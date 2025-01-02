#include <ostream>
#include "List.h"
#include <iostream>
#include <stdexcept>
#ifndef LISTARRAY_H
#define LISTARRAY_H
template <typename T> 
class ListArray : public List<T> {

    private:
        // miembros privados
	T* arr;
	int max;
	int n;
	static const int MINSIZE = 2;// es de tipo estatico es decir que sera un atributo de la clase no de cada instancia y constante por que no cambia	
	void resize(int new_size){
		T* arr_new = new T[new_size];//se crea el nuevo array con memoria dinamica usando new
		 for ( int i = 0; i < n; i++){
		 	arr_new[i] = arr[i];// copiar el contenido de arr en el nuevo array
		 }
		 delete[] arr; //eliminamos el arr para liberar espacio
	         arr = arr_new;// arr apunta a la direccion de memoria de arr_bew
		 max = new_size;
	}
    public:
	ListArray(): arr(new T[MINSIZE]), max(MINSIZE), n(0){}
	~ListArray(){
	delete[] arr;
	}
        void insert(int pos, T e)override{
		if ( pos < 0 || pos > n){
			throw std::out_of_range("Posición inválida en insert");

		}
		if ( n == max) {// si el array esta lleno aummnetamos su tamaño llamando al método resize  
			
			resize(max * 2);//duplicamos el tamaño
	       
		}
		for ( int i = n; i > pos; --i){//mueve todos los elementos desde la posición de inserción a la derecha, para hacer el hueco y mantener la consistencia
			arr[i] = arr[i - 1];// cada elemento se mueve hacia la derecha
		
		}
		arr[pos] = e;// colocamos el nuevo elemento
		++n;// aumenta el contador de elementos
	
	}
	void append(T e) override{ //
	insert (n,e);
	}
	void prepend(T e) override{
	insert(0,e);
	}
	T remove(int pos) override{
		if ( pos < 0 || pos >= n){
		 throw std::out_of_range("Posición inválida en remove");
		}
		T e_removed = arr[pos];
		for( int i = pos; i < n - 1; ++i){
			arr[i] = arr[i + 1]; // movemos los elementos a la izquierda para evitar que haya un hueco
		}
		--n;
		if (n < max / 4 && max / 2 >= MINSIZE) {
            resize(max / 2);
        }// si se gasta mucho espacio, si el numero de elementos es menor que la 4 parte del maximo y si se reduce no sera inferior al minimo permitido
		return e_removed;
	}
	T get(int pos) const override {
		
		if ( pos < 0 || pos >= n) {
		 throw std::out_of_range("Posición inválida para el método get");}
		return arr[pos];
	}
	int search(T e) const override {
		int pos = 0;
		while( pos < n && e != arr[pos]){
			pos ++;
		}
		if (pos < n) {
		 return pos;
		}
		else {
		return -1;
		}
	}
	bool empty() const override {
		return (n == 0);
	
	}
	int size() const override { 
	return n;
	
	}
	 
	T operator[](int pos) const {// es const ya que no se puede modificar el elemento
		return get(pos);// con el método get obtiene el elemento dada la pos
	}
	friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
		 out << "[";// out los corchetes y cada elemento del array que se obtiene cuando se recorre el for y si no es el último se separa mediante una coma
        	for (int i = 0; i < list.n; ++i) {
            		out << list.arr[i];
            		if (i < list.n - 1) {
                		out << ", ";
            		}	
        	}
        	out << "]";
        	return out;// se devuelve la salid	
	}	
    
};

#endif
