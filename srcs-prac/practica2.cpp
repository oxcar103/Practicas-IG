// *********************************************************************
// **
// ** Informática Gráfica, curso 2015-16
// ** Práctica 2  (implementación)
// **
// *********************************************************************

#include "aux.hpp"
#include "tuplasg.hpp"   // Tupla3f 
#include "practica2.hpp"
#include "MallasInd.hpp"
#include "MallasPLY.hpp"
#include "MallasRevol.hpp"
#include <vector>

static unsigned objeto_activo;

// ---------------------------------------------------------------------
// declaraciones de estructuras de datos....

static MallaInd * * figuras;
MallaPLY * fig_ply = NULL;
MallaRevol * fig_revol = NULL;

// ---------------------------------------------------------------------
// Función para implementar en la práctica 2 para inicialización.
// Se llama una vez al inicio, cuando ya se ha creado la ventana e 
// incializado OpenGL. 

void P2_Inicializar(int argc, char *argv[]){
    fig_revol = new MallaRevol("../plys/peon.ply", 50);

    if(argc > 1)
        fig_ply = new MallaPLY(argv[1]);
    else
        fig_ply = new MallaPLY("../plys/ant.ply");

    figuras = new MallaInd *[2] {fig_ply, fig_revol};

    objeto_activo = 0;
}

// ---------------------------------------------------------------------
// Función invocada al pulsar una tecla con la práctica 2 activa:
// (si la tecla no se procesa en el 'main').
//
//  - devuelve 'true' si la tecla se usa en esta práctica para cambiar 
//    entre el cubo, el tetraedro u otros objetos (cambia el valor de
//    'objeto_activo').
//  - devuelve 'false' si la tecla no se usa en esta práctica (no ha
//    cambiado nada)

bool P2_FGE_PulsarTeclaNormal(unsigned char tecla){
    switch(toupper(tecla)){
        case 'O':
            objeto_activo = (objeto_activo+1) % 2;
            break;

        default:
            return false;
    }

    return true;
}

// ---------------------------------------------------------------------
// Función a implementar en la práctica 2  para dibujar los objetos
// modo: 0 - puntos, 1 - alambre, 2 - sólido, 3 - sólido ajedrez , >=4 otros....

void P2_DibujarObjetos(unsigned modo){
    figuras[objeto_activo]->visualizar(modo);
}

