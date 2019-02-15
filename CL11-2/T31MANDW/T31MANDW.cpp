/*Romanova Polina 11-2 25.09.2014*/
#include "compl.h"

void Display(void)
{
  static Frame f(1000);

  Timer();
  glClear(GL_COLOR_BUFFER_BIT);
  f.CalculateTmp();
  f.Draw();
  glFinish();
    glutSwapBuffers();
  glutPostRedisplay();
}

int main(int argc, char *argv[])
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

  glutInitWindowPosition(0,0);
  glutInitWindowSize(W,H);
  glutCreateWindow("Romanova Polina 11-2 25.09.2014");
  glutDisplayFunc(Display);
  glutMainLoop();
  return 0;
}