#include <iostream>
#include "Programa.h"
#include "LeerArchivo.h"
#include "Excepcion_archivos.h"

using namespace std ;

const string MSJ_ARCHIVOS_INEXISTENTES = "No hay ningun Archivo de peliculas vistas o no vistas" ;
const string ruta_vistas = "peliculasVistasprueba.txt" ;
const string ruta_no_vistas = "peliculasNoVistas.txt" ;


int main (int argc, char *argv [] ){

    LeerArchivo archivo_pelis_vistas( ruta_vistas ) ;
    LeerArchivo archivo_pelis_no_vistas( ruta_no_vistas ) ;
    Lista < Dato > lista_pelis_vistas ;
    Lista < Dato > lista_pelis_no_vistas ;
    bool esta_vistas = false ;

    try{
        if ( !archivo_pelis_vistas.estado_de_archivo() )
            throw Excepcion_archivos() ;
        else{
            archivo_pelis_vistas.cargar_datos_lista( lista_pelis_vistas ) ;
            esta_vistas = true ;
        }
    }
    catch( Excepcion_archivos& e ){
        cout << e.excepcion_vistas() << endl ;
    }


    try {
        if ( !archivo_pelis_no_vistas.estado_de_archivo() )
            throw Excepcion_archivos() ;
        else{
            archivo_pelis_no_vistas.cargar_datos_lista( lista_pelis_no_vistas ) ;
            Programa programa( esta_vistas ) ;
            do{
                programa.mostrar_menu() ;
                programa.elegir_opcion() ;
                programa.abrir_menu_interno(lista_pelis_no_vistas, lista_pelis_vistas) ;
            }while ( programa.obtener_opcion() != SALIR ) ;
        }
    }
    catch ( Excepcion_archivos& l ){
        cout << l.excepcion_no_vistas() << endl ;
    }

    return 0 ;
}
