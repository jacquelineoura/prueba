#include "LeerArchivo.h"
#include "Peliculas.h"
#include <sstream>
#include "string.h"

/* SI NO ME SALE LO DE EXPECIONES RESTAURAR ESTO
//cambiar este metodo
LeerArchivo::LeerArchivo(string ruta){


    if (existencia_de_archivo(ruta)){
        archivo.open(ruta, ios::out);
        archivo_abierto = true;
        cout << MSJ_OK_APERTURA <<endl;
    }
    else {
        cout << endl;
        cout << MSJ_ERROR_APERTURA;
        archivo_abierto = false;
    }
}

//cambiar este metodo
bool LeerArchivo::existencia_de_archivo(string ruta){
    ifstream archivo(ruta);
    return archivo.good();
}*/


//cambiar este metodo
LeerArchivo::LeerArchivo(string ruta){


    if (existencia_de_archivo(ruta)){
        archivo.open(ruta, ios::out);
        archivo_abierto = true;
        cout << MSJ_OK_APERTURA <<endl;
    }
    else {
        archivo_abierto = false;
    }
}

//cambiar este metodo
bool LeerArchivo::existencia_de_archivo(string ruta){
    ifstream archivo(ruta);
    return archivo.good();
}

LeerArchivo::~LeerArchivo(){
    cerrar_archivo();
}

void LeerArchivo::cerrar_archivo(){
    archivo.close();
    archivo_abierto = false;
}

string LeerArchivo::leer_string(){
    string s; //Les parece cambiar "s" por "dato a leer"?
    archivo >> s;
    return s;

}

int LeerArchivo::leer_int(){
    int valor;
    archivo >> valor;
    return valor;
}

bool LeerArchivo::final_archivo(){
    return archivo.eof();
}

bool LeerArchivo::estado_de_archivo(){
    return archivo_abierto;
}



void LeerArchivo::cargar_datos_lista(Lista<Dato> &lista){

      if (archivo_abierto){

        string nombre_pelicula;
        string genero;
        string director;
        string puntaje;
        string espacio;
        string linea_actores;



        while (!final_archivo()){

            //string linea_actores;
            getline(archivo, nombre_pelicula);
            getline(archivo, genero);
            getline(archivo, puntaje);
            getline(archivo, director);
            getline(archivo, linea_actores);

            stringstream s(linea_actores);
            string* nombre_actor = new string;


            Peliculas* dato = new Peliculas(nombre_pelicula, genero, atoi(puntaje.c_str()), director);

            while (s >> *nombre_actor){
              dato -> asignar_actor(*nombre_actor);
            }

            lista.insertar(dato);

            getline(archivo, espacio);
            }

        cout << MSJ_CARGA_CORRECTA << endl;
    }
}
