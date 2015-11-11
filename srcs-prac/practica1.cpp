// *********************************************************************
// **
// ** Informática Gráfica, curso 2015-16
// ** Práctica 1  (implementación)
// **
// *********************************************************************

#include "aux.hpp"
#include "tuplasg.hpp"   // Tupla3f 
#include "practica1.hpp"
#include "MallasInd.hpp" 
#include "Cube.hpp"
#include "Tetrahedron.hpp"
#include "Cylinder.hpp"
#include "Cone.hpp"
#include <vector>

static unsigned objeto_activo; // objeto activo: cubo (0), tetraedro (1), otros....

// ---------------------------------------------------------------------
// declaraciones de estructuras de datos....

static MallaInd * * figuras;
Cube * cubo = NULL;
Tetrahedron * tetraedro = NULL;
Cylinder * cilindro = NULL;
Cone * cono = NULL;

// ---------------------------------------------------------------------
// Función para implementar en la práctica 1 para inicialización.
// Se llama una vez al inicio, cuando ya se ha creado la ventana e 
// incializado OpenGL. 

void P1_Inicializar(int argc, char *argv[]){
    cubo = new Cube(1.5);
    tetraedro = new Tetrahedron(1.25);
    cilindro = new Cylinder(1, 0.85);
    cono = new Cone(1, 0.85, 50);

    figuras = new MallaInd *[4] {cubo, tetraedro, cilindro, cono};

    objeto_activo = 0;
}

// ---------------------------------------------------------------------
// Función invocada al pulsar una tecla con la práctica 1 activa:
// (si la tecla no se procesa en el 'main').
//
//  - devuelve 'true' si la tecla se usa en esta práctica para cambiar 
//    entre el cubo, el tetraedro u otros objetos (cambia el valor de
//    'objeto_activo').
//  - devuelve 'false' si la tecla no se usa en esta práctica (no ha
//    cambiado nada)

bool P1_FGE_PulsarTeclaNormal(unsigned char tecla){
    switch(toupper(tecla)){
        case 'O':
            objeto_activo = (objeto_activo+1) % 4;            
            break;

        default:
            return false;
    }

    return true;
}

// ---------------------------------------------------------------------
// Función a implementar en la práctica 1  para dibujar los objetos
// modo: 0 - puntos, 1 - alambre, 2 - sólido, 3 - sólido ajedrez , >=4 otros....

void P1_DibujarObjetos(unsigned modo){
    figuras[objeto_activo]->visualizar(modo);
}

