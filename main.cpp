#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "programa.h"

typedef Pelicula* tipo;

int main (int argc, char *argv[])
{

   //hacer lectura de archivos


    Programa programaPrincipal(archivo);
    programaPrincipal.ejecutarProgramaPrincipal();

    Lista<tipo> lista;  // lista template
/*
    Pelicula* peliculasVistas;
    Pelicula* peliculasNoVistas ;
    Pelicula* peliculasRecomendadas;

   */
    return 0;
}
