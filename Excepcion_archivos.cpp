#include "Excepcion_archivos.h"

const char * Excepcion_archivos::excepcion_vistas() const throw()  {
    return "\tError: El archivo vistas no se pudo abrir correctamente";
}

const char * Excepcion_archivos::excepcion_no_vistas() const throw() {
    return "\tError: El archivo no vistas no se pudo abrir correctamente. Fin del programa";
}