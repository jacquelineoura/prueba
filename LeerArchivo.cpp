#include "LeerArchivo.h"
#include "Peliculas.h"
#include <sstream>
#include "string.h"
const string MSJ_APERTURA_ARCHIVO= " No se pudo abrir el archivo " ;
const string MSJ_CARGA_CORRECTA= "\tDatos cargados correctamente" ;
typedef Peliculas* Dato;

LeerArchivo:: LeerArchivo(string ruta) {


    if (existencia_de_archivo(ruta)) {
        archivo.open( ruta, ios::out ) ;
        archivo_abierto = true ;
        cout<<"\tarchivo abierto"<<endl;
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

        string nombre_pelicula;
        string genero;
        string director;
        string puntaje;
        string espacio;
        string linea_actores;



        while ( ! final_archivo()) {

            string linea_actores; // No esta de mas ?
            getline(archivo, nombre_pelicula);
            getline(archivo, genero);
            getline(archivo, puntaje);
            getline(archivo, director);
            getline(archivo, linea_actores);

            stringstream s(linea_actores);
            string* nombre_actor = new string;


            Peliculas* dato = new Peliculas( nombre_pelicula, genero, atoi( puntaje.c_str()), director);

            while (s >> *nombre_actor){
              dato->asignar_actor(*nombre_actor);
            }

            lista.insertar(dato);

            getline(archivo, espacio);

            }

        cout << MSJ_CARGA_CORRECTA << endl ;


    }
}
