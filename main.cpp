#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include "lista.h"
#include "nodo.h"
#include "LeerArchivo.h"
#include "Peliculas.h"
#include "Programa.h"

using namespace std;

const string peliculaVacia = "vacia";

int main (int argc, char *argv[])
{
    Programa programa;
    string vistas, novistas;

    //poner en funcion
    switch(argc){

    		case 1: cout << "No hay ningun Archivo de peliculas vistas o no vistas"<< endl;
    			break;

    		case 2: {
                novistas= argv[1];
                vistas= peliculaVacia;
                programa.asignar_archivo_novistas(vistas);       //guardo en los atributos de la clase programa los nombres de los archivos recibidos.
                programa.asignar_archivo_vistas(peliculaVacia);
    		}  break;
    		case 3: {
    		    vistas = argv[1];
                novistas= argv[2];
                programa.asignar_archivo_vistas(vistas);
                programa.asignar_archivo_novistas(novistas);
    		}  break;
        	default: cout << "Cantidad de parametros incorrectos"<< endl;
    }

   programa.programa_principal();


    return 0;
}
