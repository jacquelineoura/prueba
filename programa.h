#ifndef PROGRAMA_H_
#define PROGRAMA_H_

#include <iostream>

#include "peliculas.h"

using namespace std;


template < typename Dato >
class Programa
{
private:

	string nombreArchivo;
	Lista<string> peliculasVistas;
	Lista<string> peliculasNoVistas;
	Lista<string> recomendados; 
	
public:	
	Programa(string archivoPelisVistas, string archivoPelisNoVistas) ;
	~Programa();
	//mas funciones	
	void ejecutarProgramaPrincipal();
	void leerArchivo(); 
	void ejecutarOpcion(); //menu
}


void Programa::leerArchivo(){
}



void Programa::ejecutarProgramaPrincipal()
{
	leerArchivo();
	ejecutarOpcion();
}
