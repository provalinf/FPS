#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cstdlib>
#include <math.h>

void Dessiner();

double angleZ = 0;
double angleY = 0;
double centerX = 0;
float theta, phi =0;

int main(int argc, char *argv[])
{
    SDL_Event event;
    Uint8 *keystates = SDL_GetKeyState( NULL );
    SDL_Init(SDL_INIT_VIDEO);
    atexit(SDL_Quit);
    SDL_WM_SetCaption("SDL GL Application", NULL);
    SDL_SetVideoMode(640, 480, 32, SDL_OPENGL);

    SDL_EnableKeyRepeat(300,10);
    SDL_WM_GrabInput(SDL_GRAB_ON);
    SDL_ShowCursor(SDL_DISABLE);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective(70,(double)640/480,1,1000);

    glEnable(GL_DEPTH_TEST);

    Uint32 last_time = SDL_GetTicks();
    Uint32 current_time,ellapsed_time;
    Uint32 start_time;

    for (;;)
    {
        start_time = SDL_GetTicks();
        current_time = SDL_GetTicks();
        ellapsed_time = current_time - last_time;
        last_time = current_time;

          while (SDL_PollEvent(&event))
          {
              if(SDL_MOUSEMOTION==event.type)centerX = event.motion.xrel*0.1;
              if(SDL_KEYDOWN==event.type)
              {
                if(SDLK_ESCAPE==event.key.keysym.sym)exit(0);
                if(SDLK_LEFT==event.key.keysym.sym)
                {
                    angleZ += 0.05* ellapsed_time;
                }
                if(SDLK_RIGHT==event.key.keysym.sym)angleZ -= 0.05* ellapsed_time;
                if(SDLK_UP==event.key.keysym.sym)angleY -= 0.05* ellapsed_time;
                if(SDLK_DOWN==event.key.keysym.sym)angleY += 0.05* ellapsed_time;
              }




            switch(event.type)
            {
                case SDL_QUIT:
                exit(0);
                break;
                case SDL_MOUSEMOTION:
                centerX = event.motion.xrel*0.1;
                break;
                case SDL_KEYUP:
                break;
                case SDL_KEYDOWN:
                if(SDLK_LEFT==event.key.keysym.sym)angleZ += 0.05* ellapsed_time;
                if(SDLK_RIGHT==event.key.keysym.sym)angleZ -= 0.05* ellapsed_time;
                if(SDLK_UP==event.key.keysym.sym)angleY -= 0.05* ellapsed_time;
                if(SDLK_DOWN==event.key.keysym.sym)angleY += 0.05* ellapsed_time;

//                switch (event.key.keysym.sym)
//                {
//                    case SDLK_LEFT:
//                    angleZ += 0.05* ellapsed_time;
//                    break;
//                    case SDLK_RIGHT:
//                    angleZ -= 0.05* ellapsed_time;
//                    break;
//                    case SDLK_UP:
//                    angleY -= 0.05* ellapsed_time;
//                    break;
//                    case SDLK_DOWN:
//                    angleY += 0.05* ellapsed_time;
//                    break;
//                    case SDLK_LEFT&&SDLK_UP:
//                    angleZ += 0.05* ellapsed_time;
//                    angleY -= 0.05* ellapsed_time;
//                    break;
//                    default:
//                    exit(0);
//                }
            }
        }

        Dessiner();

        ellapsed_time = SDL_GetTicks() - start_time;
        if (ellapsed_time < 10)
        {
            SDL_Delay(10 - ellapsed_time);
        }

    }

    return 0;
}

void Dessiner()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    gluLookAt(angleY,0,0,0,0,centerX,0,0,1);
    glTranslated(0,angleZ,0);

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

    glColor3ub(0,5,60); //sol
    glVertex3d(100,100,-1);
    glVertex3d(100,-100,-1);
    glVertex3d(-100,-100,-1);
    glVertex3d(-100,100,-1);

    glEnd();

    glFlush();
    SDL_GL_SwapBuffers();
}
