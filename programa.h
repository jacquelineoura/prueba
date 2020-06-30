#ifndef PROGRAMA_H_
#define PROGRAMA_H_

#include <iostream>

#include "peliculas.h"

using namespace std;


template < typename Dato >
class Programa
{
private:

	Menu menu ;
	Bool estado_pelicula_vistas ;
	Lista<string> peliculas_Vistas ;
	Lista<string> peliculas_No_Vistas ;
	Lista<string> recomendados ;

public:
	Programa(string archivo_pelis_vistas, string archivo_pelis_no_vistas) ; //reveer
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
