#include <iostream>
#include "Programa.h"
#include "LeerArchivo.h"
#include "Excepcion_archivos.h"

using namespace std;

const string peliculaVacia = "vacia";
const string MSJ_ARCHIVOS_INEXISTENTES = "No hay ningun Archivo de peliculas vistas o no vistas";

const string ruta_vistas = "peliculasVistasprueba.txt";
const string ruta_no_vistas = "peliculasNoVistas.txt";


int main (int argc, char *argv[]){

    LeerArchivo archivo_pelis_vistas(ruta_vistas);
    LeerArchivo archivo_pelis_no_vistas(ruta_no_vistas);
    Lista<Dato> lista_pelis_vistas;
    Lista<Dato> lista_pelis_no_vistas;
    bool esta_vistas=false;

    try {
        if (!archivo_pelis_vistas.estado_de_archivo())
            throw Excepcion_archivos();
        else{
            archivo_pelis_vistas.cargar_datos_lista(lista_pelis_vistas);
            esta_vistas = true;
        }
    }
    catch(Excepcion_archivos& e){
        cout << e.excepcion_vistas() << endl;
    }

    try {
        if (!archivo_pelis_no_vistas.estado_de_archivo())
            throw Excepcion_archivos();
        else{
            archivo_pelis_no_vistas.cargar_datos_lista(lista_pelis_no_vistas);
            Programa programa(esta_vistas);
            do {
                programa.mostrar_menu();
                programa.elegir_opcion();
                programa.abrir_menu_interno(lista_pelis_no_vistas, lista_pelis_vistas);
            } while (programa.obtener_opcion() != SALIR);
        }
    }
    catch(Excepcion_archivos& l) {
        cout << l.excepcion_no_vistas() << endl;
    }

    return 0;
}

/*
int main (int argc, char *argv[]){

    LeerArchivo archivo_pelis_vistas(ruta_vistas);
    Lista<Dato> lista_pelis_vistas;
    archivo_pelis_vistas.cargar_datos_lista(lista_pelis_vistas);

    LeerArchivo archivo_pelis_no_vistas(ruta_no_vistas);
    Lista<Dato> lista_pelis_no_vistas;
    archivo_pelis_no_vistas.cargar_datos_lista(lista_pelis_no_vistas);

    if (archivo_pelis_no_vistas.estado_de_archivo()){
        Programa programa;
        do {
            programa.mostrar_menu();
            programa.elegir_opcion();
            programa.abrir_menu_interno(lista_pelis_no_vistas, lista_pelis_vistas);
        } while (programa.obtener_opcion() != SALIR);
    }


    return 0;
}*/














/* ARGC ARGV
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

              //  programa.asignar_archivo_vistas(vistas);
             //   programa.asignar_archivo_novistas(novistas);
    		}  break;
        	default: cout << "Cantidad de parametros incorrectos"<< endl;
                      return 1;  //sale del programa
    }
*/


