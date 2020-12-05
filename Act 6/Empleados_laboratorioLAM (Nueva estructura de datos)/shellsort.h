#ifndef SHELLSORT_H_
#define SHELLSORT_H_

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>

using namespace std;

template <class T>
class Shellsort{
	public:
		void ordenar_datos(vector<T> &b, int tam, vector<string> &a);
};

template <class T>
void Shellsort<T>::ordenar_datos(vector<T> &b, int tam, vector<string> &a){
	
	//Empieza con un tamaño de espacios grandes y cuando más se repite el ciclo, va disminuyendo
	for (int gap=tam/2; gap>0; gap/=2) 
    { 
	//Hace una Insert Sort con espacios para el tamaño de espacios (tam) donde a[0...gap-1] ya están 
	//orden de espacios y sigue añadiendo alementos hasta que el vector esté ordenado por espacios
        for (int i=gap; i<tam; i+=1) 
        { 
		//Agrega b[i] y a[i] a los elementos que se ordenaron por espacios, lo salvan en
		//temp y temp2 respectivamente y hace un nuevo espacio en la posición i
		//temp para la primera lista numérica y tem2 para la segunda lista string
            int temp = b[i];
            string temp2= a[i];
            int j;   
		
		//Desplaza los elementos ordenados anteriormente por espacios hasta que se encuentre 
		//la ubicación correcta de b[i] y también el de a[i] 
            for (j=i; j >= gap&&b[j-gap] > temp; j -= gap){
            	b[j] = b[j-gap]; 
            	a[j]=a[j-gap];
			} 
            //pone temp y temp 2 en su posición correcta    
            b[j]=temp; 
            a[j]=temp2;			 
        } 
    }
}

#endif
