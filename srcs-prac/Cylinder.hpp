// *********************************************************************
// **
// ** Informática Gráfica, curso 2015-16
// ** Práctica 1  (declaraciones públicas)
// **
// *********************************************************************

#ifndef CYLINDER_HPP
#define CYLINDER_HPP

#include "MallasInd.hpp"

// Clase para el cilindro
class Cylinder : public MallaInd{
    public:
        Cylinder(double height = 1.0, double radius = 1.0, int num_parts = 103);
};
#endif
