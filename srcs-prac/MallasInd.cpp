// *********************************************************************
// **
// ** Informática Gráfica, curso 2015-16
// ** Práctica 1  (implementación)
// **
// *********************************************************************

#include "MallasInd.hpp"
#include "aux.hpp"

void MallaInd::visualizar(unsigned modo_vis){
    GLenum modo;

    switch (modo_vis){
        case 0:
            modo = GL_POINTS;
            break;
        case 1:
            modo = GL_LINE_LOOP;
            break;
        default:
            modo = GL_TRIANGLES;
    }

        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, &vertices[0]);
    for(unsigned int i = 0; i < faces.size(); i++){
        if(modo_vis == 3 && i % 2 == 0)
            glColor3f(1, 1, 0);
        else
            glColor3f(0.5, 0, 0.75);
    
        glDrawElements(modo, 3, GL_UNSIGNED_INT, &faces[i]);

        
    }
        glDisableClientState(GL_VERTEX_ARRAY);
}
