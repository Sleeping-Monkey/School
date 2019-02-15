/*Romanova Polina 10-2 01.04.2014*/
#include <glut.h>
#include <time.h>

double SyncTime;

void Timer(void)
{
  long t;
  static long StartTime=-1;
  t=clock();
  if(StartTime == -1)
    StartTime=t;
  SyncTime=(double)(t-StartTime)/CLOCKS_PER_SEC;
}


void Display(void)
{
  int i=11;
  
  
  Timer();
  glClear(GL_COLOR_BUFFER_BIT);
  
  glLoadIdentity();

  for(;i>0;i--)
  {
    glRotated(SyncTime*30*(11-i), 0,0,1);
    glColor3d((i%2),1,i%3);
    glRectd(0,0,0.5,0.3);
    glTranslated(0.5,0.3,0);
    glScaled((double)i/11, (double)i/11,0);
    glRotated((11-i)*10, 0,0,1);
  }
  glFinish();
  glutSwapBuffers();
  glutPostRedisplay(); 
}

int main(int argc, char *argv[])
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

  glutInitWindowPosition(0,0);
  glutInitWindowSize(500,500);
  glutCreateWindow("Romanova Polina 10-2 01.04.2014");
  glutDisplayFunc(Display);
  glutMainLoop();
return 0;
}