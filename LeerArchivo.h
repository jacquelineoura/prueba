#ifndef TP4A_LEERARCHIVO_H
#define TP4A_LEERARCHIVO_H
#include <fstream>
#include "lista.h"
#include "Peliculas.h"

const string MSJ_ERROR_APERTURA = " No se pudo abrir el archivo " ;
const string MSJ_CARGA_CORRECTA = "\tDatos cargados correctamente" ;
const string MSJ_OK_APERTURA = "\tarchivo abierto" ;


typedef Peliculas* Dato ;

/* SI NO ME SALE LO DE EXEPCIONES RESTAURAR ESTO
class LeerArchivo{

    private:

        ifstream archivo;
        bool archivo_abierto;

    public:

        // PRE: ruta es un string valido
        // POST:
        LeerArchivo(string ruta);

        // PRE: El archivo se encontraba abierto
        // POST: Cierra el archivo
        ~LeerArchivo();

        // PRE: El archivo fue abierto
        // POST: Cierra el archivo
        void cerrar_archivo();

        // PRE: -
        // POST: Si el archivo esta abierto devuelve true
        bool estado_de_archivo();

        // PRE: El archivo se encontraba abierto
        // POST: si se llego al final del archivo devuelve true
        bool final_archivo();

        // PRE: ingresa string valido
        // POST: Devuelve true si el archivo existe
        bool existencia_de_archivo(string ruta);


        // PRE: La lista es v?lida

        // PRE: La lista es valida

        // POST: Carga los datos del archivo en la lista
        void cargar_datos_lista(Lista<Dato> &lista);

        // PRE: El archivo fue abierto, el dato a leer debe ser un string
        // POST: Lee un dato del archivo como string y lo devuelve
        string leer_string();

        // PRE: El archivo esta abierto, como el archivo esta bien formado, el dato a leer es un numero
        // POST: Lee un dato del archivo como int y lo devuelve
        int leer_int();
};
*/

class LeerArchivo{

private:

    ifstream archivo ;
    bool archivo_abierto ;

public:

    // PRE: ruta es un string valido
    // POST:
    LeerArchivo(string ruta) ;

    // PRE: El archivo se encontraba abierto
    // POST: Cierra el archivo
    ~LeerArchivo() ;

    // PRE: El archivo fue abierto
    // POST: Cierra el archivo
    void cerrar_archivo() ;

    // PRE: -
    // POST: Si el archivo esta abierto devuelve true
    bool estado_de_archivo() ;

    // PRE: El archivo se encontraba abierto
    // POST: si se llego al final del archivo devuelve true
    bool final_archivo() ;

    // PRE: ingresa string valido
    // POST: Devuelve true si el archivo existe
    bool existencia_de_archivo(string ruta) ;


    // PRE: La lista es v?lida

    // PRE: La lista es valida

    // POST: Carga los datos del archivo en la lista
    void cargar_datos_lista(Lista<Dato> &lista) ;

    // PRE: El archivo fue abierto, el dato a leer debe ser un string
    // POST: Lee un dato del archivo como string y lo devuelve
    string leer_string() ;

    // PRE: El archivo esta abierto, como el archivo esta bien formado, el dato a leer es un numero
    // POST: Lee un dato del archivo como int y lo devuelve
    int leer_int() ;


};

#endif
