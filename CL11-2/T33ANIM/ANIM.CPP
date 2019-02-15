/*Romanove Polina 11-2 4.12.2014*/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "anim.h"
#include <iostream>

using namespace prgl;
using namespace std;

int X = 50, Y = 50;

prgl::anim prgl::anim::Instance;

prgl::anim::anim() 
{
  StackSize = 0;
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(WINDOW_W, WINDOW_H);
  glutInitWindowPosition(0, 0);

  glutCreateWindow("PRGL");

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_COLOR_MATERIAL);
  glEnable(GL_NORMALIZE);
  glEnable(GL_AUTO_NORMAL);
  glEnable(GL_DEPTH_TEST);

  glutDisplayFunc(anim::Display);
  glutReshapeFunc(anim::Reshape);
  glutKeyboardFunc(anim::Keyboard);
  glutIdleFunc(anim::Idle);
}

void prgl::anim::Display(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  vec pos(5, 50, -100), dir(0, 0, 0), up(0, 1, 0);
  SetCamera(pos, dir, up);
  
  for (int i = 0; i < Instance.StackSize; i++)
    Instance.Stack[i]->Draw();
  
  glFinish();
  glutSwapBuffers();
}

void prgl::anim::Reshape(int W, int H) 
{
  glViewport(0, 0, W, H);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(90, (double)W / H, 1, 1000);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void prgl::anim::Keyboard(unsigned char Key, int x, int y) 
{
  if (Key == 27)
    exit(0);
  if (Key == 43)
    exit(0);
  if (Key == 45)
    exit(0);
  for (int i = 0; i < Instance.StackSize; i++)
    Instance.Stack[i]->Keyboard(Key, x, y); 
}

void prgl::anim::Idle(void)
{
  static long StartTime = -1;
  if (StartTime == -1)
    StartTime = clock();
  else
    Instance.Time = (clock() - StartTime) / (double)CLOCKS_PER_SEC;

  glutPostRedisplay();
}

void prgl::anim::SetCamera(vec pos, vec dir, vec up)
{
  glLoadIdentity();
  gluLookAt(pos.x, pos.y, pos.z, dir.x, dir.y, dir.z, up.x, up.y, up.z);
}

double prgl::anim::GetTime(void)
{
  return Instance.Time;
}

prgl::fir_tree::fir_tree() : Levels(rand() % LEVELS_MAX + 1), Height(rand() % LEVELS_MAX), Pos(rand() % 100, 0, rand() % 100), Radius(rand() % 10 + 5)
{
}

void prgl::fir_tree::Draw(void)
{
  glPushMatrix();
  glTranslated(Pos.x, Pos.y, Pos.z);
  //printf("%.2lf, %.2lf, %.2lf\n", Pos.x, Pos.y, Pos.z);
  glRotated(-90, 1, 0, 0);
  glColor3d(Color.x, Color.y, Color.z);

  double sum = .0, K, R;
  for (int i = 0; i < Levels; i++)
    sum += 1 /(1 + i);
  K = Height / sum;
  R = Radius / sum;
  double angle = 30 * sin(anim::GetTime());
  for (int i = 0; i < Levels; i++)
  {
    if (i > 0)
    {
      glRotated(angle, 1, 0, 0);
      glRotated(angle, 0, 0, 1);
    }
    glutSolidCone(R / (i + 1), K / (i + 1), 10, 10);
    glTranslated(0, 0, K / (i + 1));
  }
  glPopMatrix();
}

void fir_tree::Keyboard(unsigned char Key, int x, int y) 
{
  if (Key == 'a')
    Color = vec(1, 0, 0);
  if (Key == 'b')
    Color = vec(0, 0, 1);
  if (Key == 'c')
    Color = vec(0, 1, 0);
}

void prgl::sphere::Draw(void)
{ 
  glPushMatrix();
  glTranslated(Pos.x, Pos.y, Pos.z);
  glRotated(-90, 1, 0, 0);
  double angle = 30 * sin(anim::GetTime());
  glColor3d(Color.x, Color.y, Color.z);
  glRotated(angle, 1, 0, 0);    
  glutWireSphere(Radius, 10, 10);
  //printf("%d, %d, %d\n", Pos.x, Pos.y, Pos.z);
  glPopMatrix();
  GenNextPos();
}

void sphere::Keyboard(unsigned char Key, int x, int y) 
{
  if (Key == 'a')
    Color = vec(1, 0, 0);
  if (Key == 'b')
    Color = vec(0, 0.5, 0.5);
  if (Key == 'c')
    Color = vec(1, 1, 1);
}
void sphere::GenNextPos(void)
{
  Pos.x = NextPos.x;
  Pos.y = NextPos.y;
  Pos.z = NextPos.z;
  NextPos.x = Pos.x - rand() % 5;
  NextPos.y = Pos.y + rand() % 4 - 2;
  if(Pos.x <= 0) {
    NextPos.x = 100;
    NextPos.y = rand() % 100;
  }
}
void prgl::snow::Draw(void)
{
  for (int i = 0; i < 100; i++)
    Stack[i].Draw();
}
prgl::snowman::snowman() : Levels(3), Height(rand() % 20), Pos(rand() % 100, 0, rand() % 100), Radius(rand() % 5 + 5)
{
}

void prgl::snowman::Draw(void)
{
  glPushMatrix();
  glTranslated(Pos.x, Pos.y, Pos.z);
  //printf("%.2lf, %.2lf, %.2lf\n", Pos.x, Pos.y, Pos.z);
  glRotated(-90, 1, 0, 0);
  glColor3d(Color.x, Color.y, Color.z);

  double sum = .0, K, R;
  for (int i = 0; i < Levels; i++)
    sum += 1 /(1 + i);
  K = Height / sum;
  R = Radius / sum;
  //double angle = 30 * sin(anim::GetTime());
  for (int i = 0; i < Levels; i++)
  {
   /* if (i > 0)
    {
      glRotated(angle, 1, 0, 0);
      glRotated(angle, 0, 0, 1);
    }*/
    glutSolidSphere(R / (i + 1), K / (i + 1), 10);
    glTranslated(0, 0, R / (i + 1));
  }
  glPopMatrix();
}

void snowman::Keyboard(unsigned char Key, int x, int y) 
{
  if (Key == 'a')
    Color = vec(1, 0, 0);
  if (Key == 'b')
    Color = vec(1, 1, 0.5);
  if (Key == 'c')
    Color = vec(1, 1, 1);
}

