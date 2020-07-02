#include "Programa.h"


const MSJ_OPCION = "\n\tIngrese la opcion que desea: " ;
const int SALIR = 0 ;
const int PELIS_VISTAS = 1 ;
const int PELIS_NO_VISTAS = 2 ;
const int PELIS_RECOMENDADAS = 3 ;


Programa::Programa() {

}
Programa::~Programa() {

}


int Programa:: obtener_opcion() {
    return opcion;
}

void Programa:: mostrar_menu() {   //aca pegue el menu que habias hecho Alex
        cout<<endl<<endl<<"Bienvenido al programa principal"<<endl;
        cout<<"Decida que operacion quiere realizar: "<< endl << endl ;
        cout<<"1. Mostrar lista peliculas vistas"<< endl;
        cout<<"2. Mostrar lista peliculas no vistas"<< endl;
        cout<<"3. Mostrar lista peliculas recomendadas"<< endl;
        cout<<"0. Salir del programa"<< endl;
}

void Menu:: elegir_opcion() {
    string opcion_menu;

    cout << MSJ_OPCION;
    cin >> opcion_menu;
    cout <<endl;
    opcion = stoi ( opcion_menu.c_str());    //falta validar opcion_menu
}


void Programa::  abrir_menu_interno(Lista<Peliculas> &lista_pelis_no_vistas, Lista<Peliculas> &lista_pelis_vistas){


    switch (opcion) {

            case PELIS_VISTAS :  mostrar_lista_pelicula(lista_pelis_vistas );
                                 break;

            case PELIS_NO_VISTAS:  mostrar_lista_pelicula(lista_pelis_no_vistas);
                                   break;
                                        // falta hacer recomendados
            case PELIS_RECOMENDADAS:   formar_recomendados();
                                       mostrar_lista_pelicula(lista_recomendadas);
                                        break;

            case SALIR: cout<<"Fin del programa"<<endl;
                        break;
}
}


void mostrar_lista_pelicula(Lista<Peliculas> &lista){
}




/*
//El programa principal deberia empezar llamando la clase LeerArchivo para formar las listas con lo obtenido en el archivo.
void Programa::programa_principal() {

    //leer_archivo.metodoAdefinir
    int auxiliar;

    while(auxiliar!=4){
        cout<<endl<<endl<<"Bienvenido al programa principal"<<endl;
        cout<<"Decida que operacion quiere hacer"<<endl;
        cout<<"1. Mostrar lista peliculas vistas"<<endl;
        cout<<"2. Mostrar lista peliculas no vistas"<<endl;
        cout<<"3. Mostrar lista peliculas recomendadas"<<endl;
        cout<<"4. Salir del programa"<<endl;
        cin>>auxiliar;

        switch (auxiliar) {
            case 1:mostrar_lista_pelicula(auxiliar);break;
            case 2:mostrar_lista_pelicula(auxiliar);break;
            case 3:formar_recomendados(); mostrar_lista_pelicula(auxiliar); break;
            case 4: cout<<"Fin del programa"<<endl; break;
            default: {
                cout<<"Ingrese una opcion valida: 1, 2, 3 o 4"<<endl;
                cin>>auxiliar;
            }
        }
    }




}

void Programa::mostrar_lista_pelicula(int auxiliar) {
    //muestra la lista entera (la que le pidas, vista o no vista). El auxiliar te sirve para saber que lista queres que muestre.
    cout<<"Mostrar lista peliculas"<<endl;
}

void Programa::formar_recomendados() {
    //seguramente para hacedr esta van a haber que crear mas metodos (uno que forme recomendados con ambas listas y otro con una sola lista)
    cout<<"Formando lista recomendados"<<endl;
}









//--------------------SETTERS Y GETTERS-----------

void Programa::asignar_archivo_vistas(string archivo_vistas_out) {
    this->archivo_vistas=archivo_vistas_out;
}

void Programa::asignar_archivo_novistas(string archivo_novistas_out) {
    this->archivo_novistas=archivo_novistas_out;
}

string Programa::obtener_archivo_vistas() {
    return archivo_vistas;
}

string Programa::obtener_archivo_novistas() {
    return archivo_novistas;
}
*/
