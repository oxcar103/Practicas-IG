// *********************************************************************
// **
// ** Informática Gráfica, curso 2015-16
// ** Práctica 2  (implementación)
// **
// *********************************************************************

#include "MallasPLY.hpp"

MallaPLY::MallaPLY(const char * nombre_arch){
    nombre_obj = "Malla generada por .PLY";

    std::vector<float> vertices_ply;    // coordenadas de vértices
    std::vector<int> faces_ply;         // índices de vértices de triángulos

    ply::read(nombre_arch, vertices_ply, faces_ply);    // Lectura del archivo .ply

    // Vertices
    for(unsigned int i = 0; i < vertices_ply.size(); i += 3){
        vertices.push_back(Tupla3f (vertices_ply[i], vertices_ply[i+1], vertices_ply[i+2]));
    }

    // Faces
    for(unsigned int i = 0; i < faces_ply.size(); i += 3){
        faces.push_back(Tupla3i (faces_ply[i], faces_ply[i+1], faces_ply[i+2]));
    }
}
