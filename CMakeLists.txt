cmake_minimum_required(VERSION 3.16)
project(prueba)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(prueba
        LeerArchivo.cpp
        LeerArchivo.h
        lista.h
        main.cpp
        nodo.h
        Peliculas.cpp
        Peliculas.h
        peliculas.txt
        peliculasNoVistas.txt
        peliculasVistas.txt
        peliculaVacia.txt
        Programa.cpp
        Programa.h)
