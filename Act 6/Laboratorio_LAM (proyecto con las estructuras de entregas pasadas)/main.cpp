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
#include <fstream>
#include <algorithm>
#include "archivo.h"
#include "archivo2.h"
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
	int opcion, eleccion;
	string inicio, final;
	
	//Texto que explica al usuario de que va el programa
	cout<<"Registro de un dia de LAM\n"<<endl;
	cout<<"Bienvenid@ a la base de datos del edificio de investigaciones cientificas LAM, a continuacion podras ver el registro"<<endl;
	cout<<"del dia 01-oct, ¿que le gustaria revisar? \n\n"<<endl;
	
	//Se elige si quiere ver registros de actividad o lugares concurridos
	cout<<"1) Registros de actividad"<<endl;
	cout<<"2) Lugares concurridos"<<endl;
	cout<<"3) Buscar ID de trabajador"<<endl;
	cout<<"Eleccion: ";
	cin>>eleccion;
	
	if(eleccion == 1){
		
		//Se elige si se quiere trabajar con los datos de horas o de id
		cout<<"\n1) Hora"<<endl;
		cout<<"2) ID"<<endl;
		cout<<"Opcion: ";
		cin>>opcion;
	
		cout<<"\n\nPerfecto!, ahora elija el rango que desea ver\n"<<endl;
	
		//Trabajo de los datos de horas
		if(opcion==1){
	    
	    	//Se da el rango de búsqueda
		    cout<<"Ingresa hora inicial (en formato '00:00' y de 24hr): ";
		    cin>>inicio;
		    cout<<"Ingresa hora final (en formato '00:00' y de 24hr): ";
		    cin>>final;
		    cout<<"\n"<<endl;
	    
		    //Se verifica si el inicio no es mayor que el final
			if(inicio>final)
			    cout<<"error";
		    
			else{
				//Ordena los datos de la hora más temprana a la más tarde
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
	    
		    //Se da el rango de búsqueda
		    cout<<"Ingresa ID inicial (numero entre 100-1000): ";
		    cin>>inicio;
		    cout<<"Ingresa ID final (numero entre 100-1000): ";
		    cin>>final;
		    cout<<"\n"<<endl;
	    
		    //Se verifica si el inicio no es mayor que el final
			if(inicio>final)
			    cout<<"error";
		    
			else{
				//Ordena los datos del ID más bajo al más alto
				b.ordenar_datos(v,ID); 
				//Busca los datos del rango dado
			    b.buscar_datos(v, ID, inicio, final); 
			}
		}
	
		//Si la opcion no es horas ni ID, regresa que la opcion dada es inválida
		else{
			cout<<"Opcion invalida";
		}
	}
	
	else if(eleccion==2){
		//Se abre un árbol heap para los lugares
		Heap<int> heap(6);
	
		//Se agregan los datos al árbol
		heap.agregar_dato(lugar);
	
		//Muestra los 5 lugares más concurridos
		cout << "\n\n\nLos 5 lugares mas concurridos del dia: \n\n";
		heap.mas_concurridos();

	}
	
	else if(eleccion==3){
		//Se quitan los datos repetidos de los vectores nombre y ID
		vector<string>::iterator nombres;
		vector<string>::iterator IDs;
		nombres=std::unique(nombre.begin(), nombre.end());
		IDs=std::unique(ID.begin(), ID.end());
		nombre.resize(std::distance(nombre.begin(), nombres));
		ID.resize(std::distance(ID.begin(), IDs)); 
		
		//Crea la tabla Hash
		Hash<string> hash;
		
		//Variable para saber de que empleado se quiere saber el ID
		string empleado;

		//Se llena la tabla con los datos de nombres, que son las llaves, y IDs, que son los valores de las llaves
		for (int i=0; i<5; i++) {
		    hash.agregar_dato(nombre[i], ID[i]);
        } 
        
        //Muestra la lista de empleados del cual se puede elegir
        cout<<"\n-Adrian"<<endl;
        cout<<"-Lucy"<<endl;
        cout<<"-Issac"<<endl;
        cout<<"-Roy"<<endl;
        cout<<"-Lyudmina"<<endl;
		cout<<"De quien quieres saber su ID? (Escriba el nombre): ";
		cin>>empleado;
		
		//Busca el Id del empleado elegido y lo muestra
		cout<<"\nID: "<<hash.busqueda(empleado);
	}
	
	//Si no se pone el número de eleccion disponible, aparecerá que hay un error
	else
	    cout << "\n\nError";
}
