// *********************************************************************
// **
// ** Informática Gráfica, curso 2015-16
// ** Práctica 1  (implementación)
// **
// *********************************************************************

#include "Tetrahedron.hpp"
#include <math.h>

/* Tetrahedron:
 *                              v0
 *                             ,|,
 *                           ,7``\'VA,
 *                         ,7`   |, `'VA,
 *                       ,7`     `\    `'VA,
 *                     ,7`        |,      `'VA,
 *                   ,7`          `\         `'VA,
 *                 ,7`             |,           `'VA,
 *               ,7`               `\       ,..ooOOTK` v1
 *             ,7`                  |,.ooOOT''`    AV
 *           ,7`            ,..ooOOT`\`           /7
 *         ,7`      ,..ooOOT''`      |,          AV
 *        ,T,..ooOOT''`              `\         /7
 *    v3 `'TTs.,                      |,       AV
 *            `'TTs.,                 `\      /7
 *                 `'TTs.,             |,    AV
 *                      `'TTs.,        `\   /7
 *                           `'TTs.,    |, AV
 *                                `'TTs.,\/7
 *                                     `'T`
 *                                        v2
 */

Tetrahedron::Tetrahedron(double size){
    // Para dejar el origen de coordenadas centrado en el triángulo base
    double dist = 2 * sqrt(pow(size, 2) + pow(size / 2.0, 2)) / 3.0;    // Distancia del centro de un triángulo equilátero a los lados
    double x = dist * cos (2*M_PI/3);                                   // Coordenada x de v2
    double z = dist * sin (2*M_PI/3);                                   // Coordenada z de v2
    double y = sqrt(pow(size, 2) - pow(dist, 2));                       // Coordenada y de v0

    nombre_obj = "Tetraedro";

    // Vertices
    vertices.push_back(Tupla3f(0, y, 0));
    vertices.push_back(Tupla3f(dist, 0, 0));
    vertices.push_back(Tupla3f(x, 0, z));
    vertices.push_back(Tupla3f(x, 0, -z));                             // v3 es conjugado de v2

    // Faces
    faces.push_back(Tupla3i(0, 1, 2));
    faces.push_back(Tupla3i(0, 1, 3));
    faces.push_back(Tupla3i(0, 2, 3));
    faces.push_back(Tupla3i(1, 2, 3));
}

