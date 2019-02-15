//Romanova Polina 10-2

#include <glut.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include "m.h"

void LoadTexImage(char *FileName)
{
  FILE *F;
  void *image;
  int W = 0, H = 0;

  if((F=fopen(FileName,"rb")) != NULL)
  {
    fread(&W, 2, 1, F);
    fread(&H, 2, 1, F);
    if((image = malloc(3*H*W)) != NULL)
    {
       fread(image, 1, 3*H*W, F);
       gluBuild2DMipmaps(GL_TEXTURE_2D, 3, W, H, GL_BGR_EXT, GL_UNSIGNED_BYTE, image);
       free(image);
    }
    fclose(F);
  }
}

void CutCone1(double h0, double h1, double s0, double s1, int n)
{
  double i, x, z, nx=h1-h0, ny=s1-s0, angle, Pi=3.14159265358979323846;
  glEnable(GL_NORMALIZE);
  angle=2*Pi/n;
  glBegin(GL_TRIANGLE_STRIP);
  for(i=0;i<=n;i++)
  {
    x = cos(angle*i);
    z = sin(angle*i);
    glNormal3d(x*nx, ny, z*nx);
    glVertex3d(x*s1, h1, z*s1);
    glVertex3d(x*s0, h0, z*s0);
  }
  glEnd();
}

void CutCone2(double h0, double h1, double s0, double s1, int n)
{
  double x, z, nx=h1-h0, ny=s1-s0, angle, Pi=3.14159265358979323846;
  int i;
  glEnable(GL_NORMALIZE);
  angle=2*Pi/n;
  glBegin(GL_TRIANGLE_STRIP);
  for(i=0;i<n;i++)
  {
    x = cos(angle*i);
    z = sin(angle*i);
    glNormal3d(x*nx, ny, z*nx);
    glVertex3d(x*s1, h1+0.5*(i%2), z*s1);
    glVertex3d(x*s0, h0, z*s0);
  }
  glEnd();
}

void WirdMill(double y,double h,double s0,double s1)
{
  int i;
  glPushMatrix();
  CutCone1(y-1,y,s0, s0, 4);
  CutCone1(y, y+h, s0, s1, 4);
  CutCone1(y+h, y+h+0.5, s1+0.5, 0, 4);
  glTranslated(0, y+h, 0);
  glRotated(90, 0, 0, 1);
  glRotated(40, 1, 0, 0);
  glRotated(360*SyncTime, 0, 1, 0);
  CutCone1(y, y+h, 0.05, 0.05, 30);
  glBegin(GL_TRIANGLES);
  
    glVertex3d(0,y+h,0);
    glVertex3d(1, y+h, 0);
    glVertex3d(0.5, y+h, sqrt(3)/2.0); 
  
    glRotated(120, 1, 0 , 0);

    glVertex3d(0,y+h,0);
    glVertex3d(1, y+h, 0);
    glVertex3d(0.5, y+h, sqrt(3)/2.0); 

    glRotated(120, 1, 0 , 0);

    glVertex3d(0,y+h,0);
    glVertex3d(1, y+h, 0);
    glVertex3d(0.5, y+h, sqrt(3)/2.0); 
  glEnd();
  glPopMatrix();
}
void Fence(double y, double h, double s0, double s1)
{
   CutCone2(y, h, s0, s1, 35);  
}
void Pig()
{

}
void Birdy()
{

}