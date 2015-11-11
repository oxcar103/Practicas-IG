#ifndef MALLASIND_HPP
#define MALLASIND_HPP

#include "Objeto3D.hpp"
#include <vector>
#include "tuplasg.hpp"
 
// clase para mallas indexadas o mallas TVT
class MallaInd : public Objeto3D{
    protected:
    // declarar aquí tablas de vértices y caras
    std::vector<Tupla3f> vertices;
    std::vector<Tupla3i> faces;
    public:
        virtual void visualizar(unsigned modo_vis);
};
#endif
