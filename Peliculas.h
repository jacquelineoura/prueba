#ifndef PELICULAS_H
#define PELICULAS_H
#include <string>
#include <iostream>
#include "lista.h"

class Peliculas{

    private:

        string nombre ;
        string genero ;
        int puntaje ;
        string director ;
        Lista < string >* actores ;


    public:

        //Descripcion: Constructor sin parametros
        //PRE: -
        //Post: Construye un objeto pelicula y le asigna a los atributos null.
        Peliculas() ;

        ~Peliculas();

        //Descripcion: Constructor
        //PRE: El puntaje debe ser 0 <= && >= 10
        //Post: Construye un objeto pelicula y le asigna a los atributos los valores leidos.
        Peliculas(string nombre_pelicula_out ,string genero_out , int puntaje_out ,string director_out) ;

        //Descripcion: muestra datos de la pelicula
        //PRE: -
        //Post: Muestra nombre, genero, puntaje, director y lista de actores de la pelicula
        void mostrar_peliculas() ;

        //Descripcion: muestra datos de la pelicula
        //PRE: ingresa dato bien formado del nombre del actor
        //Post: le agrega a la lista de actores ,el nombre del actor
        void asignar_actor(string nombre_actor) ;




        //--------------------SETTERS Y GETTES------------------

        //Descripcion: devuelve el atributo nombre
        //PRE: -
        //POST: devuelve el atributo nombre
        string obtener_nombre() ;


        //Descripcion: asigna el nombre
        //PRE: -
        //POST: guarda en el atributo nombrePelicula el string recibido.
        void asignar_nombre(string nombre_out) ;


        //Descripcion: devuelve el atributo genero
        //PRE: -
        //POST: devuelve el atributo nombre
        string obtener_genero() ;


        //Descripcion: asigna el genero
        //PRE: -
        //POST: guarda en el atributo genero el string recibido.
        void asignar_genero(string genero_out) ;

        //Descripcion: devuelve el atributo director
        //PRE: -
        //POST: devuelve el atributo director
        string obtener_director() ;


        //Descripcion: asigna el director
        //PRE: -
        //POST: guarda en el atributo director el string recibido.
        void asignar_director(string director_out) ;


        //Descripcion: devuelve el atributo puntaje
        //PRE: -
        //POST: devuelve el atributo puntaje
        int obtener_puntaje() ;

        //Descripcion: asigna el puntaje.
        //PRE: puntaje mayor a 0.
        //POST:guarda en el atributo puntaje el valor recibido.
        void asignar_puntaje(int puntaje_out) ;

        //Descripcion: devuelve el atributo actores
        //PRE: i debe ser < 0.
        //POST: devuelve el atributo actores
        string obtener_actores(int i) ;

        //PRE: -
        //POST: devuelve la cantidad de actores.
        int obtener_cantidad_actores() ;
};

#endif //TP4A_PELICULAS_H
