//
// Created by alex on 30/6/20.
//

#ifndef TP4A_PROGRAMA_H
#define TP4A_PROGRAMA_H

#include "lista.h"
#include "nodo.h"

#include "LeerArchivo.h"
#include "Peliculas.h"


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
    void programa_principal();

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


#endif //TP4A_PROGRAMA_H
