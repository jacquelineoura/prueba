//
// Created by alex on 30/6/20.
//

#include "Peliculas.h"

Peliculas::Peliculas() {
    nombre = " ";
    genero = " ";
    puntaje = 0;
    director = " ";
}

Peliculas::Peliculas(string nombre_pelicula_out, string genero_out, int puntaje_out, string director_out, Lista<string> &actores_out) {
    this->nombre = nombre_pelicula_out;
    this->genero = genero_out;
    this->puntaje= puntaje_out;
    this->director=director_out;
    this->actores = actores_out; //pasarlo por referencia. VERIFICAR
}

void Peliculas::asignar_nombre(string nombre_out) {
    nombre=nombre_out;
}

string Peliculas::obtener_nombre() {
    return nombre;
}

void Peliculas::asignar_director(string director_out) {
    director=director_out;
}

string Peliculas::obtener_director() {
    return director;
}

void Peliculas::asignar_genero(string genero_out) {
    genero=genero_out;
}

string Peliculas::obtener_genero() {
    return genero;
}

void Peliculas::asignar_puntaje(int puntaje_out) {
    puntaje=puntaje_out;
}

int Peliculas::obtener_puntaje() {
    return puntaje;
}


