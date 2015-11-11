// *********************************************************************
// **
// ** Informática Gráfica, curso 2015-16
// ** Práctica 1  (implementación)
// **
// *********************************************************************

#include "MallasRevol.hpp"
#include <math.h>

MallaRevol::MallaRevol(const char * nombre_arch = "ant.ply", unsigned num_rev){
    unsigned int top, bottom, num_vert;
    double angle_rot, angle_ini, radius;

    // Establecemos un valor mínimo para num_rev
    if(num_rev < 3)
        num_rev = 3;

    angle_rot = 2*M_PI/(num_rev*1.0);

    nombre_obj = "Malla generada por revolución";

    std::vector<float> vertices_ply;    // coordenadas de vértices

    ply::read_vertices(nombre_arch, vertices_ply);    // Lectura del archivo .ply

    num_vert = vertices_ply.size() / 3;

    // Vertices
    for(unsigned int i = 0; i < 3 * num_vert; i += 3){
        radius = sqrt(pow(vertices_ply[i],2) + pow(vertices_ply[i+2],2));
        angle_ini = atan(vertices_ply[i+2]/vertices_ply[i]);

        for(unsigned int j = 0; j < num_rev; j++)
            vertices.push_back(Tupla3f (radius*cos(j*angle_rot + angle_ini), vertices_ply[i+1], radius*sin(j*angle_rot + angle_ini)));
    }

    // Para nombrarlos supongo que el primer punto es el más bajo y el último es el más alto,
    // pero si no fuese así, a efectos de visualización, no afectaría.
    vertices.push_back(Tupla3f (0, vertices_ply[1], 0));
    bottom = vertices.size()-1;
    vertices.push_back(Tupla3f (0, vertices_ply[vertices_ply.size()-2], 0));
    top = vertices.size()-1;

    // Faces
    // Side
    for(unsigned int i = 0; i < num_vert - 1; i++){        
        for(unsigned int j = 0; j < num_rev; j++){
            faces.push_back(Tupla3i (i*num_rev+j, i*num_rev + (j+1)%num_rev, (i+1)*num_rev + j));
            faces.push_back(Tupla3i (i*num_rev + (j+1)%num_rev, (i+1)*num_rev + j, (i+1)*num_rev + (j+1)%num_rev));
        }
    }

    // Bottom
    for(unsigned int i = 0; i < num_rev; i++){
        faces.push_back(Tupla3i(i, (i+1) % num_rev, bottom));
    }

    // Top
    for(unsigned int i = 0; i < num_rev; i++){
        faces.push_back(Tupla3i(num_rev*(num_vert-1) + i, num_rev*(num_vert-1) + (i+1) % num_rev, top));
    }
}
