// *********************************************************************
// **
// ** Informática Gráfica, curso 2015-16
// ** Práctica 2  (declaraciones públicas)
// **
// *********************************************************************

#ifndef MALLASREVOL_HPP
#define MALLASREVOL_HPP

#include "MallasInd.hpp"
#include "file_ply_stl.hpp"
 
// clase mallas indexadas obtenidas de un archivo PLY
class MallaRevol : public MallaInd{
   public:
      // constructor
      // se debe especificar: el nombre completo del archivo a leer
      //                      el número de copias del perfil
      
      MallaRevol(const char * nombre_arch, unsigned num_rev = 103); 
};
#endif
