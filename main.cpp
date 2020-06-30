#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "programa.h"
#include "peliculas.h"
#include "lista.h"


//typedef Pelicula* Dato;
//me gusta la milanesa.
using namespace std;

const string peliculaVacia = "peliculaVacia.txt";
//const string archivo2 = "peliculasNoVistas.txt";
const MSJPARAMETROSINCORRECTOS= "cantidad de parametros incorrectos" ;


// .ejecutable vistas.txt
int main (int argc, char *argv[])
{
    string archivoPelisNoVistas, archivoPelisVistas ;

    //poner en funcion
    switch(argc){

    		case 1: cout << "No hay ningun Archivo de peliculas vistas o no vistas"<< endl;
    			break;

    		case 2: archivoPelisNoVistas= argv[1];
    			archivoPelisVistas= peliculaVacia;

    			 break;
    		case 3:  archivoPelisVistas = argv[1];
        		 archivoPelisNoVistas= argv[2];
        		 break;
        	default: cout << MSJPARAMETROSINCORRECTOS << endl;

    }



    Programa programaPrincipal (archivoPelisVistas, archivoPelisNoVistas);
    programaPrincipal.ejecutarProgramaPrincipal();



    return 0;
}
