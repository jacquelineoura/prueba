#include "Programa.h"

Programa::Programa(bool esta_vistas) {
    this -> esta_vistas = esta_vistas;
}

char Programa:: obtener_opcion() {
    return opcion;
}

void Programa:: mostrar_menu() {
        cout << "\n\t***************  MENU **************"<< endl << endl;
        cout << "\t1. Mostrar lista peliculas vistas" << endl;
        cout << "\t2. Mostrar lista peliculas no vistas" << endl;
        cout << "\t3. Mostrar lista peliculas recomendadas" << endl;
        cout << "\t0. Salir del programa" << endl;
}

void Programa:: elegir_opcion(){
    cout << MSJ_OPCION;
    cin >> opcion;
}


void Programa::abrir_menu_interno(Lista<Peliculas*> &lista_no_vistas , Lista<Peliculas*> &lista_vistas ){

    switch ( opcion ){
        case PELIS_VISTAS: {
            if ( esta_vistas == true ){
                mostrar_lista_pelicula(lista_vistas);
            }
            else
                cout << endl << "\tNo se puede mostrar vistas porque no se encontro el archivo anteriormente\n";
            break;
        }

        case PELIS_NO_VISTAS:
            mostrar_lista_pelicula(lista_no_vistas);
            break;

        case PELIS_RECOMENDADAS:{
            Lista < Dato > lista_recomendadas;
            if (esta_vistas)
                llenar_recomendados(lista_no_vistas,lista_vistas,lista_recomendadas);
            else
                llenar_recomendados(lista_no_vistas,lista_recomendadas);
            mostrar_lista_pelicula(lista_recomendadas);
            break;
        }

        case SALIR:
            cout << MSJ_FIN_PROGRAMA << endl;
            return;

        default:
            cout << "\tOpcion invalida, por favor elija una opcion del menu [0-3]\n";
    }
}


void Programa:: mostrar_lista_pelicula( Lista<Peliculas*> &lista ){

    cout << endl << MSJ_PELICULAS << endl;

    if ( !lista.lista_vacia() ){
        for ( int i = 1; i <= lista.obtener_tam(); i++ ){
            cout << i  << ". " << endl;
            lista.obtener_dato(i)->mostrar_peliculas();
            cout << endl;
        }
    }
}

void Programa::llenar_recomendados( Lista<Dato> &lista_no_vistas, Lista<Dato> &lista_vistas, Lista<Dato> &lista_recomendado ){

    Lista < string > actores;
    Lista < string > directores;
    Lista < string > generos;

    llenar_listas_auxiliares( lista_vistas,  actores, directores, generos );

    for ( int i = PRIMER_NODO; i <= lista_no_vistas.obtener_tam(); i++ ){

        if (puntaje_es_valido (i , lista_no_vistas)){
            lista_recomendado.insertar(lista_no_vistas.obtener_dato(i) );
        }
        else if (coincidencia_genero(i, generos, lista_no_vistas)){

            if (coincidencia_director(i, directores, lista_no_vistas) ){
                lista_recomendado.insertar(lista_no_vistas.obtener_dato(i) );
            }
            else if (coincidencia_actor(i, actores, lista_no_vistas) ){
                lista_recomendado.insertar(lista_no_vistas.obtener_dato(i) );
            }
        }
    }

}



bool Programa::puntaje_es_valido (int posicion, Lista<Dato> &lista_no_vistas){

    bool puntaje_valido = false;
    if ( lista_no_vistas.obtener_dato(posicion)->obtener_puntaje() >= CONDICION_DE_PUNTAJE_MINIMO )
        puntaje_valido = true;
    return puntaje_valido;
}

bool Programa::coincidencia_genero(int posicion, Lista<string> &generos, Lista<Dato> &lista_no_vistas){

    bool hay_coincedencia = false;
    for ( int i = PRIMER_NODO; i <= generos.obtener_tam(); i++ ){
        if ( generos.obtener_dato(i) == lista_no_vistas.obtener_dato(posicion)->obtener_genero() )
            hay_coincedencia = true;
    }
    return hay_coincedencia;
}

bool Programa::coincidencia_director(int posicion, Lista<string> &directores, Lista<Dato> &lista_no_vistas){

    bool hay_coincedencia = false;
    for ( int i = PRIMER_NODO; i <= directores.obtener_tam(); i++ ){
        if ( directores.obtener_dato(i) == lista_no_vistas.obtener_dato(posicion)->obtener_director() )
            hay_coincedencia = true;
    }
    return hay_coincedencia;
}

bool Programa::coincidencia_actor(int posicion, Lista<string> &actores, Lista<Dato> &lista_no_vistas){

    bool hay_coincedencia = false;
    for ( int i = PRIMER_NODO; i <= lista_no_vistas.obtener_dato(posicion)->obtener_cantidad_actores(); i++ ){
        for ( int j = PRIMER_NODO; j <= actores.obtener_tam(); j++ ){
            if ( actores.obtener_dato(j) == lista_no_vistas.obtener_dato(posicion)->obtener_actores(i) )
                    hay_coincedencia = true;
        }
    }
    return hay_coincedencia;
}

void Programa::llenar_listas_auxiliares( Lista<Dato> &lista_vistas, Lista<string> &actores, Lista<string> &directores, Lista<string> &generos ){

        for ( int i = PRIMER_NODO; i <= lista_vistas.obtener_tam(); i++ ){
            generos.insertar( lista_vistas.obtener_dato(i)->obtener_genero() );
            directores.insertar( lista_vistas.obtener_dato(i)->obtener_director() );
            for( int j=PRIMER_NODO; j<=lista_vistas.obtener_dato(i)->obtener_cantidad_actores(); j++ ){
                actores.insertar( lista_vistas.obtener_dato(i)->obtener_actores(j) );
        }
    }
}

void Programa::llenar_recomendados( Lista<Dato> &lista_no_vistas, Lista<Dato> &lista_recomendado ){

    cout << endl << "Formo recomendados con no vistas" << endl;
    for ( int i = PRIMER_NODO; i <= lista_no_vistas.obtener_tam(); i++ ){
        if ( lista_no_vistas.obtener_dato(i)->obtener_puntaje() >= CONDICION_DE_PUNTAJE_MINIMO ){
            lista_recomendado.insertar( lista_no_vistas.obtener_dato(i) );
        }
    }

}