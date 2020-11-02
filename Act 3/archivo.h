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

//Muestra datos de un rango de hora y los guarda en un archivo
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

#endif
