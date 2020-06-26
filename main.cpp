#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "programa.h"
#include "peliculas.h"
#include "lista.h"


typedef Pelicula* Dato;

using namespace std;

const string archivo = "peliculas.txt";



int main (int argc, char *argv[])
{

   //hacer lectura de archivos


    Programa programaPrincipal(archivo);
    programaPrincipal.ejecutarProgramaPrincipal();

    
/*
    Pelicula* peliculasVistas;
    Pelicula* peliculasNoVistas ;
    Pelicula* peliculasRecomendadas;

   */
    return 0;
}
