/*Romanova Polina 10-2 08.04.2014*/

#include <glut.h>
#include <time.h>
#include <math.h>
double SyncTime, W, H;


void Keyboard(unsigned char Key)
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
  glOrtho(-sx,sx,-sy,sy,-10,10);
  glMatrixMode(GL_MODELVIEW);
}

void Display(void)
{
  int i=9;
  Timer();
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
  SetProj(500,500);
 // gluLookAt(2,2,2,0,0,0,0,1,0);
  glScaled(0.30,0.30,0.30);
  for(i;i>0;i--)
  {
      glPushMatrix();
      glRotated(40*SyncTime+40*i, 0, 0, 1);
      glTranslated(1, fabs(cos(SyncTime*(i%2)-i))/1.0, 0);
      glRotated(120*SyncTime, 0, 1, 0);
      glColor3d(i/10.0, i%2, 0);
      switch(i)
      {
      case 9:
        glutWireTeapot(0.30);
      case 8:
        glScaled(0.30,0.30,0.30);
        glutWireIcosahedron();
      case 7:
        glutWireCone(0.20, 0.30, 5, 10);
      case 6:
        glutWireSphere(0.30, 5, 10);
      case 5:
        glutWireTorus(0.15, 0.20, 10, 5);
      case 4:
        glScaled(0.30,0.30,0.30);
        glutWireTetrahedron();
      case 3:
        glScaled(0.30,0.30,0.30);
        glutWireDodecahedron();
      case 2:
        glScaled(0.30,0.30,0.30);
        glutWireOctahedron();
      case 1:
        glutWireCube(0.30);
      glPopMatrix();
      }
  }
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
  glutCreateWindow("Romanova Polina 10-2 08.04.2014");
  glutDisplayFunc(Display);
  glutKeyboardFunc(Keyboard);
  glutMainLoop();
  
return 0;
}