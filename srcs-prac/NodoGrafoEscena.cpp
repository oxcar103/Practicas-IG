// *********************************************************************
// **
// ** Informática Gráfica, curso 2015-16
// ** Práctica 1  (implementación)
// **
// *********************************************************************

#include "NodoGrafoEscena.hpp"
#include "aux.hpp"

void NodoGrafoEscena::visualizar(unsigned modo_vis){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    for(unsigned i = 0; i < entradas.size(); i++){
        if(entradas[i].tipoE == 0)      // sub-objeto: visualizarlo
            entradas[i].objeto->visualizar(modo_vis);
        else        // transformación: componerla
            glMultMatrixf(*(entradas[i].matriz));
    }

    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}

void NodoGrafoEscena::agregar(EntradaNGE * entrada){
    entradas.push_back(*entrada);
}

void NodoGrafoEscena::agregar(EntradaNGE  entrada){
    EntradaNGE * aux = new EntradaNGE(entrada);

    agregar(aux);
}

