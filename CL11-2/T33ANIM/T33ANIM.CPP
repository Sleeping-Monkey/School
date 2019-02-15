/*Romanova Polina 11-2 4.12.2014*/
#include <time.h>
#include "anim.h"
#include <stdio.h>
void main(void)
{
  srand(time(NULL));
  glutInitWindowPosition(0,0);
  glutInitWindowSize(500,500);
  prgl::anim &MyAnim = prgl::anim::GetRef();
  for (int i = 0; i < 10; i++)
    MyAnim << new prgl::fir_tree();
  //MyAnim << new prgl::snow();
  for( int i = 0; i < 100; i++)
    MyAnim << new prgl::sphere();
  for (int i = 0; i < 10; i++)
    MyAnim << new prgl::snowman();  
  // MyAnim << new prgl::cube();
  MyAnim.Run();
}