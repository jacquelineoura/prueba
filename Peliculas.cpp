#include "Peliculas.h"

Peliculas::Peliculas() {
    this->nombre = " ";
    this->genero = " ";
    this->puntaje = 0;
    this->director = " ";

}

Peliculas::Peliculas(string nombre_pelicula_out, string genero_out, int puntaje_out, string director_out) {

    this->nombre = nombre_pelicula_out;
    this->genero = genero_out;
    this->puntaje= puntaje_out;
    this->director=director_out;
    actores = new Lista<string>();
}


void Peliculas::asignar_actor(string nombre_actor){
  actores -> insertar(nombre_actor);
}


void Peliculas::mostrar_peliculas(){

    cout << "\tNombre: "<<nombre <<endl ;
    cout << "\tGenero: "<<genero <<endl  ;
    cout << "\tPuntaje: "<<puntaje <<endl  ;
    cout << "\tDirector: "<<director <<endl  ;


   for (int i = 1; i <= actores->obtener_tam(); i++) {
        cout << "\tActor "<<i<<"." <<actores->obtener_dato(i) ;

   cout <<endl ;

}


}/*
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

