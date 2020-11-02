/*------------------
Acomodo de datos en BST
------------------*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>
#include <string>
#include <fstream>
#include "archivo.h"
#include "bst.h"
using namespace std;

int main(int argc, char* argv[]) {
    
    //se guarda los datos del archivo txt en un vector
    vector<string> separador, v;
    string linea, palabra;
    ifstream datos;
    datos.open("registro.txt", ios::in);
	while(!datos.eof()){
        getline(datos,linea);
        v.push_back(linea);      
    }
	datos.close();
	
	//Se crea otros vector pero con el dato de horas, nombre, id y lugar, la cuales usaremos para los ordenamientos
	//y busqueda de datos, los datos de relleno solo sirven para que los otros datos se acomoden en su vector
	vector<string> hora, nombre, ID, dato_relleno1, dato_relleno2, lugar;
    for (ifstream o("registro.txt"); o;)
    {
        string n;

        if (o >> n)
            hora.push_back(n);
        if (o >> n)
            nombre.push_back(n);
        if (o >> n)
            ID.push_back(n);
        if (o >> n)
            dato_relleno1.push_back(n);
        if (o >> n)
            dato_relleno2.push_back(n);
        if (o >> n)
            lugar.push_back(n);
    }
    
    //Variables que guardan cuantas veces se uso cada lugar
    int laboratorio=0; 
	int baseDatos=0;
	int cafeteria=0;
	int jardin=0; 
	int observatorio=0;
	int almacen=0;
    
    //Guarda en cada variable cuantas veces se uso cada lugar
    for(int i = 0; i <= lugar.size(); i++){
    	if(lugar[i] == "laboratorio")
    	    laboratorio += 1;
    	if(lugar[i] == "base_de_datos")
    	    baseDatos += 1;
    	if(lugar[i] == "cafeteria")
    	    cafeteria += 1;
    	if(lugar[i] == "jardin")
    		jardin += 1;
    	if(lugar[i] == "observatorio")
    		observatorio += 1;
    	if(lugar[i] == "almacen")
		  	almacen += 1;
	}
		
    //Objeto de la clase bst
	BST<int> bst;
	
	//Se agregan los datos al árbol
	bst.add(laboratorio);
	bst.add(baseDatos);	
	bst.add(cafeteria);
	bst.add(jardin);
	bst.add(observatorio);
	bst.add(almacen);
}
