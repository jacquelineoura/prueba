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
	Lista<Dato> listaPeliculas;
	
public:	
	Programa(string nombreDelArchivo);
	~Programa();
	//mas funciones	
	void ejecutarProgramaPrincipal();
	void leerArchivo();
}


void Programa::leerArchivo(){
}



void Programa::ejecutarProgramaPrincipal()
{
	leerArchivo();
	//ejecutarOpcion();
}
