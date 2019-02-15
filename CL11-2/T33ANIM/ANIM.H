/*Romanova Polina 11-2 4.12.2014*/
#include <glut.h>
#include <stdlib.h>


#define WINDOW_W 500
#define WINDOW_H 500

#define STACK_SIZE 500
#define LEVELS_MAX 10


namespace prgl
{
  class vec
  {
  public:
    double x, y, z;

    vec() : x(0), y(0), z(0)
    {
    }
    vec(double x, double y, double z) : x(x), y(y), z(z)
    {
    }
  };

  class object
  {
  public:
    vec Color;

    virtual void Draw(void)
    {
    }
    virtual void Keyboard(unsigned char Key, int x, int y)
    {
    }
    object()
    {
    }
  };

  class sphere : public object
  {
  public:
    double Radius;
    vec Pos, NextPos;
 
    void Draw(void);
    void GenNextPos(void);
    sphere() : Radius(0.5 + rand() % 50 / 100), Pos(vec(50 - rand() % 100, 50 - rand() % 100, rand() % 100 + 3))
    {
      NextPos.x = Pos.x - rand() % 10;
      NextPos.y = Pos.y + rand() % 20 - 10;
    }
    sphere(double r) : Radius(r)
    {
    }
    sphere(double r, vec p) : Radius(r), Pos(p), NextPos(p)
    {
    }
    void Keyboard(unsigned char Key, int x, int y);
  };

  class fir_tree : public object
  {
  public:
    double Height, Radius;
    vec Pos;
    int Levels;
   
    fir_tree();
    void Draw(void);
    void Keyboard(unsigned char Key, int x, int y);
  };  

  class snow : public sphere 
  {
  public:
    sphere Stack[100];
    void Draw(void);
    snow()
    {
      for (int i = 0; i < 100; i++) {
        sphere a;
        Stack[i] = a;
      }
    }
  }; 
  class snowman : public object
  {
    public:
    double Height, Radius;
    vec Pos;
    int Levels;
    snowman();
    void Draw(void);
    void Keyboard(unsigned char Key, int x, int y);
  };
  class anim
  {
  private:
    static void Reshape(int W, int H);
    static void Display(void);
    static void Idle(void);
    static void Keyboard(unsigned char Key, int x, int y);
    
    anim();
    
    static anim Instance;
  
  public:
    object *Stack[STACK_SIZE];
    int StackSize;
    double Time;

    void Run(void)
    {
      glutMainLoop();
    }
    static anim & GetRef(void)
    {
      return Instance;
    }

    static void SetCamera(vec pos, vec dir, vec up);
    static double GetTime(void);

    anim & operator << (object *o)
    {
      if (StackSize != STACK_SIZE)
        Stack[StackSize++] = o;
      return *this;
    }
  };
}
    