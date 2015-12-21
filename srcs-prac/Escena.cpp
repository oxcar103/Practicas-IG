// *********************************************************************
// **
// ** Informática Gráfica, curso 2015-16
// ** Práctica 3  (implementación)
// **
// *********************************************************************

#include "Escena.hpp"

Helicopter::Helicopter(){
    chopper = new MallaPLY("../plys/helicopter.ply");

    // Matrices que determinarán la posición:
    agregar(MAT_Ident());
    agregar(MAT_Ident());

    // Colocar el modelo con la orientación correcta y la línea de tierra
    agregar(MAT_Traslacion(0, 3.1, 0));
    agregar(MAT_Rotacion(270, 1, 0, 0));
    agregar(MAT_Rotacion(90, 0, 0, 1));

    // Base
    agregar(chopper);

    // Hélice principal
    agregar(new HelicopterRotor());

    // Hélice de cola
    agregar(new TailRotor());
}

void Helicopter::setX(float x){
    *(entradas[0].matriz)=MAT_Traslacion(x, 0, 0);
}

void Helicopter::setY(float y){
    *(entradas[1].matriz)=MAT_Traslacion(0, y, 0);
}

void Helicopter::setAngleHRotor(float angle){
    HelicopterRotor * hijo = (HelicopterRotor *) entradas[6].objeto;
    hijo->setAngle(angle);
}

void Helicopter::setAngleTRotor(float angle){
    TailRotor * hijo = (TailRotor *) entradas[7].objeto;
    hijo->setAngle(angle);
}

HelicopterRotor::HelicopterRotor(){
    hRotor = new MallaPLY("../plys/helicopter2.ply");

    // Ajustes para que quede pegada a la base
    agregar(MAT_Traslacion(0, 0.2, 2.2));

    // Matriz que determinará el angulo
    agregar(MAT_Ident());

    // Hélice principal
    agregar(hRotor);
}

void HelicopterRotor::setAngle(float angle){
    *(entradas[1].matriz)= MAT_Rotacion(angle, 0, 0, 1);
}


TailRotor::TailRotor(){
    tRotor = new MallaPLY("../plys/helicopter3.ply");

    // Ajustes para que quede pegada a la base
    agregar(MAT_Traslacion(0.3, 7.6, 0.65));

    // Matriz que determinará el angulo
    agregar(MAT_Ident());

    // Hélice de cola
    agregar(tRotor);
}

void TailRotor::setAngle(float angle){
    *(entradas[1].matriz)= MAT_Rotacion(angle, 1, 0, 0);
}

