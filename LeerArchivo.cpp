#include "LeerArchivo.h"

const string MSJ_APERTURA_ARCHIVO= " No se pudo abrir el archivo " ;
//typedef Peliculas* Dato;

Leer_archivo:: Leer_archivo(string ruta) {


    if (existencia_de_archivo(ruta)) {
        archivo.open( ruta, ios::out );
        archivo_abierto = true;
    }
    else {
        cout << endl ;
        cout << MSJ_APERTURA_ARCHIVO ;
        archivo_abierto = false;
    }
}

Leer_archivo:: ~Leer_archivo() {
    cerrar_archivo();
}

void Leer_archivo:: cerrar_archivo() {
    archivo.close();
    archivo_abierto = false;
}

char Leer_archivo:: leer_string() {
    string s;
    archivo >> s;
    return s;

}

int Leer_archivo:: leer_int() {
    int valor;
    archivo >> valor;
    return valor;
}

bool Leer_archivo:: final_archivo() {
    return archivo.eof() ;
}

bool Leer_archivo:: estado_de_archivo() {
    return archivo_abierto ;
}

bool Leer_archivo:: existencia_de_archivo( string ruta ) {
    ifstream archivo( ruta );
    return archivo.good();
}

void Leer_archivo:: cargar_datos_lista ( Lista<Dato> &lista ) {

    if ( estado_de_archivo ) {

        string nombre_pelicula ;
        string genero ;
        string director ;
        int puntaje ;
        string actor ;
        Lista<string> actores ;

        Dato dato; // Peliculas* dato

        while ( ! final_archivo()) {

            nombre_pelicula = leer_string();
            genero = leer_string();
            puntaje = leer_int ;
            director = leer_string();
            //crea lista actores
            while ( (actor = leer_string())! ="\n" ) {  //lee hasta que encuentre un newline, cuando la encontro vuelve a leer nombre de pelicula
                    actores.insert( actor ) ;
            }

            dato = new Peliculas( nombre_pelicula, genero, puntaje, director, actores ) ;
            lista.insert( dato );

        }
        cout << "\tDatos cargados correctamente"<< endl <<endl;

    }
}
