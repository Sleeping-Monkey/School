/*Romanove Polina 11-2 4.12.2014*/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "anim.h"
#include <iostream>

#define CELL_SIZE 10
using namespace prgl;
using namespace std;

vec Alf(vec(0, 0, 1));

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
	glutSpecialFunc(anim::SpecialKeyboard);
  glutIdleFunc(anim::Idle);
}

void prgl::anim::Display(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  vec pos(1, 50, -100), dir(0, 0, 0), up(0, 1, 0);
  SetCamera(pos, dir, up);
	glRotated(Alf.x, 0, 1, 0);
	glRotated(Alf.y, 0, 1, 0);
	glScaled(Alf.z, Alf.z, Alf.z); 
	glBegin(GL_POLYGON);
		glColor3d(1, 0, 0);
		glVertex3d(-1000, 0, -1000);
		glVertex3d(1000, 0, -1000);
		glVertex3d(1000, 0, 1000);
		glVertex3d(-1000, 0, 1000);
	glEnd();
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
	if (Key == 'q') {
		glutFullScreen();
		Reshape(WINDOW_W, WINDOW_H);	
	}
	for (int i = 0; i < Instance.StackSize; i++)
    Instance.Stack[i]->Keyboard(Key, x, y); 
}

void prgl::anim::SpecialKeyboard(int Key, int x, int y)
{
	if (Key == GLUT_KEY_LEFT)
			Alf.x -= 5;
	if (Key == GLUT_KEY_RIGHT)
		Alf.x += 5;	
	if (Key == GLUT_KEY_DOWN)
		Alf.z -= 0.1;
	if (Key == GLUT_KEY_UP)
		Alf.z += 0.1;
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

prgl::fir_tree::fir_tree() : Levels(rand() % LEVELS_MAX + 1), Height(rand() % LEVELS_MAX), Pos(rand() % 100, 0, rand() % 100), Radius(rand() % 15 + 5)
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
  double angle = 5 * sin(anim::GetTime());
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
  glutSolidSphere(Radius, 10, 10);
  //printf("%d, %d, %d\n", Pos.x, Pos.y, Pos.z);
  glPopMatrix();
}

void sphere::Keyboard(unsigned char Key, int x, int y) 
{
  if (Key == 'a')
    Color = vec(1, 0, 0);
  if (Key == 'b')
    Color = vec(0, 0.5, 0.5);
  if (Key == 'c')
    Color = vec(1, 1, 1);
	if (Key == 't')
		Up = 1- Up;
}


prgl::snowman::snowman() : Levels(3), Height(rand() % 20), Pos(rand() % 100, 0, rand() % 100), Radius(rand() % 5 + 5)
{
}

void prgl::snowman::Draw(void)
{
  glPushMatrix();
  glTranslated(Pos.x, Pos.y, Pos.z);
  glRotated(-90, 1, 0, 0);
  glColor3d(Color.x, Color.y, Color.z);

  double sum = .0, K, R;
  K = Height;
  R = Radius;
  for (int i = 0; i < Levels; i++)
  {
    glutSolidSphere(R, K, 10);
    glTranslated(0, 0, R + R/2.0 - 0.2);
		R = R/2.0;
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

void prgl::santa::Draw(void)
{ 
  glPushMatrix();
  glTranslated(50, 50, 50);
  double angle = 360 * sin(anim::GetTime());
  glRotated(angle, 0, 1, 0);
  glTranslated(Pos.x, Pos.y, Pos.z);
  glRotated(angle, 0, 1, 0);
  glColor3d(Color.x, Color.y, Color.z);
  glutSolidSphere(Radius, 10, 10);
  glTranslated(Radius, 2*Radius / 5, 0);
  glColor3d(1,1,0);
  glutSolidSphere(Radius / 4.5, 10, 10);
  glTranslated(-Radius, 0, 0);
  glRotated(50, 0, 1, 0);
  glTranslated(Radius, 0, 0);
  glutSolidSphere(Radius / 5.0, 10, 10);
  glPopMatrix();
}

void santa::Keyboard(unsigned char Key, int x, int y) 
{
  if (Key == 'a')
    Color = vec(1, 0, 0);
  if (Key == 'b')
    Color = vec(1, 0, 0.1);
  if (Key == 'c')
    Color = vec(1, 0, 0);
}