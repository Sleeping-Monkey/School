/*Romanova Polina 10-2 22.04.2014*/

#include <glut.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include "m.h"

void Keyboard(unsigned char Key, int X, int Y)
{
  if(Key==27)
    exit(0);
}

void Timer(void)
{
  long t;
  static long StartTime=-1;
  t=clock();
  if(StartTime == -1)
    StartTime=t;
  SyncTime=(double)(t-StartTime)/CLOCKS_PER_SEC;
}
 
void SetProj(int W, int H)
{
  double sx=1, sy=1;
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  if(W>H)
    sx=(double)W/H;
  else
    sy=(double)H/W;
  glOrtho(-sx*5,sx*5,-sy*5,sy*5,-50,50);
  glMatrixMode(GL_MODELVIEW);
}  


void Display(void)
{
  Timer();
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  //glBindTexture(GL_TEXTURE_2D, TexNames[0]);
/*  glEnable(GL_TEXTURE_2D);
  glBegin(GL_QUADS);
  glTexCoord2d(0,0);
  glVertex3d(0, 0, 0);
  glTexCoord2d(1,0);
  glVertex3d(0, 1, 0);
  glTexCoord2d(1,1);
  glVertex3d(1, 1, 0);
  glTexCoord2d(0,1);
  glVertex3d(1, 0, 0);
  glEnd();   */
  SetProj(500,500);
  gluLookAt(2,2,2,0,0,0,0,1,0);
  glRotated(40*SyncTime, 0, 1, 0);
  glColor3d(0,1,0);
  WirdMill(0, 2, 2, 1);
  glColor3d(1, 0, 0);
  glRotated(40*SyncTime, 0, 1, 0);
  Fence(0, 1, 5, 5);  
  glFinish();
  glutSwapBuffers();
  glutPostRedisplay(); 
  
}

int main(int argc, char *argv[])
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowPosition(0,0);
  glutInitWindowSize(500,500);
  glutCreateWindow("Romanova Polina 10-2 22.04.2014");
  glGenTextures(4, TexNames);
  glBindTexture(GL_TEXTURE_2D, TexNames[0]);
  LoadTexImage("X:\\PICS\\M.G24");

  glEnable(GL_DEPTH_TEST);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_COLOR_MATERIAL);
  glEnable(GL_NORMALIZE);

  glutDisplayFunc(Display);
  glutKeyboardFunc(Keyboard);
  glutMainLoop();
  
return 0;
}