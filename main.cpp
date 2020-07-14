// ARREGLO DEFINITIVO 2.0

/* Alex teper - 105301-*
/* Matias caseres- 101883-*
/* Jacqueline Oura - 87622 */


#include <iostream>
#include "Programa.h"
#include "LeerArchivo.h"
#include "Excepcion_archivos.h"

using namespace std;

const string RUTA_VISTAS = "peliculasVistasprueba.txt";
const string RUTA_NO_VISTAS = "peliculasNoVistas.txt";

int main (int argc, char *argv [] ){

    LeerArchivo archivo_pelis_vistas( RUTA_VISTAS );
    LeerArchivo archivo_pelis_no_vistas( RUTA_NO_VISTAS );
    Lista < Dato > lista_pelis_vistas;
    Lista < Dato > lista_pelis_no_vistas;
    bool esta_vistas = false;

    try{
        if ( !archivo_pelis_vistas.estado_de_archivo() )
            throw Excepcion_archivos();
        else{
            archivo_pelis_vistas.cargar_datos_lista( lista_pelis_vistas );
            esta_vistas = true;
        }
    }
    catch( Excepcion_archivos& e ){
        cout << e.excepcion_vistas() << endl;
    }

    try {
        if ( !archivo_pelis_no_vistas.estado_de_archivo() )
            throw Excepcion_archivos();

        else{

            archivo_pelis_no_vistas.cargar_datos_lista( lista_pelis_no_vistas );
            Programa programa( esta_vistas );

            do{
                programa.mostrar_menu();
                programa.elegir_opcion();
                programa.abrir_menu_interno(lista_pelis_no_vistas, lista_pelis_vistas);
            } while ( programa.obtener_opcion() != SALIR );

            for (int i = 0; i < lista_pelis_vistas.obtener_tam(); ++i) {
                delete lista_pelis_vistas.obtener_dato(i);
            }

            for (int j = 0; j < lista_pelis_no_vistas.obtener_tam(); ++j) {
                delete lista_pelis_no_vistas.obtener_dato(j);
            }
        }
    }
    catch ( Excepcion_archivos& l ){
        cout << l.excepcion_no_vistas() << endl;
    }

    return 0;
}
