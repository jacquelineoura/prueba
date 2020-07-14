#ifndef PROGRAMA_H
#define PROGRAMA_H
#include "lista.h"
#include "nodo.h"
#include "LeerArchivo.h"
#include "Peliculas.h"

const string MSJ_OPCION = "\n\tIngrese la opcion que desea: " ;
const string MSJ_PELICULAS = "\t******** Peliculas ********  " ;
const string MSJ_FIN_PROGRAMA = "Fin del programa" ;
const int SALIR = 0 ;
const int PELIS_VISTAS = 1 ;
const int PELIS_NO_VISTAS = 2 ;
const int PELIS_RECOMENDADAS = 3 ;


typedef Peliculas* Dato ;


class Programa{

    private:

        int opcion ;
        bool esta_vistas ;


    public:

        //Descripcion: Constructor del programa con parametro
        //PRE: Ingresa un booleano que me indica si existe el archivo de peliculas vistas
        //Post:  Asigna el valor en el atributo esta_vista
        Programa(bool esta_vistas) ;

        //Descripcion: Destructor
        ~Programa();

        //Descripcion:
        //PRE: -
        //Post: Muestra las opciones del menu
        void mostrar_menu() ;

        //Descripcion:
        //PRE: -
        //Post: Se ingresa por teclado una opcion del menu
        void elegir_opcion() ;

        //Descripcion: Menu interno que se encarga de ejecutar metodos segun  opcion
        //PRE: Ingresan listas bien formadas.
        //Post: maneja el programa dependiendo de la opcion  de menu elegida.
        void abrir_menu_interno(Lista<Dato> &lista_no_vistas , Lista<Dato> &lista_vistas) ;

        //Descripcion: Devuelve la opcion de menu elegida
        //PRE: -
        //Post: devuelve la opcion de menu elegida
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
        //POST: Devuelve si coincide al menos un actor de la pelicula no vista con algun actor de alguna pelicula vista.
        bool coincidencia_actor(int posicion, Lista<string> &actores, Lista<Dato> &lista_no_vistas) ;

        //PRE: Debe existir una lista de peliculas vistas.
        //POST: devuelve si el puntaje de la pelicula no vista supera el minimo de calidad requerida para ser recomendada
        bool puntaje_es_valido (int posicion, Lista<Dato> &lista_no_vistas) ;
};


#endif //TP4A_PROGRAMA_H
