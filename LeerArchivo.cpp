#include "LeerArchivo.h"
#include "Peliculas.h"

#include "string.h"
const string MSJ_APERTURA_ARCHIVO= " No se pudo abrir el archivo " ;
const string MSJ_CARGA_CORRECTA= "\tDatos cargados correctamente" ;
typedef Peliculas* Dato;

LeerArchivo:: LeerArchivo(string ruta) {


    if (existencia_de_archivo(ruta)) {
        archivo.open( ruta, ios::out ) ;
        archivo_abierto = true ;
        cout<<"archivo abierto"<<endl;
    }
    else {
        cout << endl ;
        cout << MSJ_APERTURA_ARCHIVO ;
        archivo_abierto = false;

    }
}

LeerArchivo:: ~LeerArchivo() {
    cerrar_archivo() ;
}

void LeerArchivo:: cerrar_archivo() {
    archivo.close() ;
    archivo_abierto = false ;
}

string LeerArchivo:: leer_string() {
    string s ;
    archivo >> s ;
    return s ;

}

int LeerArchivo:: leer_int() {
    int valor;
    archivo >> valor;
    return valor;
}

bool LeerArchivo:: final_archivo() {
    return archivo.eof() ;
}

bool LeerArchivo:: estado_de_archivo() {
    return archivo_abierto ;
}

bool LeerArchivo:: existencia_de_archivo( string ruta ) {
    ifstream archivo( ruta );
    return archivo.good();
}

void LeerArchivo:: cargar_datos_lista ( Lista<Dato> &lista ) {

      if (archivo_abierto) {

        string nombre_pelicula ;
        string genero ;
        string director ;
        string puntaje ;
        string nombre_actor;
        string espacio;

        Lista<string> lista_actores ;

        //Dato dato; // Peliculas dato

        while ( ! final_archivo()) {

            getline(archivo, nombre_pelicula);
            getline(archivo, genero);
            getline(archivo, puntaje);
            getline(archivo, director);
            getline(archivo, nombre_actor);
            getline(archivo, espacio);

            cout<<nombre_pelicula<<endl;
            cout<<genero<<endl;
            cout<<puntaje<<endl;
            cout<<director<<endl;
            cout<<nombre_actor<<endl;

           /* while ( archivo>> nombre_actor )
            {   cout<<nombre_actor<<endl;
               // lista_actores.insertar(nombre_actor);
            };
*/
          Peliculas* dato = new Peliculas( nombre_pelicula, genero, atoi( puntaje.c_str()), director ) ;  //saque lista de actores para hacer checkeos
           lista.insertar(dato);
            }

        cout << MSJ_CARGA_CORRECTA << endl <<endl;


    }
}
