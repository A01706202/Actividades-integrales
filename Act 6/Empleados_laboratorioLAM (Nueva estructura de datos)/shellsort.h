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
	
	for (int gap=tam/2; gap>0; gap/=2) 
    { 
        for (int i=gap; i<tam; i+=1) 
        { 
            int temp = b[i];
            string temp2= a[i];
            int j;   
			          
            for (j=i; j >= gap&&b[j-gap] > temp; j -= gap){
            	b[j] = b[j-gap]; 
            	a[j]=a[j-gap];
			} 
                
            b[j]=temp; 
            a[j]=temp2;			 
        } 
    }
}

#endif
