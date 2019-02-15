/*Romanova Polina 16.04.2015*/
#ifndef __LAB_H

#define __LAB_H

#include "anim.h"
#include <vector>
#include <algorithm>
#include <glut.h>
#include <stdlib.h>

#define Max 100

namespace prgl
{
	class lab : public object
	{
	public :
		int Wall[Max][Max], Wbfs[Max][Max];
		std::vector <int> Queue;
		int W, H;

		lab() : W(0), H(0)
		{
			for (int i = 0; i < Max; i++)
				for (int j = 0; j < Max; j++)
					Wall[i][j] = 0;
		};
		bool Load(anim &Anim, char *FileName);
		lab(anim &Anim, char *FileName) : W(0), H(0)
		{
			Load(Anim, FileName);
		};
		void StartBfs(int x, int y); 
		void bfs(int id);
		void Draw(void);
		int CheckWall(int x, int y);
		void GoWall(int x1, int y1, int x2, int y2, int k);
	};
	class ball : public object
	{
	public:
		double Radius, Up;
		vec Pos;
		lab *Table;
		void Draw(void);
		ball(vec Pos, double R, lab *T) : Radius(R), Up(0), Table(T)
		{
			this->Pos = Pos;
		}
		void Keyboard(unsigned char Key, int x, int y);
	};
	class ballE : public object
	{
	public:
		double Radius, Up;
		vec Pos;
		lab *Table;
		void Draw(void);
		ballE(vec Pos, double R, lab *T) : Radius(R), Up(0), Table(T)
		{
			this->Pos = Pos;
		}
		void GenPos();
		void Keyboard(unsigned char Key, int x, int y);
	};
};

#endif
