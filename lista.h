#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
# include <iostream>
# include "nodo.h"



using namespace std;


template <typename Dato>
class Lista{

    private :

        // Primer elemento de la lista
        Nodo <Dato>* primero;
        // Tamanio de la lista
        unsigned tam;

    public :

        // Constructor
        // PRE: Ninguna
        // POST: construye una lista vacia
        // - primero apunta a nulo
        // - tam = 0
        Lista();

        // Destructor
        // PRE: Lista creada
        // POST: Libera todos los recursos de la lista
        ~Lista();

        // Agregar un elemento a la lista
        // PRE: lista creada y d valido
        // POST: agrega un dato dentro de un nodo al principio
        // - modifica el primero
        // - tam se incrementa en 1
        void insertar (Dato d);

        // Obtener el tamanio de la lista
        // PRE: Lista creada
        // POST: devuelve el tamanio de la lista (cantidad de nodos)
        int obtener_tam () ;

        // Obtener el dato que esta en la posicion posicion
        // PRE: - lista creada y no vacia
        // - 0 < pos <= tam
        // POST: devuelve el dato que esta en la posicion posicion
        // se toma 1 como el primero
        Dato obtener_dato (unsigned posicion);

        // Lista vacia?
        // PRE: Lista creada
        // POST: True si es vacia, False sino
        bool lista_vacia ();

        // Borrado del nodo que esta en la posicion posicion
        // PRE: - lista creada y no vacia
        // - 0 < pos <= tam
        // POST: libera el nodo que esta en la posicion posicion
        // se toma 1 como el primero
        void borrar_dato(unsigned posicion);



};





// Constructor
template <typename Dato>
Lista <Dato> ::Lista(){

    primero = 0;
    tam = 0;
}


// Destructor
template <typename Dato>
Lista <Dato> ::~Lista(){

    while (!this->lista_vacia()){
    this->borrar_dato(1);
    }
}


template <typename Dato>
bool Lista <Dato> :: lista_vacia(){

    return (tam == 0);
}


template <typename Dato>
void Lista <Dato> :: insertar(Dato d){

    Nodo <Dato>* nuevo = new Nodo<Dato>(d);
    if (!(this-> lista_vacia () )){
    nuevo -> set_sig(primero) ;
    }
    primero = nuevo ;
    tam++ ;
}


// Devuelve el dato que esta en la posicion pos
template <typename Dato>
Dato Lista <Dato> :: obtener_dato (unsigned posicion){

    Nodo <Dato>* aux = primero;
    if (!lista_vacia()){
        for (unsigned contador = 1; (contador < posicion && aux); contador ++){
            aux = aux -> get_sig();
    }

    return aux -> get_dato();
    }
    return 0;
}


template <typename Dato>
int Lista <Dato> :: obtener_tam(){

    return tam;
}


template <typename Dato>
void Lista <Dato> ::borrar_dato(unsigned posicion){

    Nodo < Dato >* paux = primero;
    if ( posicion == 1 || !( primero -> get_sig() ) ){
        primero = paux -> get_sig() ;
    }
    else{
        unsigned i = 1;
        Nodo <Dato>* pant = NULL;

        while (i < posicion && paux->get_sig()){
            pant = paux;
            paux = paux -> get_sig();
            i++ ;
        }
        pant -> set_sig (paux -> get_sig());
    }

    delete paux;
    tam--;
}




#endif // LISTA_H_INCLUDED
