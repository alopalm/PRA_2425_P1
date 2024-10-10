#include <ostream>
#include "List.h"

template <typename T> 
class ListArray : public List<T> {

    private:
        // miembros privados
	T* arr;
	int max;
	int n;
	static const int MINSIZE = 2;  // es de tipo estatico es de cir que sera un atributo de la clase no de cada instancia y constante por que no cambia

    public:
	ListArray();
	~ListArray();
	T operator[](int pos);
	friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list);
	void resize(int new_size);
        void insert(int pos, T e);
	void append(T e) override;
	void prepend(T e) override;
	T remove(int pos) override;
	T get(int pos) override;
	int search(T e) override;
	bool empty() override;
	int size() override;
	 // miembros públicos, incluidos los heredados de List<T>
    
};

	ListArray::ListArray(){
		 n=0;
		 MINSIZE = 2;
		 max= MINSIZE;
		 arr= new T[MINSIZE];
	}

	ListArray::~ListArray(){
		delete[] arr;
	
	}
	
	T ListArray::operator[](int pos){
	size = size();
	if (pos>= 0 && pos < size) { return arr[pos]; }
	else { throw ; }	
	}


