#ifndef ESCENA_HPP
#define ESCENA_HPP

#include <vector>
#include "NodoGrafoEscena.hpp"
#include "MallasPLY.hpp"

// Escena
class Helicopter : public NodoGrafoEscena{
        Objeto3D * chopper;
    public:
        Helicopter();
        void setX(float x);
        void setY(float y);
        void setAngleHRotor(float angle);
        void setAngleTRotor(float angle);
};

class HelicopterRotor : public NodoGrafoEscena{
        Objeto3D * hRotor;
    public:
        HelicopterRotor();
        void setAngle(float angle);
};

class TailRotor : public NodoGrafoEscena{
        Objeto3D * tRotor;
    public:
        TailRotor();
        void setAngle(float angle);
};

#endif
