/*-------------------
Michelle Aylin Calzada Montes
A01706202
Actividad integral 6

Aquí se implementa la estructura Shell Sort, en un programa que ordena a los empleados de las
entregas pasadas más el gerente por salario o por edades, de menor a mayor
--------------------*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include "shellsort.h"

using namespace std; 


int main(int argc, char* argv[]) 
{ 

	//se guarda los datos del archivo txt en un vector
    vector<string> separador, v;
    string linea, palabra;
    ifstream datos;
    datos.open("empleados.txt", ios::in);
	while(!datos.eof()){
        getline(datos,linea);
        v.push_back(linea);      
    }
	datos.close();
	
	//Se crea otros vector pero con los datos de nombre, salario y edad
	vector<string> nombre;
	vector<float> salario;
	vector<int> edad;
    for (ifstream o("empleados.txt"); o;)
    {
        string n;
        float s;
        int e;

        if (o >> n)
            nombre.push_back(n);
        if (o >> s)
            salario.push_back(s);
        if (o >> e)
            edad.push_back(e);
    }
    
	//Variable para elegir la opcion
    int eleccion;
    
    //Se abre un archivo para escribir los datos de ordenamiento
    ofstream resultado;
	resultado.open("ordenamiento.txt",ios::out);
        
    //Explicación del programa
    cout<<"Laboratorio LAM\n\n";
    cout<<"Aqui podras consultar la edad o salarios de los cientificos por orden ascendente, que desea revisar?"<<endl;
    cout<<"\n1) Salarios"<<endl;
    cout<<"2) Edades"<<endl;
    cout<<"Eleccion: ";
    cin>>eleccion;
    
    //Ordena el vector de datos (v) respecto al salario de forma ascendente, los imprime y los guarda en un archivo
    if(eleccion==1){
    	Shellsort<float> sal;
    	int tam=sizeof(salario)/sizeof(salario[0]);
    	sal.ordenar_datos(salario,tam,v);
    	
    	for(int i=0; i<tam; i++){
    		cout<<"\n"<<v[i];
    		resultado<<v[i];
    		resultado<<"\n";
		}	
    		
	}
	
	//Ordena el vector de datos (v) respecto alas edades de forma ascendente, los imprime y los guarda en un archivo
	else if(eleccion==2){
		Shellsort<int> ed;
    	int tam=sizeof(edad)/sizeof(edad[0]);
    	ed.ordenar_datos(edad,tam,v);
    	
    	for(int i=0; i<tam; i++){
    		cout<<"\n"<<v[i];
    		resultado<<v[i];
    		resultado<<"\n";
		}
	}
	
	//Si se eligió otra opción que no está en la lista, desplega que hay un error
	else{
		cout<<"\nError";
	}
	
	//Se cierra el archivo
	resultado.close();
} 
