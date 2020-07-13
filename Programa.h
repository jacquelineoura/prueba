#ifndef PROGRAMA_H
#define PROGRAMA_H
#include "lista.h"
#include "nodo.h"

//LOS NOMBRES D LAS LIBRERIAS DEBERIAN ESTAR TODO EN MINUSCULA BY ANDRES
#include "LeerArchivo.h"
#include "Peliculas.h"

const string MSJ_OPCION = "\n\tIngrese la opcion que desea: " ;
const string MSJ_PELICULAS = "\t******** Peliculas ********  " ;
const string MSJ_FIN_PROGRAMA = "Fin del programa" ;
const int SALIR = 0 ;
const int PELIS_VISTAS = 1 ;
const int PELIS_NO_VISTAS = 2 ;
const int PELIS_RECOMENDADAS = 3 ;
const int CONDICION_DE_PUNTAJE_MINIMO = 7 ;

typedef Peliculas* Dato ;


class Programa{

    private:

        int opcion ;
        bool esta_vistas ;


    public:

        //Descripcion: Constructor del programa sin parametros
        //PRE: -
        //Post:  -
        Programa(bool esta_vistas) ;

        //destructor
        //~Programa();

        //Descripcion:
        //PRE: -
        //Post: Muestra las opciones del menu
        void mostrar_menu() ;

        //Descripcion:
        //PRE:
        //Post: Se ingresa por teclado una opcion del menu
        void elegir_opcion() ;

        //Descripcion:
        //PRE:
        //Post:
        void abrir_menu_interno(Lista<Dato> &lista_no_vistas , Lista<Dato> &lista_vistas) ;

        //Descripcion:
        //PRE:
        //Post:
        int obtener_opcion() ;

        //Descripcion: Muestra  lista completa
        //PRE: Ingresa una lista bien formada
        //Post: Muestra todos los elementos de dicha lista
        void mostrar_lista_pelicula(Lista <Dato> &lista) ;

        //Descripcion: Utiliza la lista de vistas y no vistas para formar recomendados.
        //PRE: Debe existir una lista de peliculas vistas y una lista de peliculas no vistas
        //Post: llena la lista de recomendados
        void llenar_recomendados(Lista<Dato> &lista_no_vistas , Lista<Dato> &lista_vistas,Lista<Dato> &lista_recomendado) ;

        //Descripcion: Utiliza la lista no vistas para formar recomendados.
        //PRE: Debe faltar la lista de peliculas vistas.
        //Post: Llena la lista de recomendados cuando no hay lista de peliculas vistas.
        void llenar_recomendados(Lista<Dato> &lista_no_vistas,Lista<Dato> &lista_recomendado) ;

        //PRE: Debe existir una lista de peliculas vistas.
        //POST: llena las listas auxiliares utilizadas para la creacion de recomendados.
        void llenar_listas_auxiliares(Lista<Dato> &lista_vistas, Lista<string> &actores, Lista<string> &directores, Lista<string> &generos) ;

        //PRE: Debe existir una lista de peliculas vistas.
        //POST: Devuelve si coincide el genero de la pelicula no vista con alguno de alguna pelicula vista.
        bool coincidencia_genero(int posicion, Lista<string> &generos, Lista<Dato> &lista_no_vistas) ;

        //PRE: Debe existir una lista de peliculas vistas.
        //POST: Devuelve si coincide el director de la pelicula no vista con alguno de alguna pelicula vista.
        bool coincidencia_director(int posicion, Lista<string> &directores, Lista<Dato> &lista_no_vistas) ;

        //PRE: Debe existir una lista de peliculas vistas.
        //POST: Devuelve si coincide al menos un actor de la pelicula no vista con algun actor de alguna pelivula vista.
        bool coincidencia_actor(int posicion, Lista<string> &actores, Lista<Dato> &lista_no_vistas) ;

        //PRE: Debe existir una lista de peliculas vistas.
        //POST: devuelve si el puntaje de la pelicula no vista supera el minimo de calidad requerida para ser recomendada
        bool puntaje_es_valido (int posicion, Lista<Dato> &lista_no_vistas) ;
};


/*
class Programa {

private:
    LeerArchivo leer_archivo;
    Lista<Peliculas> vistas;
    Lista<Peliculas> novistas;
    string archivo_vistas; //este mismo va a actuar como el booleano, al pedo tener dos cosas.
    string archivo_novistas;

public:
    //Descripcion: Constructor del programa sin parametros
    //PRE:
    //Post:  Inicializa el resto de los atributos
    Programa();

    //--------------------HACE FALTA?----------- Digame el resto del grupo, depende de la implementacion
    //Descripcion: Constructor del programa con parametros
    //PRE:
    //Post:
    //------------------------------------------

    //Descripcion: El "Falso main" encargado de ejecutar todo el programa
    //PRE:
    //Post:
   // void programa_principal();     // COPIASTE MAL DEL MAIN , PROGRAMAPRINCIPAL ES EL OBJETO DE LA CLASE PROGRAMA NO METODO

    //----------Setters y Getters-------

    //Descripcion: asigna archivo_vistas
    //PRE:
    //Post: guarda en el atributo archivo_vistas el valor recibido
    void asignar_archivo_vistas(string archivo_vistas_out);


    //Descripcion: devuelve el atributo archivo_vistas
    //PRE:
    //Post: devuelve el atributo archivo_vistas
    string obtener_archivo_vistas();


    //Descripcion: asigna archivo_vistas
    //PRE:
    //Post: guarda en el atributo archivo_vistas el valor recibido
    void asignar_archivo_novistas(string archivo_novistas_out);


    //Descripcion: devuelve el atributo archivo_vistas
    //PRE:
    //Post: devuelve el atributo archivo_vistas
    string obtener_archivo_novistas();



    //Descripcion: muestra la lista entera (la que le pidas, vista o no vista)
    //PRE:
    //Post:
    void mostrar_lista_pelicula(int auxiliar);


    //Descripcion:Utiliza la lista de vistas y no vistas para formar recomendados
    //PRE:
    //Post:
    void formar_recomendados();

    //Descripcion:
    //PRE:
    //Post:

};
*/

#endif //TP4A_PROGRAMA_H
