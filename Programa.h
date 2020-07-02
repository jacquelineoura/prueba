#ifndef PROGRAMA_H
#define PROGRAMA_H

#include "lista.h"
#include "nodo.h"

//LOS NOMBRES D LAS LIBRERIAS DEBERIAN ESTAR TODO EN MINUSCULA BY ANDRES
#include "LeerArchivo.h"
#include "Peliculas.h"


typedef Peliculas Dato;


class Programa {

private:

    int opcion ;

public:
    //Descripcion: Constructor del programa sin parametros
    //PRE:
    //Post:  Inicializa el resto de los atributos
    Programa();

    //destructor
    ~Programa();

    //Descripcion:
    //PRE:
    //Post:
    void mostrar_menu();

    //Descripcion:
    //PRE:
    //Post:
    void elegir_opcion();

    //Descripcion:
    //PRE:
    //Post:
    void abrir_menu_interno(Lista <Dato> &lista_vistas , Lista<Dato> &lista_no_vistas) ;

    //Descripcion:
    //PRE:
    //Post:
    int obtener_opcion() ;


    //Descripcion: Muestra  lista completa
    //PRE: Ingresa una lista bien formada
    //Post: Muestra todos los elementos de dicha lista
    void mostrar_lista_pelicula(Lista <Dato> &lista);   // MAS TARDE HAGO LA IMPLEMENTACION ->JACKIE


    //Descripcion: Utiliza la lista de vistas y no vistas para formar recomendados
    //PRE:
    //Post:
    void formar_recomendados();



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
