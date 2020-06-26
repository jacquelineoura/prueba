#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
# include <iostream>
# include "nodo.h"



using namespace std;


template < typename Dato >
class Lista
{
    private :
        // Primer elemento de la lista
        Nodo < Dato >* primero ;
        // Tamaño de la lista
        unsigned tam ;

    public :
        // Constructor
        // PRE: Ninguna
        // POST: construye una lista vacía
        // - primero apunta a nulo
        // - tam = 0
        Lista() ;
        // Destructor
        // PRE: Lista creada
        // POST: Libera todos los recursos de la lista
        ~Lista() ;
        // Agregar un elemento a la lista
        // PRE: lista creada y d válido
        // POST: agrega un dato dentro de un nodo al principio
        // - modifica el primero
        // - tam se incrementa en 1
        void insert ( Dato d ) ;
        // Obtener el tamaño de la lista
        // PRE: Lista creada
        // POST: devuelve el tamaño de la lista (cantidad de nodos)
        unsigned get_tam () ;
        // Obtener el dato que está en la posición pos
        // PRE: - lista creada y no vacía
        // - 0 < pos <= tam
        // POST: devuelve el dato que está en la posición pos
        // se toma 1 como el primero
        Dato get_dato ( unsigned posicion ) ;
        // ¿Lista vacia?
        // PRE: Lista creada
        // POST: True si es vacia, False sino
        bool lista_vacia () ;
        // Borrado del nodo que está en la posición pos
        // PRE: - lista creada y no vacía
        // - 0 < pos <= tam
        // POST: libera el nodo que está en la posición pos
        // se toma 1 como el primero
        void del_dato( unsigned posicion ) ;

};





// Constructor
template < typename Dato >
Lista<Dato>::Lista()
{
    primero = 0;
    tam = 0;
}


// Destructor
template < typename Dato >
Lista<Dato>::~Lista()
{
    while (!this->lista_vacia())
    {
    this->del_dato(1);
    }
}


template < typename Dato >
bool Lista < Dato > :: lista_vacia()
{
    return (tam == 0) ;
}


template < typename Dato >
void Lista < Dato > :: insert( Dato d )
{
    Nodo<Dato>* nuevo = new Nodo<Dato>(d);

    if (!(this-> lista_vacia () ))
    {
    nuevo -> set_sig( primero ) ;
    }
    primero = nuevo ;
    tam++ ;
}


// Devuelve el dato que esta en la posición pos
template < typename Dato >
Dato Lista < Dato > :: get_dato ( unsigned posicion )
{
    Nodo < Dato >* aux = primero ;
    if ( !lista_vacia() )
    {
        for ( unsigned contador = 1 ; ( contador < posicion && aux ) ; contador ++ ){
            aux = aux -> get_sig() ;
     }

    return aux -> get_dato() ;
    }
    return 0 ;
}


template < typename Dato >
unsigned Lista<Dato> :: get_tam ()
{
    return tam ;
}


template < typename Dato >
void Lista<Dato>::del_dato(unsigned posicion)
{
       Nodo < Dato >* paux = primero ;

    if (posicion == 1 || !(primero -> get_sig() ) )
    {
        primero = paux -> get_sig() ;
    }
    else
    {
        unsigned i = 1 ;
        Nodo < Dato >* pant = NULL ;

        while (i < posicion && paux->get_sig())
        {
            pant = paux ;
            paux = paux -> get_sig() ;
            i++ ;
        }
        pant -> set_sig ( paux -> get_sig() ) ;
    }

    delete paux ;
    tam-- ;    //decrementa el tamanio de la lista
}


#endif // LISTA_H_INCLUDED
