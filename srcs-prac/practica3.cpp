// *********************************************************************
// **
// ** Informática Gráfica, curso 2015-16
// ** Práctica 3  (implementación)
// **
// *********************************************************************

#include "aux.hpp"
#include "tuplasg.hpp"   // Tupla3f 
#include "practica3.hpp"
#include "MallasInd.hpp" 
#include <vector>
#include "Escena.hpp"
#include "FreedomDegree.hpp"

static unsigned objeto_activo;
static unsigned grado_activo;

// ---------------------------------------------------------------------
// declaraciones de estructuras de datos....

static NodoGrafoEscena * * figuras;
Helicopter * chopper;
FreedomDegree<int> *subir, *avanzar;
FreedomDegree<double> *helice, *cola;

// ---------------------------------------------------------------------
// Funciones auxiliares

void aumentar(){
    switch(grado_activo){
        case 0:
            subir->increase();
            chopper->setY(subir->get_value());
            break;
        case 1:
            avanzar->increase();
            chopper->setX(avanzar->get_value());
            break;
        case 2:
            helice->increase();
            chopper->setAngleHRotor(helice->get_value());
            break;
        case 3:
            cola->increase();
            chopper->setAngleTRotor(cola->get_value());
            break;
    }
}

void disminuir(){
    switch(grado_activo){
        case 0:
            subir->decrease();
            chopper->setY(subir->get_value());
            break;
        case 1:
            avanzar->decrease();
            chopper->setX(avanzar->get_value());
            break;
        case 2:
            helice->decrease();
            chopper->setAngleHRotor(helice->get_value());
            break;
        case 3:
            cola->decrease();
            chopper->setAngleTRotor(cola->get_value());
            break;
    }
}

// ---------------------------------------------------------------------
// Función para implementar en la práctica 3 para inicialización.
// Se llama una vez al inicio, cuando ya se ha creado la ventana e 
// incializado OpenGL. 

void P3_Inicializar(int argc, char *argv[]){
    subir = new FreedomDegree<int> (0, 0, 50, 1, false);
    avanzar = new FreedomDegree<int> (0, -30, 30);
    helice = new FreedomDegree<double> (0, 0, 180, 5, true);
    cola = new FreedomDegree<double> (0, 0, 180, 10);

    grado_activo = 0;
    
    chopper = new Helicopter();
    
    figuras = new NodoGrafoEscena * [1] {chopper};

    objeto_activo = 0;
}

// ---------------------------------------------------------------------
// Función invocada al pulsar una tecla con la práctica 3 activa:
// (si la tecla no se procesa en el 'main').
//
//  - devuelve 'true' si la tecla se usa en esta práctica para cambiar 
//    entre el cubo, el tetraedro u otros objetos (cambia el valor de
//    'objeto_activo').
//  - devuelve 'false' si la tecla no se usa en esta práctica (no ha
//    cambiado nada)

bool P3_FGE_PulsarTeclaNormal(unsigned char tecla){
    switch(toupper(tecla)){
        case 'O':
            objeto_activo = (objeto_activo+1) % 1;
            break;

        case 'G':
            grado_activo = (grado_activo+1) % 4;
            break;

        case '<':
            disminuir();
            break;

        case '>':
            aumentar();
            break;

        default:
            return false;
    }

    return true;
}

// ---------------------------------------------------------------------
// Función a implementar en la práctica 3  para dibujar los objetos
// modo: 0 - puntos, 1 - alambre, 2 - sólido, 3 - sólido ajedrez , >=4 otros....

void P3_DibujarObjetos(unsigned modo){
    figuras[objeto_activo]->visualizar(modo);
}

