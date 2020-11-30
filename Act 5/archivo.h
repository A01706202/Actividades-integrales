#ifndef ARCHIVO_H_
#define ARCHIVO_H_

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>
#include <string>
#include <fstream>

using namespace std;

template <class T>
class Archivo {		
	public:
	void ordenar_datos(vector<string> &b, vector<string> &h);
	void buscar_datos(vector<T> &b, vector<string> &h, string in, string fin);
};

//Ordena los datos
template <class T>
void Archivo<T>::ordenar_datos(vector<string> &b, vector<string> &h){
	int min;
	string aux, aux2;
	for(int i=0; i<h.size()-1; i++){
		min=i;
		for(int j=i+1; j<h.size()-1; j++){
			if(h[j]<h[min]){
				min=j;
			}
		}
		aux=h[i];
		h[i]=h[min];
		h[min]=aux;
		
		aux2=b[i];
		b[i]=b[min];
		b[min]=aux2;
	}
}

//Hace una búsqueda secuencial de datos, los imprime y los gurada en el archivo
template <class T>
void Archivo<T>::buscar_datos(vector<T> &b, vector<string> &h, string in, string fin){
	ofstream resultado;
	resultado.open("busqueda.txt",ios::out);
	for(int i=0; i<=b.size(); i++){
        if(h[i]>=in && h[i]<=fin){
        resultado<<b[i]<<"\n";
        cout<<b[i]<<endl;
        }
	}
	resultado<<"\n\n\n";
	resultado.close();
}

template <class T>
class Heap {
    private:
	    T *data;
	    unsigned int tam;
	    unsigned int cont;
	    
	    //Valores que le pondremos al arbol
		int laboratorio;
		int baseDatos;
		int cafeteria;
		int jardin; 
		int observatorio;
		int almacen;	    

    public:
	    Heap(unsigned int ta);
	    ~Heap();
	    void agregar_dato(vector<string> &b);
	    void mas_concurridos();
	    
	    //Funciones del árbol heap
	    void push(T);
	    T pop();
	    int size();
	    int top();
	    bool empty() const;
	    bool full() const;	    
	    void clear();	 
		unsigned int parent(unsigned int) const;
	    unsigned int left(unsigned int) const;
	    unsigned int right(unsigned int) const;
	    void heapify(unsigned int);
	    void swap(unsigned int, unsigned int);   
};


template <class T>
Heap<T>::Heap(unsigned int ta) {
	tam = ta;
	data = new T[tam];
	cont = 0;
	laboratorio = 0; 
	baseDatos = 0;
	cafeteria = 0;
	jardin = 0; 
	observatorio = 0;
	almacen = 0;	 
}

template <class T>
Heap<T>::~Heap() {
	delete [] data; 
	data = 0;
	tam = 0; 
	cont = 0;
	laboratorio = 0; 
	baseDatos = 0;
	cafeteria = 0;
	jardin = 0; 
	observatorio = 0;
	almacen = 0;
}

//Por aqui pasa el vector con los nombres de los lugares, se cuenta cuantes veces se repite cada lugar, 
//los guarda en los valores y estos se agregan al árbol al final
template <class T>
void Heap<T>::agregar_dato(vector<string> &b){
	for(int i = 0; i <= b.size(); i++){
    	if(b[i] == "laboratorio")
    	    laboratorio += 1;
    	if(b[i] == "base_de_datos")
    	    baseDatos += 1;
    	if(b[i] == "cafeteria")
    	    cafeteria += 1;
    	if(b[i] == "jardin")
    		jardin += 1;
    	if(b[i] == "observatorio")
    		observatorio += 1;
    	if(b[i] == "almacen")
		  	almacen += 1;
	}
	
	push(laboratorio);
	push(baseDatos);
	push(cafeteria);
	push(jardin);
	push(observatorio);
	push(almacen);
}

//Se recorre la lista y dependiendo de los valores, muestran que lugar es
//Como son 6 lugares y solo queremos saber los 5 mas concurridos, podemos deducir que i=5
template <class T>
void Heap<T>::mas_concurridos(){
	int n=1;
	
	for(int i=5; i>0; i--){
		if(data[i] == laboratorio)
    	    cout << n << " Laboratorio\n";
    	else if(data[i] == baseDatos)
    	    cout << n << " Base de datos\n";
    	else if(data[i] == cafeteria)
    	    cout << n << " Cafeteria\n";
    	else if(data[i] == almacen)
    	    cout << n << " Almacen\n";
    	else if(data[i] == jardin)
    	    cout << n << " Jardin\n";
    	else if(data[i] == observatorio)
    	    cout << n << " Observatorio\n";
    	else
    	    cout << "Error";
    	n++;
	}
	
}

template <class T>
void Heap<T>::push(T val) {
	unsigned int pos;

	pos = cont;
	cont++;
	while (pos > 0 && val < data[parent(pos)]) {
		data[pos] = data[parent(pos)];
		pos = parent(pos);
	}
	data[pos] = val;
}

template <class T>
T Heap<T>::pop() {
	T aux = data[0];

	data[0] = data[--cont];
	heapify(0);
	return aux;
}

template <class T>
int Heap<T>::size() {
	return cont;
}

template <class T>
int Heap<T>::top() {
	return data[0];
}

template <class T>
bool Heap<T>::empty() const {
	return (cont == 0);
}

template <class T>
bool Heap<T>::full() const {
	return (cont == tam);
}

template <class T>
unsigned int Heap<T>::parent(unsigned int pos) const {
	return (pos - 1) / 2;
}

template <class T>
unsigned int Heap<T>::left(unsigned int pos) const {
	return ((2 * pos) + 1);
}

template <class T>
unsigned int Heap<T>::right(unsigned int pos) const {
	return ((2 * pos) + 2);
}

template <class T>
void Heap<T>::swap(unsigned int i, unsigned int j) {
	T aux = data[i];
	data[i] = data[j];
	data[j] = aux;
}

template <class T>
void Heap<T>::heapify(unsigned int pos) {
	unsigned int le = left(pos);
	unsigned int ri = right(pos);
	unsigned int min = pos;
	
	if (le <= cont && data[le] < data[min]) {
		min = le;
	}
	if (ri <= cont && data[ri] < data[min]) {
		min = ri;
	}
	if (min != pos) {
		swap(pos, min);
		heapify(min);
	}
}

template <class T>
void Heap<T>::clear() {
	cont = 0;
}

#endif
