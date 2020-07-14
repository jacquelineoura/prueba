#ifndef TP4AAAA_EXCEPCION_ARCHIVOS_H
#define TP4AAAA_EXCEPCION_ARCHIVOS_H

#include <cstdlib>
#include <exception>

using namespace std;

class Excepcion_archivos: public exception{

    public:
        const char* excepcion_vistas() const throw() ;
        const char* excepcion_no_vistas() const throw() ;

        void asignar_cant_archivos(int cantidad_archivos_out) ;

        int obtener_cantidad_Archivos() ;

    private:
        int motivo ;
};

#endif //TP4AAAA_EXCEPCION_ARCHIVOS_H