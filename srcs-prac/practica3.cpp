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

static unsigned objeto_activo;

// ---------------------------------------------------------------------
// declaraciones de estructuras de datos....

static MallaInd * * figuras;

// ---------------------------------------------------------------------
// Función para implementar en la práctica 3 para inicialización.
// Se llama una vez al inicio, cuando ya se ha creado la ventana e 
// incializado OpenGL. 

void P3_Inicializar(int argc, char *argv[]){
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

        default:
            return false;
    }

    return true;
}

// ---------------------------------------------------------------------
// Función a implementar en la práctica 3  para dibujar los objetos
// modo: 0 - puntos, 1 - alambre, 2 - sólido, 3 - sólido ajedrez , >=4 otros....

void P3_DibujarObjetos(unsigned modo){
//    figuras[objeto_activo]->visualizar(modo);
}

