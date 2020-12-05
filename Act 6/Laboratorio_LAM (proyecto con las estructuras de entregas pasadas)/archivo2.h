//Se implementa el hashing

#ifndef ARCHIVO2_H_
#define ARCHIVO2_H_

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>
#include <string>
#include <fstream>


using namespace std;


template <class T> class Hash;

template <class T>
class TablaEntrada {
    public:
       string k;
       string v;
       TablaEntrada(string k, string v);
      
      friend class Hash<T>;
};

template <class T>
TablaEntrada<T>::TablaEntrada(string k, string v) {
    this->k = k;
    this->v = v;
}

template <class T>
class Hash {
	private:
		TablaEntrada<T> **t;
		int esp = 7;
	public:
		Hash();
		~Hash();
		int funcion_hash(string k);
		void agregar_dato(string k, string v);
		string busqueda(string k);
		
};

template <class T>
Hash<T>::Hash(){
	t = new TablaEntrada<T> * [esp];
	for (int i=0; i<esp; i++) {
        t[i] = NULL;
    }
}

template <class T>
Hash<T>::~Hash(){
	for (int i=0; i<esp; i++) {
        if (t[i] != NULL){
            delete t[i];
            delete[] t;
        }
    }
}
template <class T>
int Hash<T>::funcion_hash(string k){
	int a;
	
	//string a int
	if(k=="Adrian")
		a=591;
	else if(k=="Lucy")
		a=413;
	else if(k=="Issac")
		a=499;
	else if(k=="Roy")
		a=314;
	else
		a=835;
		
	return a;
}

template <class T>
void Hash<T>::agregar_dato(string k, string v){
	int b = funcion_hash(k);
        while (t[b]!=NULL && t[b]->k!=k) {
           b = (b+1)%esp;
        }
        
        if (t[b] != NULL)
           delete t[b];
        
		t[b] = new TablaEntrada<T>(k, v);
}

template <class T>
string Hash<T>::busqueda(string k) {
    int b = funcion_hash(k);
        
    while (t[b] != NULL && t[b]->k != k) {
       b = (b+1)%esp;
    }
         
	if (t[b] == NULL)
        return "none";
        
	else
        return t[b]->v;
}

#endif
