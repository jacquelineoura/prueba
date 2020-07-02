#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include "lista.h"
#include "nodo.h"
#include "LeerArchivo.h"
#include "Peliculas.h"
#include "Programa.h"

using namespace std;

const string peliculaVacia = "vacia";
const string MSJ_ARCHIVOS_INEXISTENTES ="No hay ningun Archivo de peliculas vistas o no vistas" ;

int main (int argc, char *argv[])
{
    Programa programa;
    string vistas, novistas;

    //poner en funcion
    switch(argc){

    		case 1: cout << MSJ_ARCHIVOS_INEXISTENTES << endl;   //sale del programa
                    return 1;


    		case 2: {
                     novistas= argv[1];
                     vistas= peliculaVacia;
               // programa.asignar_archivo_novistas(vistas);
              //  programa.asignar_archivo_vistas(peliculaVacia);
    		       }  break;

    		case 3: {
                    vistas = argv[1];
                    novistas= argv[2];

                    // hace las lecturas de pelis  vistas y crea carga lista
                   LeerArchivo archivo_pelis_vistas ( vistas)  ;  // vistas o  arch_pelis_vistas
                   Lista<Dato> lista_pelis_vistas ;
                   arch_pelis_vistas.cargar_datos_lista (lista_pelis_vistas) ;

              //  programa.asignar_archivo_vistas(vistas);
             //   programa.asignar_archivo_novistas(novistas);
    		}  break;
        	default: cout << "Cantidad de parametros incorrectos"<< endl;
                      return 1;  //sale del programa
    }


   LeerArchivo archivo_pelis_no_vistas ( novistas)  ; // novistas o arch_pelis_no_vistas
   Lista<Dato> lista_pelis_no_vistas ;
   arch_pelis_no_vistas.cargar_datos_lista (lista_pelis_no_vistas) ;





    if ( // CONDICION DE QUE SI ARCHIV PELIS EL ESTADO DEL ARCHIVO ES TRUE Y DEL NO VISTAS TMB ENTONCES (si ambos archivos estan abiertos ) {
        Programa programa;
        do {
            programa.mostrar_menu();  //muestra oopciones de menu
            programa.elegir_opcion(); // elije y valida rango de oopciones del menu
            programa.abrir_menu_interno(lista_pelis_no_vistas, lista_pelis_vistas);  //contiene los switch de opciones
        } while (programa.obtener_opcion() != SALIR);   //salir 0
    }


    return 0;
}
