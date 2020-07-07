
#ifndef PELICULAS_H
#define PELICULAS_H

#include <string>

#include <iostream>

#include "lista.h"


class Peliculas {

    private:
        string nombre;
        string genero;
        int puntaje;
        string director;
        Lista<string>* actores;

    public:

        //Descripcion: Constructor sin parametros
        //PRE: -
        //Post: Construye un objeto pelicula y le asigna a los atributos null.
        Peliculas();

        ~Peliculas();

        //Descripcion: Constructor
        //PRE: -
        //Post: Construye un objeto pelicula y le asigna a los atributos los valores leidos.
     //   Peliculas(string nombre_pelicula_out ,string genero_out , int puntaje_out ,string director_out , Lista <string>& actores_out);
        Peliculas(string nombre_pelicula_out ,string genero_out , int puntaje_out ,string director_out);

        void mostrar_peliculas();

        void asignar_actor(string nombre_actor);

        void lista_recomendados();  //HACER
};

        //--------------------SETTERS Y GETTES------------------
        //Descripcion: devuelve el atributo nombre
        //PRE:
        //POST: devuelve el atributo nombre
      //  string obtener_nombre();


        //Descripcion: asigna el nombre
        //PRE: recibe un string
        //POST: guarda en el atributo nombrePelicula el string recibido.
      //  void asignar_nombre(string nombre_out);


        //Descripcion: devuelve el atributo genero
        //PRE:
        //POST: devuelve el atributo nombre
        string obtener_genero();


        //Descripcion: asigna el genero
        //PRE: recibe un string
        //POST: guarda en el atributo genero el string recibido.
     //   void asignar_genero(string genero_out);

        //Descripcion: devuelve el atributo director
        //PRE:
        //POST: devuelve el atributo director
        string obtener_director();


        //Descripcion: asigna el director
        //PRE: recibe un string
        //POST: guarda en el atributo director el string recibido.
     //   void asignar_director(string director_out);


        //Descripcion: devuelve el atributo puntaje
        //PRE:
        //POST: devuelve el atributo puntaje
        int obtener_puntaje();

        //Descripcion: asigna el puntaje.
        //PRE: puntaje mayor a 0.
        //POST:guarda en el atributo puntaje el valor recibido.
     //   void asignar_puntaje(int puntaje_out);


        //REVISAAR
        //Descripcion: Muestra una unica pelicula
        //PRE: creada la pelicula
        //POST: muestra por pantalla
        //void mostrar_pelicula();









    //-------DUDOSO----- REPASAR-----REVISAR-------HACER

    //Descripcion: devuelve el atributo actores
    //PRE:
    //POST: devuelve el atributo actores
    // Lista<string> obtenerActores();


    //Descripcion: asigna la lista de actores.
    //PRE:
    //POST: guarda en el atributo actores la lista de actores.
    //void asignarActores(Lista<string> actoresOut);







#endif //TP4A_PELICULAS_H
