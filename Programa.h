#ifndef PROGRAMA_H
#define PROGRAMA_H
#include "Lista.h"
#include "Nodo.h"
#include "LeerArchivo.h"
#include "Peliculas.h"

const string MSJ_OPCION = "\n\tIngrese la opcion que desea: ";
const string MSJ_PELICULAS = "\t******** Peliculas ********  ";
const string MSJ_FIN_PROGRAMA = "Fin del programa";
const char SALIR = '0';
const char PELIS_VISTAS = '1';
const char PELIS_NO_VISTAS = '2';
const char PELIS_RECOMENDADAS = '3';
const int CONDICION_DE_PUNTAJE_MINIMO = 7;

typedef Peliculas* Dato;

class Programa{

    private:

        char opcion;
        bool esta_vistas;

    public:

        //Descripcion: Constructor del programa sin parametros
        //PRE: -
        //Post:  -
        Programa(bool esta_vistas);

        //Descripcion:
        //PRE: -
        //Post: Muestra las opciones del menu
        void mostrar_menu();

        //Descripcion:
        //PRE:
        //Post: Se ingresa por teclado una opcion del menu
        void elegir_opcion();

        //Descripcion:
        //PRE:
        //Post:
        void abrir_menu_interno(Lista<Dato> &lista_no_vistas , Lista<Dato> &lista_vistas);

        //Descripcion:
        //PRE:
        //Post:
        char obtener_opcion();

        //Descripcion: Muestra  lista completa
        //PRE: Ingresa una lista bien formada
        //Post: Muestra todos los elementos de dicha lista
        void mostrar_lista_pelicula(Lista <Dato> &lista);

        //Descripcion: Utiliza la lista de vistas y no vistas para formar recomendados.
        //PRE: Debe existir una lista de peliculas vistas y una lista de peliculas no vistas
        //Post: llena la lista de recomendados
        void llenar_recomendados(Lista<Dato> &lista_no_vistas , Lista<Dato> &lista_vistas,Lista<Dato> &lista_recomendado);

        //Descripcion: Utiliza la lista no vistas para formar recomendados.
        //PRE: Debe faltar la lista de peliculas vistas.
        //Post: Llena la lista de recomendados cuando no hay lista de peliculas vistas.
        void llenar_recomendados(Lista<Dato> &lista_no_vistas,Lista<Dato> &lista_recomendado);

        //PRE: Debe existir una lista de peliculas vistas.
        //POST: llena las listas auxiliares utilizadas para la creacion de recomendados.
        void llenar_listas_auxiliares(Lista<Dato> &lista_vistas, Lista<string> &actores, Lista<string> &directores, Lista<string> &generos);

        //PRE: Debe existir una lista de peliculas vistas.
        //POST: Devuelve si coincide el genero de la pelicula no vista con alguno de alguna pelicula vista.
        bool coincidencia_genero(int posicion, Lista<string> &generos, Lista<Dato> &lista_no_vistas);

        //PRE: Debe existir una lista de peliculas vistas.
        //POST: Devuelve si coincide el director de la pelicula no vista con alguno de alguna pelicula vista.
        bool coincidencia_director(int posicion, Lista<string> &directores, Lista<Dato> &lista_no_vistas);

        //PRE: Debe existir una lista de peliculas vistas.
        //POST: Devuelve si coincide al menos un actor de la pelicula no vista con algun actor de alguna pelivula vista.
        bool coincidencia_actor(int posicion, Lista<string> &actores, Lista<Dato> &lista_no_vistas);

        //PRE: Debe existir una lista de peliculas vistas.
        //POST: devuelve si el puntaje de la pelicula no vista supera el minimo de calidad requerida para ser recomendada
        bool puntaje_es_valido (int posicion, Lista<Dato> &lista_no_vistas);
};

#endif //TP4A_PROGRAMA_H