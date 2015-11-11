// *********************************************************************
// **
// ** Informática Gráfica, curso 2015-16
// ** Práctica 1  (implementación)
// **
// *********************************************************************

#include "Cube.hpp"

/* Cube:
 *
 *       v4----------v0
 *      /|           /|
 *     / |          / |
 *    v5-----------v1 |
 *    |  |  (0,0)  |  |
 *    |  |    ·    |  |
 *    |  |v6-------|--|v2
 *    |  /         | /
 *    | /          |/
 *    v7-----------v3
 */

Cube::Cube(double size){
    double x, y , z = y = x = size / 2.0;

    nombre_obj = "Cubo";

    // Vertices
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                vertices.push_back(Tupla3f (x, y, z));

                z *= -1;
            }

            y *= -1;
        }

        x *= -1;
    }

    // Faces
    faces.push_back(Tupla3i (0, 1, 2));
    faces.push_back(Tupla3i (1, 3, 2));
    faces.push_back(Tupla3i (0, 1, 4));
    faces.push_back(Tupla3i (1, 4, 5));
    faces.push_back(Tupla3i (1, 3, 5));
    faces.push_back(Tupla3i (5, 7, 3));
    faces.push_back(Tupla3i (2, 3, 6));
    faces.push_back(Tupla3i (3, 7, 6));
    faces.push_back(Tupla3i (0, 2, 4));
    faces.push_back(Tupla3i (6, 2, 4));
    faces.push_back(Tupla3i (4, 6, 5));
    faces.push_back(Tupla3i (6, 5, 7));    
}
