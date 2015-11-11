// *********************************************************************
// **
// ** Informática Gráfica, curso 2015-16
// ** Práctica 1  (implementación)
// **
// *********************************************************************

#include "Cylinder.hpp"

/* Cylinder(12 parts):
 *       v9 v7 v5
 *   v11_.-----._v3
 *  v13-   .v25  -v1
 *    |-_       _-|
 *    |  ~-----~  |
 *    |     ·(0,0)|
 *    |           |
 *  v12._   ·v24_.v0
 *    v14"-----"v22
 *     v16 v18 v20
 */

Cylinder::Cylinder(double height, double radius, int num_parts){
    double angle, y = height/2.0;
    int top, bottom;

    nombre_obj = "Cilindro";

    if(num_parts < 3)
        num_parts = 3;

    angle = 2*M_PI/(num_parts*1.0);

    // Vertices
    for(int i = 0; i < num_parts; i++){
        vertices.push_back(Tupla3f (radius*cos(i*angle), -y, radius*sin(i*angle)));
        vertices.push_back(Tupla3f (radius*cos(i*angle), y, radius*sin(i*angle)));
    }

    // Bottom center
    vertices.push_back(Tupla3f (0, -y, 0));
    bottom = vertices.size()-1;
    
    // Top center
    vertices.push_back(Tupla3f (0, y, 0));
    top = vertices.size()-1;

    // Faces
    // Side
    for(int i = 0; i < num_parts*2; i++){
        faces.push_back(Tupla3i(i, (i+1)%(2*num_parts), (i+2)%(2*num_parts)));
    }

    // Bottom
    for(int i = 0; i < num_parts*2; i+=2){
        faces.push_back(Tupla3i(i, (i+2)%(2*num_parts), bottom));
    }

    // Top
    for(int i = 1; i < num_parts*2; i+=2){
        faces.push_back(Tupla3i(i, (i+2)%(2*num_parts), top));
    }
}
