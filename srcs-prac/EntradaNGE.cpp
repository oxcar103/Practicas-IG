// *********************************************************************
// **
// ** Informática Gráfica, curso 2015-16
// ** Práctica 1  (implementación)
// **
// *********************************************************************

#include "EntradaNGE.hpp"

EntradaNGE::EntradaNGE(Objeto3D * pObjeto){
    objeto = pObjeto;
    tipoE = 0;
};

EntradaNGE::EntradaNGE(const Matriz4f & pMatriz){
    matriz = new Matriz4f(pMatriz);
    tipoE = 1;
};

