/*Romanova Polina 11-2 16.04.2015*/
#include <time.h>
#include "anim.h"
#include <stdio.h>
#include "lab.h"
#include <iostream>

void main(void)
{
	srand(time(NULL));
	glutInitWindowPosition(0,0);
	glutInitWindowSize(500,500);
	prgl::anim &MyAnim = prgl::anim::GetRef();
	MyAnim << new prgl::lab(MyAnim, "lab.txt"); 
	
	MyAnim.Run();
}