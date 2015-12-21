// *********************************************************************
// **
// ** Informática Gráfica, curso 2015-16
// ** Práctica 3  (declaraciones públicas)
// **
// *********************************************************************

#ifndef NGE_HPP
#define NGE_HPP

#include <vector>
#include "EntradaNGE.hpp"

// Nodo grafo de escena
class NodoGrafoEscena : public Objeto3D{
    protected:
        std::vector<EntradaNGE> entradas;   // vector de entradas

    public:
        // visualiza usando OpenGL
        virtual void visualizar(unsigned modo_vis);

        // añade entrada al final
        void agregar(EntradaNGE * entrada);
        // añade entrada al final
        void agregar(EntradaNGE entrada);

};

#endif
