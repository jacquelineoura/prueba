//
// Created by alex on 12/7/20.
//

#include "Excepcion_archivos.h"



//que tenga para vistas y no vistas un mensaje diferente
const char * Excepcion_archivos::excepcion_vistas() const throw()  {
    return "Error: El archivo vistas no se pudo abrir correctamente" ;
}

const char * Excepcion_archivos::excepcion_no_vistas() const throw() {
    return "Error: El archivo no vistas no se pudo abrir correctamente. Fin del programa" ;
}
