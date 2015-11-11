// *********************************************************************
// **
// ** Informática Gráfica, curso 2015-16
// ** Práctica 1  (implementación)
// **
// *********************************************************************

#include "Cone.hpp"

/* Cone(12 parts):
 *                  .v13
 *                 / \
 *                /   \
 *               /     \
 *              /       \
 *             /         \
 *            /           \
 *           /    (0,0)    \
 *          /       .       \
 *         /                 \
 *        /         v3        \
 *       /     v4 _---_ v2     \
 *      /_v5"""""´     `"""""v1_\ 
 *   v6(__          .v12       __)v0
 *        v7-_____     _____-v11 
 *             v8 `"-"´v10
 *                  v9
 */

Cone::Cone(double height, double radius, int num_parts){
    double angle, y = height/2.0;
    int top, bottom;

    nombre_obj = "Cono";

    if(num_parts < 3)
        num_parts = 3;

    angle = 2*M_PI/(num_parts*1.0);

    // Vertices
    for(int i = 0; i < num_parts; i++){
        vertices.push_back(Tupla3f (radius*cos(i*angle), -y, radius*sin(i*angle)));
    }

    vertices.push_back(Tupla3f (0, -y, 0));
    bottom = vertices.size()-1;
    vertices.push_back(Tupla3f (0, y, 0));
    top = vertices.size()-1;

    // Faces
    for(int i = 0; i < num_parts; i++){
        faces.push_back(Tupla3i(i, (i+1)%num_parts, bottom));
    }

    for(int i = 0; i < num_parts; i++){
        faces.push_back(Tupla3i(i, (i+1)%num_parts, top));
    }
}
