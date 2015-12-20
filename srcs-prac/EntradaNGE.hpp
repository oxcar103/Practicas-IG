#ifndef ENTRADA_NGE_HPP
#define ENTRADA_NGE_HPP

#include "matrices-tr.hpp"
#include "matrizg.hpp"
#include "matrizg_impl.hpp"
#include "Objeto3D.hpp"

// Entrada del nodo del Grafo de Escena
class EntradaNGE{
    public:
        unsigned char tipoE;    // 0 = objeto, 1 = transformación

        union{
            Objeto3D * objeto;    // Puntero a objeto(propietario)
            Matriz4f * matriz;    // Puntero a matriz 4x4 transformación(propietario)
        };

        EntradaNGE(Objeto3D * pObjeto);          // Copia solo puntero
        EntradaNGE(const Matriz4f & pMatriz);   // Crea copia
};

#endif
