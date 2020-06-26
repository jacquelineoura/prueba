#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "programa.h"
#include "peliculas.h"
#include "lista.h"
#include "nodo.h"

typedef Pelicula* Dato;





int main (int argc, char *argv[])
{

   //hacer lectura de archivos


    Programa programaPrincipal(archivo);
    programaPrincipal.ejecutarProgramaPrincipal();

    Lista<Dato> lista;  // lista template
/*
    Pelicula* peliculasVistas;
    Pelicula* peliculasNoVistas ;
    Pelicula* peliculasRecomendadas;

   */
    return 0;
}
