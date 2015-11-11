#ifndef CONE_HPP
#define CONE_HPP

#include "MallasInd.hpp"

// Clase para el cono
class Cone : public MallaInd{
    public:
        Cone(double height = 1.0, double radius = 1.0, int num_parts = 103);
};
#endif
