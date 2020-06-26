#ifndef PELICULAS_H_INCLUDED
#define PELICULAS_H_INCLUDED


class Pelicula{

            private:
                    string nombrePelicula ;
                    string genero ;
                    int puntaje ;
                    string director ;
                    Lista<string> actores ;

            public:
                    Pelicula() ;
                    ~ Pelicula() ;
                    obtenerGenero();
                    obtenerActores();
                    obtenerDirector();
                    mostrarPuntaje();

}












};

#endif // PELICULAS_H_INCLUDED
