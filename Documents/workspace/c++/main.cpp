#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
 
int		main(int argc, char *argv[])
{
  (void) argc;
  (void) argv;

  SDL_Init(SDL_INIT_VIDEO);
  SDL_WM_SetCaption("Mon premier programme OpenGL !", NULL);
  SDL_SetVideoMode(640, 480, 32, SDL_OPENGL);

  bool		flag = true;
  SDL_Event	event;
 
  while (flag)
    {
      SDL_WaitEvent(&event);
      switch(event.type)
        {
	case SDL_QUIT:
	  flag = false;
        }
 
      glClear(GL_COLOR_BUFFER_BIT);
 
      glPointSize(10);
      glBegin(GL_POINTS);
      // Point A
      glColor3ub(0, 0, 255);
      glVertex2d(-0.5, 0.5);
      // Point B
      glColor3ub(255, 0, 0);
      glVertex2d(0.5, -0.5);
      glEnd();

      glLineWidth(3);
      glBegin(GL_LINES);
      // Point A
      glColor3ub(0, 0, 255);
      glVertex2d(-0.5, 0.5);
      // Point B
      glColor3ub(255, 0, 0);
      glVertex2d(0.5, -0.5);
      glEnd();
 
      glFlush();
      SDL_GL_SwapBuffers();
    } 
  SDL_Quit(); 
  return 0;
}
