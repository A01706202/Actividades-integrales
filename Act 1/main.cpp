/*---------------------------
Michelle Aylin Calzada Montes
A01706202
Actividad integral

En este proyecto lo que se hace es revisar un documento
de texto con los datos de actividad de un edificio 
científico en un día
------------------------------*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>
#include <string>
#include <fstream>
#include "archivo.h"
using namespace std;

int main(int argc, char* argv[]) {
    
    //se guarda los datos en un vector
    vector<string> separador, v;
    string linea, palabra;
    ifstream datos;
    datos.open("registro.txt", ios::in);
	while(!datos.eof()){
        getline(datos,linea);
        v.push_back(linea);      
    }
	datos.close();
	
	//Se crea otro vector pero con el dato de horas, la cual usaremos para el ordenamiento 
	//y busqueda de datos, los datos de relleno solo sirven para que los datos 
	//de la hora se acomoden a su vector
	vector<string> hora, dato_relleno1, dato_relleno2, dato_relleno3, dato_relleno4, dato_relleno5;
    for (ifstream o("registro.txt"); o;)
    {
        string n;

        if (o >> n)
            hora.push_back(n);
        if (o >> n)
            dato_relleno1.push_back(n);
        if (o >> n)
            dato_relleno2.push_back(n);
        if (o >> n)
            dato_relleno3.push_back(n);
        if (o >> n)
            dato_relleno4.push_back(n);
        if (o >> n)
            dato_relleno5.push_back(n);
    }
	

	Archivo<string> a;
	a.ordenar_datos(v,hora);
	

	string inicio, final;
	cout<<"Ingresa hora inicial (en formato '00:00'): ";
	cin>>inicio;
	cout<<"Ingresa hora final (en formato '00:00'): ";
	cin>>final;
	cout<<"\n"<<endl;
	
	//Casos de prueba
	//inicio="07:00";
	//final="10:00";
	//inicio="09:30";
	//final="11:20";	
	
	if(final<inicio){
		cout<<"Error";
	}
	
	else{
		a.buscar_datos(v, hora, inicio, final);
	}
	
}
