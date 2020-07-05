#include "Peliculas.h"

Peliculas::Peliculas() {
    this->nombre = " ";
    this->genero = " ";
    this->puntaje = 0;
    this->director = " ";
   // this->actores=0;
}
//Peliculas::Peliculas(string nombre_pelicula_out, string genero_out, int puntaje_out, string director_out, Lista<string> &actores_out) {

Peliculas::Peliculas(string nombre_pelicula_out, string genero_out, int puntaje_out, string director_out) {
    this->nombre = nombre_pelicula_out;
    this->genero = genero_out;
    this->puntaje= puntaje_out;
    this->director=director_out;
   // this->actores = actores_out; //pasarlo por referencia. VERIFICAR
}

void Peliculas::mostrar_peliculas(){
    cout << "nombre: "<<nombre <<endl ;
    cout << "genero: "<<genero <<endl  ;
    cout << "puntaje: "<<nombre <<endl  ;
    cout << "director: "<<nombre <<endl  ;

    for (int i = 1; i < actores.obtener_tam(); i++) {
        cout << "actor: "<< actores.obtener_dato(i) <<endl ;
    }
}
/*
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
*/

