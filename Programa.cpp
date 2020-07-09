#include "Programa.h"


const string MSJ_OPCION = "\n\tIngrese la opcion que desea: " ;
const string MSJ_PELICULAS= "\t******** Peliculas ********  " ;
const string MSJ_FIN_PROGRAMA= "Fin del programa" ;
const int SALIR = 0 ;
const int PELIS_VISTAS = 1 ;
const int PELIS_NO_VISTAS = 2 ;
const int PELIS_RECOMENDADAS = 3 ;
const int CONDICION_DE_PUNTAJE_MINIMO = 7;


Programa::Programa() {
}
Programa::~Programa() {
//FALTA
}

int Programa:: obtener_opcion() {
    return opcion;
}

void Programa:: mostrar_menu() {   //aca pegue el menu que habias hecho Alex
        cout << endl << endl << endl ;
        cout << "\t***************  MENU **************"<<endl << endl ;
        cout << "\tDecida que operacion quiere realizar: " << endl << endl ;
        cout << "\t1. Mostrar lista peliculas vistas" << endl ;
        cout << "\t2. Mostrar lista peliculas no vistas" << endl ;
        cout << "\t3. Mostrar lista peliculas recomendadas" << endl ;
        cout << "\t0. Salir del programa" << endl ;
}

void Programa:: elegir_opcion(){
    string opcion_menu ;
    cout << MSJ_OPCION ;
    cin >> opcion_menu ;
    cout <<endl ;
    opcion = atoi ( opcion_menu.c_str() ) ;    //falta validar opcion_menu  - FALTA
}


void Programa:: abrir_menu_interno( Lista<Peliculas*> &lista_no_vistas , Lista<Peliculas*> &lista_vistas ){

    switch ( opcion ) {
            case PELIS_VISTAS:  mostrar_lista_pelicula(lista_vistas);
                break;

            case PELIS_NO_VISTAS: mostrar_lista_pelicula(lista_no_vistas);
                break;

            case PELIS_RECOMENDADAS:{
                Lista<Dato> lista_recomendadas;
                bool esta_vistas;

                esta_vistas=true; //por ahora lo dejo asi. Despues hay que recibir del main este parametro. Aca deberia recibir si se abrio o no

                if (esta_vistas)
                    llenar_recomendados(lista_no_vistas,lista_vistas,lista_recomendadas);
                    //probando
                 else
                     llenar_recomendados(lista_no_vistas,lista_recomendadas);

                mostrar_lista_pelicula(lista_recomendadas);
            }
            break;

            case SALIR: cout << MSJ_FIN_PROGRAMA << endl ;
                        break;
    }
}


void Programa:: mostrar_lista_pelicula(Lista<Peliculas*> &lista){
    cout << endl << endl << MSJ_PELICULAS << endl << endl;

    if ( !lista.lista_vacia() ) {
        for (int i = 1; i <= lista.obtener_tam(); i++ ) {
            cout << i  << ". " << endl ;
            lista.obtener_dato(i)->mostrar_peliculas();
            cout << endl << endl ;
        }
    }
}


//Lo forma con vistas y no vistas
void Programa::formar_recomendados(Lista<Dato> &lista_no_vistas, Lista<Dato> &lista_vistas, Lista<Dato> &lista_recomendado){

    /*
 //te dejo un ejemplo de como acceder a los datos. Despues implementa como quieras.
   if(lista_no_vistas.obtener_dato(3)->obtener_puntaje()>=7)
       cout<<"Esta pelicula va a ir a recomendadasss"<<endl;
    */

   //IDEA DE ALEX DE HACER RECOMENDADOS
   //-------Creo 3 listas auxiliares-------
   Lista<string> actores;
   Lista<string> directores;
   Lista<string> generos;
   //Lista<string> participantes;

   //--------Lleno las 3 listas auxiliares con la informacion de las peliculas vistas.-------
   for (int i=0;i<=lista_vistas.obtener_tam();i++){
       generos.insertar(lista_vistas.obtener_dato(i)->obtener_genero());
       directores.insertar(lista_vistas.obtener_dato(i)->obtener_director());

       //------Lleno la lista de actores con los actores de peliculas vistas.--------
       for(int j=0; j<=lista_vistas.obtener_dato(i)->obtener_cantidad_actores() ;j++){
           actores.insertar(lista_vistas.obtener_dato(i)->obtener_actores(j));
       }
   }

    //NI IDEA SI FUNCIONA, PROBAR MOSTRAR LAS COSAS. AUXILIAR
   /*cout<<"Lista actores"<<endl;
    for (int k = 0; k < actores.obtener_tam() ; ++k) { //por qué en esta no es "<=" como en los otros ?
        cout<<actores.obtener_dato(k)<<endl;
    }
*/
   //------------------------------------------------------------------------------------------------------

    bool coincide = false;

    for (int i = 0; i <= lista_no_vistas.obtener_tam(); i++){
        if (lista_no_vistas.obtener_dato->obtener_puntaje() >= CONDICION_DE_PUNTAJE_MINIMO){
            lista_recomendado.insertar(lista_no_vistas.obtener_dato(i));
        }else{
            for (int j = 0; j <= generos.obtener_tam(); j++){
                if (generos.obtener_dato(j) == lista_no_vistas.obtener_dato(i)->obtener_genero)
                    for (int k = 0; k <= directores.obtener_tam(); k++){
                        if (directores.obtener_dato(k) == lista_no_vistas.obtener_dato(i)->asignar_director){
                            coincide = true;
                        }else{
                            for (int m = 0; m <= lista_no_vistas.obtener_dato->obtener_cantidad_actores(); j++){
                                for (int h = 0; h <= actores.obtener_tam(); h++){
                                    if (lista_no_vistas.obtener_dato->obtener_actores(m) == actores.obtener_dato)
                                    coincide = true;
                            }
                        }

                    }
            }
            if (coincide)
                lista_recomendado.insertar(lista_no_vistas.obtener_dato(i));
        }


    }
}



//lo forma con no vistas unicamente
void Programa::formar_recomendados(Lista<Dato> &lista_no_vistas, Lista<Dato> &lista_recomendado) {
    for (int i = 0; i <= lista_no_vistas.obtener_tam(); i++){
        if (lista_no_vistas.obtener_dato->obtener_puntaje() >= CONDICION_DE_PUNTAJE_MINIMO){
            lista_recomendado.insertar(lista_no_vistas.obtener_dato(i));
        }
}


/*REVISAR ESTA MAL EL FORMATO, LAS CABECERAS*/
/*
Lista<Dato> crear_recomendados(Lista<Dato> &lista_no_vistas, Lista<Dato> &lista_vistas) {
    string* generos = new string [lista_vistas -> obtener_tam()];
    Lista<Dato> lista_participantes;
    Lista<Dato> lista_recomendadas;
    lectura_de_peliculas_vistas (lista_vistas, generos, lista_participantes);
    recomendadas (lista_participantes, lista_recomendadas, generos);
    return lista_recomendadas;
 }

 void recomendadas (Lista<Dato> &lista_participantes, Lista<Dato> &lista_recomendadas, &generos){
    bool esta = false;
    while (primero->tiene_sig()){ //no vistas
        if (dato->obtener_puntaje() >= 7){
            lista_recomendadas.insertar(dato);
        }else{
            for (int i = 0; i < lista_vistas -> obtener_tam(); i++){
                if (generos[i] == dato->obtener_genero())
                    esta = true;
            }
            if (esta){
                    esta = false;
                    while (actores->tiene_sig()){ //de la no vistas.
                        while (primero->tiene_sig()){ // de la lista participantes.
                            if (son la misma persona)
                                esta = true;
                        }
                    if (esta)
                        lista_recomendadas.insertar(dato);
                    }

            }
        }
        esta = false;
    }
 }

 void lectura_de_peliculas_vistas (Lista<Dato> &lista_vistas, &generos, Lista<Dato> &participantes){
    int contador = 0;
    do{
        generos[contador] = dato->obtener_genero();
        listaparticipantes -> insertar(dato -> obtener_director());
        while (actores->tiene_sig()){
            listaparticipantes -> insertar(actores -> obtener_dato (unsigned posicion)); //falta posicion.
        }
        contador ++;
    }while (primero->tiene_sig());
 }

 Lista<Dato> crear_recomendados_exepcion (Lista<Dato> &lista_no_vistas) {
    Lista<Dato> lista_recomendadas_exepcion;
    while (primero->tiene_sig()){ //no vistas
        if (dato->obtener_puntaje() >= 7){
            lista_recomendadas_exepcion.insertar(dato);
        }
    return lista_recomendadas_exepcion;
 }
*/

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
