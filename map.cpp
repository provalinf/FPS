#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cstdlib>
#include <math.h>
#include "map.h"

    void MapJeu::CreateFloor(int maplength)
    {
      glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
      glMatrixMode( GL_MODELVIEW );
      glLoadIdentity( );

      glBegin(GL_QUADS);

      //glColor3ub(0,255,0);
      glVertex3d(maplength,maplength,0);
      glVertex3d(maplength,-maplength,0);
      glVertex3d(-maplength,-maplength,0);
      glVertex3d(-maplength,maplength,0);
      glEnd();
      glFlush();
      SDL_GL_SwapBuffers();
    }

    void MapJeu::CreateCube(int x, int y, int CubeLength)
    {
        glBegin(GL_QUADS);

        glColor3ub(255,0,0); //face rouge
        glVertex3d(1,1,1);
        glVertex3d(1,1,-1);
        glVertex3d(-1,1,-1);
        glVertex3d(-1,1,1);

        glColor3ub(0,255,0); //face verte
        glVertex3d(1,-1,1);
        glVertex3d(1,-1,-1);
        glVertex3d(1,1,-1);
        glVertex3d(1,1,1);

        glColor3ub(0,0,255); //face bleue
        glVertex3d(-1,-1,1);
        glVertex3d(-1,-1,-1);
        glVertex3d(1,-1,-1);
        glVertex3d(1,-1,1);

        glColor3ub(255,255,0); //face jaune
        glVertex3d(-1,1,1);
        glVertex3d(-1,1,-1);
        glVertex3d(-1,-1,-1);
        glVertex3d(-1,-1,1);

        glColor3ub(0,255,255); //face cyan
        glVertex3d(1,1,-1);
        glVertex3d(1,-1,-1);
        glVertex3d(-1,-1,-1);
        glVertex3d(-1,1,-1);

        glColor3ub(255,0,255); //face magenta
        glVertex3d(1,-1,1);
        glVertex3d(1,1,1);
        glVertex3d(-1,1,1);
        glVertex3d(-1,-1,1);

        glColor3ub(255,255,0); //face jaune
        glVertex3d(-1,1,1);
        glVertex3d(-1,1,-1);
        glVertex3d(-1,-1,-1);
        glVertex3d(-1,-1,1);

        glEnd();
        glFlush();
        SDL_GL_SwapBuffers();
    }
