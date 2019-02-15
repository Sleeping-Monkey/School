/*Romanova Polina 11-2 16.04.2015*/
#include "lab.h"
#include "anim.h"
#include <glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <windows.h>
#include <iostream>

#define CELL_SIZE 10
#define Inf 1e9
using namespace prgl;
using namespace std;

bool lab::Load(anim &Anim, char *FileName)
{
	FILE *F = fopen(FileName, "rt");
	if (F == NULL)
		return false;
	int N, M;
	char Buf[2000];
	fgets(Buf, sizeof(Buf), F);
	sscanf(Buf, "%i%i", &N, &M);
	for (int i = 0; i < N; i++)
	{
		if (fgets(Buf, sizeof(Buf), F) == NULL)
			break;
		for (int j = 0; j < M && Buf[j] != 0 && Buf[j] != '\n'; j++)
			if (Buf[j] == ' ')
				Wall[i][j] = 0;
			else if (Buf[j] == 'S') {
				Anim << new ball(vec((j + 0.5) * CELL_SIZE, CELL_SIZE / 2.0, (i + 0.5) * CELL_SIZE), CELL_SIZE / 2.0, this);
				Wall[i][j] = 2;
			} else if (Buf[j] == 'E') {
				Anim << new ballE(vec((j + 0.5) * CELL_SIZE, CELL_SIZE / 2.0, (i + 0.5) * CELL_SIZE), CELL_SIZE / 2.0, this);
				Wall[i][j] = 3;
			}
			else {
				Wall[i][j] = 1;
			}
	}
	W = M;
	H = N;
	fclose(F);
	return true;
}

void lab::Draw(void)
{
	glLineWidth(2);
	glColor3d(1, 0, 0);
	glBegin(GL_LINES);
	for (int i = 0; i <= H; i++)
	{
		glVertex3d(0, 0, i * CELL_SIZE);
		glVertex3d(W * CELL_SIZE, 0, i * CELL_SIZE);
	}
	for (int i = 0; i <= W; i++)
	{
		glVertex3d(i * CELL_SIZE, 0, 0);
		glVertex3d(i * CELL_SIZE, 0, H * CELL_SIZE);
	}
	glEnd();
	glPushMatrix();
	glTranslated(CELL_SIZE / 2.0, 0, CELL_SIZE / 2.0);
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++)
			if (Wall[i][j] == 1) {
				glutSolidCube(CELL_SIZE);
				glTranslated(CELL_SIZE, 0, 0);
			} else {
				glTranslated(CELL_SIZE, 0, 0);
			}
			glTranslated(- W * CELL_SIZE, 0, CELL_SIZE);
	}
	glPopMatrix();
}

int lab::CheckWall(int x, int y)
{
	return Wall[x][y];
}

void lab::GoWall(int x1, int y1, int x2, int y2, int k)
{
	Wall[x1][y1] = 0;
	if (Wall[x2][y2] == 2 && k == 3) {
		std::cout << "Game Over!" << std::endl;
		int msgboxID = MessageBox(NULL, (LPCSTR)("Play again?"), (LPCSTR)("Game Over!"), MB_ICONQUESTION | MB_YESNO);
		if (msgboxID == IDYES) {
			
			return;
		} else
			exit(0);
	}
	Wall[x2][y2] = k;
}

void lab::StartBfs(int x, int y)
{
	for (int i = 0; i < W; i++)
		for (int j = 0; j < H; j++)
			Wbfs[i][j] = Inf;
	Queue.push_back(x);
	Queue.push_back(y);
	Queue.push_back(0);
	bfs(0);
	Queue.clear();
}

void lab::bfs(int id)
{
	if (id == Queue.size())
		return;
	int x = Queue[id];
	int y = Queue[id + 1];
	int len = Queue[id + 2];
	Wbfs[x][y] = len;
	if (Wall[x - 1][y] != 1 && Wbfs[x - 1][y] == Inf) {
		Queue.push_back(x - 1);
		Queue.push_back(y);
		Queue.push_back(len + 1);
	}
	if (Wall[x + 1][y] != 1 && Wbfs[x + 1][y] == Inf) {
		Queue.push_back(x + 1);
		Queue.push_back(y);
		Queue.push_back(len + 1);
	}
	if (Wall[x][y - 1] != 1 && Wbfs[x][y - 1] == Inf) {
		Queue.push_back(x);
		Queue.push_back(y - 1);
		Queue.push_back(len + 1);
	}
	if (Wall[x][y + 1] != 1 && Wbfs[x][y + 1] == Inf) {
		Queue.push_back(x);
		Queue.push_back(y + 1);
		Queue.push_back(len + 1);
	}
	bfs(id + 3);
}

void ball::Draw(void)
{ 
  glPushMatrix();
  glTranslated(Pos.x, Pos.y, Pos.z);
  glRotated(-90, 1, 0, 0);
  double angle = CELL_SIZE * sin(20 * anim::GetTime()) / 2.0;
  glColor3d(Color.x, Color.y, Color.z);
  glRotated(angle, 1, 0, 0);
  glTranslated(0, 0, angle);
  glutSolidSphere(Radius, 10, 10);
  //printf("%d, %d, %d\n", Pos.x, Pos.y, Pos.z);
  glPopMatrix();
}


void ball::Keyboard(unsigned char Key, int x, int y) 
{
	if (Key == 'a')
		Color = vec(1, 0.75, 0);
	if (Key == 'b')
		Color = vec(0.5, 0.5, 0.5);
	if (Key == 'c')
		Color = vec(1, 0, 1);
	if (Key == '8' && !Table->CheckWall((Pos.z + CELL_SIZE) / CELL_SIZE, Pos.x / CELL_SIZE)) {
		Table->GoWall(Pos.z / CELL_SIZE, Pos.x / CELL_SIZE, (Pos.z + CELL_SIZE) / CELL_SIZE, Pos.x / CELL_SIZE, 2);
		Pos.z += CELL_SIZE;
		Table->StartBfs(Pos.z / CELL_SIZE, Pos.x / CELL_SIZE);
	}
	if (Key == '2' && !Table->CheckWall((Pos.z - CELL_SIZE) / CELL_SIZE, Pos.x / CELL_SIZE)) {
		Table->GoWall(Pos.z / CELL_SIZE, Pos.x / CELL_SIZE, (Pos.z - CELL_SIZE) / CELL_SIZE, Pos.x / CELL_SIZE, 2);
		Pos.z -= CELL_SIZE;
		Table->StartBfs(Pos.z / CELL_SIZE, Pos.x / CELL_SIZE);
	}
	if (Key == '4' && !Table->CheckWall(Pos.z / CELL_SIZE, (Pos.x + CELL_SIZE) / CELL_SIZE)) {
		Table->GoWall(Pos.z / CELL_SIZE, Pos.x / CELL_SIZE, Pos.z / CELL_SIZE, (Pos.x + CELL_SIZE) / CELL_SIZE, 2);
		Pos.x += CELL_SIZE;
		Table->StartBfs(Pos.z / CELL_SIZE, Pos.x / CELL_SIZE);
	}
	if (Key == '6' && !Table->CheckWall(Pos.z / CELL_SIZE, (Pos.x - CELL_SIZE) / CELL_SIZE)) {
		Table->GoWall(Pos.z / CELL_SIZE, Pos.x / CELL_SIZE, Pos.z / CELL_SIZE, (Pos.x - CELL_SIZE) / CELL_SIZE, 2);
		Pos.x -= CELL_SIZE;
		Table->StartBfs(Pos.z / CELL_SIZE, Pos.x / CELL_SIZE);
	}
}

void ballE::Draw(void)
{ 
  glPushMatrix();
  glTranslated(Pos.x, Pos.y, Pos.z);
  glRotated(-90, 1, 0, 0);
  double angle = CELL_SIZE * sin(20 * anim::GetTime()) / 2.0;
  glColor3d(Color.x, Color.y, Color.z + sin(anim::GetTime()) / (cos(anim::GetTime()) + 2));
  glRotated(angle, 1, 0, 0);
  glTranslated(0, 0, angle);
  glutSolidSphere(Radius, 10, 10);
  //printf("%d, %d, %d\n", Pos.x, Pos.y, Pos.z);
  glPopMatrix();
  if (int(anim::GetTime() * 1000) % 50 == 0)
	  GenPos();
}

void ballE::GenPos()
{
	if (Table->Wbfs[int((Pos.z + CELL_SIZE) / CELL_SIZE)][int(Pos.x / CELL_SIZE)] < Table->Wbfs[int(Pos.z / CELL_SIZE)][int(Pos.x / CELL_SIZE)]) {
		Table->GoWall(Pos.z / CELL_SIZE, Pos.x / CELL_SIZE, (Pos.z + CELL_SIZE) / CELL_SIZE, Pos.x / CELL_SIZE, 3);
		Pos.z += CELL_SIZE;		
		return;
	}
	if (Table->Wbfs[int((Pos.z - CELL_SIZE) / CELL_SIZE)][int(Pos.x / CELL_SIZE)] < Table->Wbfs[int(Pos.z / CELL_SIZE)][int(Pos.x / CELL_SIZE)]) {
		Table->GoWall(Pos.z / CELL_SIZE, Pos.x / CELL_SIZE, (Pos.z - CELL_SIZE) / CELL_SIZE, Pos.x / CELL_SIZE, 3);
		Pos.z -= CELL_SIZE;		
		return;
	}
	if (Table->Wbfs[int(Pos.z / CELL_SIZE)][int(Pos.x / CELL_SIZE) + 1] < Table->Wbfs[int(Pos.z / CELL_SIZE)][int(Pos.x / CELL_SIZE)]) {
		Table->GoWall(Pos.z / CELL_SIZE, Pos.x / CELL_SIZE, Pos.z / CELL_SIZE, (Pos.x + CELL_SIZE) / CELL_SIZE, 3);
		Pos.x += CELL_SIZE;		
		return;
	}
	if (Table->Wbfs[int(Pos.z / CELL_SIZE)][int(Pos.x / CELL_SIZE) - 1] < Table->Wbfs[int(Pos.z / CELL_SIZE)][int(Pos.x / CELL_SIZE)]) {
		Table->GoWall(Pos.z / CELL_SIZE, Pos.x / CELL_SIZE, Pos.z / CELL_SIZE, (Pos.x - CELL_SIZE) / CELL_SIZE, 3);
		Pos.x -= CELL_SIZE;		
		return;
	}
}

void ballE::Keyboard(unsigned char Key, int x, int y) 
{
	if (Key == 'a')
		Color = vec(0, 1, 0);
	if (Key == 'b')
		Color = vec(0, 1, 0);
	if (Key == 'c')
		Color = vec(0, 1, 0);
}
