/*---------------------------
Michelle Aylin Calzada Montes
A01706202
Actividad integral

En este proyecto lo que se hace es revisar un documento
de texto con los datos de actividad de un edificio 
cient�fico en un d�a
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
	
    //Variables que utilizaremos para el programa
	Archivo<string> b;
	int opcion;
	string inicio, final;
	
	//Texto que explica al usuario de que va el programa
	cout<<"Registro de un dia de LAM\n"<<endl;
	cout<<"Bienvenid@ a la base de datos del edificio de investigaciones cient�ficas LAM, a continuaci�n podr�s ver el registro"<<endl;
	cout<<"de actividad del dia 01-oct de las 7:00 a Por favor elija la opcion de orden en la cual quiera visualizar los datos:\n"<<endl;
	
	//Se elige si se quiere trabajar con los datos de horas o de id
	cout<<"1) Hora"<<endl;
	cout<<"2) ID"<<endl;
	cout<<"Opcion: ";
	cin>>opcion;
	
	cout<<"\n\nPerfecto!, ahora elija el rango que desea ver\n"<<endl;
	
	//Trabajo de los datos de horas
	if(opcion==1){
		//Casos de prueba
     	//inicio="07:00";
	    //final="10:00";
	    //inicio="09:30";
	    //final="11:20";
	    
	    //Se da el rango de b�squeda
	    cout<<"Ingresa hora inicial (en formato '00:00' y de 24hr): ";
	    cin>>inicio;
	    cout<<"Ingresa hora final (en formato '00:00' y de 24hr): ";
	    cin>>final;
	    cout<<"\n"<<endl;
	    
	    //Se verifica si el inicio no es mayor que el final
		if(inicio>final)
		    cout<<"error";
		    
		else{
			//Ordena los datos de la hora m�s temprana a la m�s tarde
		    b.ordenar_datos(v,hora); 
		    //Busca los datos del rango dado
		    b.buscar_datos(v, hora, inicio, final);
		}
	}

    //Trabajo de los datos del ID
	else if(opcion==2){
		//Casos de prueba
     	//inicio="465";
	    //final="906";
	    //inicio="300";
	    //final="555";
	    
	    //Se da el rango de b�squeda
	    cout<<"Ingresa ID inicial (numero entre 100-1000): ";
	    cin>>inicio;
	    cout<<"Ingresa ID final (numero entre 100-1000): ";
	    cin>>final;
	    cout<<"\n"<<endl;
	    
	    //Se verifica si el inicio no es mayor que el final
		if(inicio>final)
		    cout<<"error";
		    
		else{
			//Ordena los datos del ID m�s bajo al m�s alto
			b.ordenar_datos(v,ID); 
			//Busca los datos del rango dado
		    b.buscar_datos(v, ID, inicio, final); 
		}
	}
	
	//Si la opcion no es horas ni ID, regresa que la opcion dada es inv�lida
	else{
		cout<<"Opcion invalida";
	}

}
