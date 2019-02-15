/*Romanova Polina 11-2 25.09.2014*/
#include <glut.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <time.h>

#define byte unsigned char 
#define ys 2.0
#define xs 2.0
#define H 500
#define W 500

using namespace std;

double SyncTime;

void Timer(void)
{
  long t;
  static long StartTime = -1;
  t = clock();
  if(StartTime == -1)
    StartTime = t;
  SyncTime = (double)(t - StartTime) / CLOCKS_PER_SEC;
}

struct Compl {
  double Re, Im;
  Compl() {}
  Compl(double a) : Re(a), Im(0)
  {}
  Compl(double a, double b) : Re(a), Im(b)
  {}
  Compl operator+(const Compl & z)
  {
    return Compl(Re + z.Re, Im + z.Im);
  }
  Compl operator*(const Compl & z)
  {
    return Compl(Re * z.Re - Im * z.Im, Re * z.Im + Im * z.Re);
  }
  double operator!(void)
  {
    return sqrt(Re * Re + Im * Im);
  }
  int Julia(const Compl &C)
  {
    int n = 0;
    Compl z(Re, Im);
    while(n < 254 && !z <= 2) {
      z = z * z + C;
      n++;
    }
    return n;
  }
};

template <class T1, class T2>
T1 Lepr(T1 A, T1 B, T2 t)
{
  return (1 - t) * A + B * t;
}


struct Frame {
  //const int W, H;
  byte StartImagew[H][W][4], FinishImagew[H][W][4], TmpImagew[H][W][4];
  int Transision_Frames, FrameT;
  
  Frame(int Time) : Transision_Frames(Time), FrameT(0)
  {
    for (int x = 0; x < W; x++) {
      for (int y = 0; y < H; y++) {
        double xc = 2 * xs * x / W - xs, yc = 2 * ys * y / H - ys;
        Compl z = Compl(xc, yc);
        int n = z.Julia(0.4);
        PutPixel(x, y, n, n * n, n * n * n);
        n = z.Julia(0.4 * sin(SyncTime * 10));
        PutPixelFinish(x, y, n, n * n, n * n * n);
      }
    }
  }
  
  void Draw(void) 
  {
    glDrawPixels(W, H, GL_BGRA_EXT, GL_UNSIGNED_BYTE, TmpImagew);
  }

  void Calculate(double c)
  {
    for (int x = 0; x < W; x++) {
      for (int y = 0; y < H; y++) {
        double xc = 2 * xs * x / W - xs, yc = 2 * ys * y / H - ys;
        Compl z = Compl(xc, yc);
        int n = z.Julia(c);
        PutPixelFinish(x, y, n * n * n, n * n * n, n * n * n);
      }
    }
  }

  void CalculateTmp(void)
  {
    for (int x = 0; x < W; x++) {
      for (int y = 0; y < H; y++) {
        byte rn = Lepr<byte, double>(StartImagew[y][x][0], 
          FinishImagew[y][x][0], 1.0 * FrameT / Transision_Frames);
        byte gn = Lepr<byte, double>(StartImagew[y][x][1], 
          FinishImagew[y][x][1], 1.0 * FrameT / Transision_Frames);
        byte bn = Lepr<byte, double>(StartImagew[y][x][2], 
          FinishImagew[y][x][2], 1.0 * FrameT / Transision_Frames);
        PutPixelTmp(x, y, rn, gn, bn);
      }
    }
    FrameT++;
    if (FrameT == Transision_Frames) {
      Swap();
      FrameT = 0;
      Calculate(sin(SyncTime) + SyncTime * 0.3);
    }
  }

  void PutPixel(int x, int y, byte r, byte g, byte b)
  {
    StartImagew[y][x][0] = r;
    StartImagew[y][x][1] = g;
    StartImagew[y][x][2] = b;
  }

  void PutPixelFinish(int x, int y, byte r, byte g, byte b)
  {
    FinishImagew[y][x][0] = r;
    FinishImagew[y][x][1] = g;
    FinishImagew[y][x][2] = b;
  }

  void PutPixelTmp(int x, int y, byte r, byte g, byte b)
  {
    TmpImagew[y][x][0] = r;
    TmpImagew[y][x][1] = g;
    TmpImagew[y][x][2] = b;
  }

  void Swap(void)
  {
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        for (int k = 0; k < 4; k++) {
          TmpImagew[i][j][k] = FinishImagew[i][j][k];
          FinishImagew[i][j][k] = StartImagew[i][j][k];
          StartImagew[i][j][k] = TmpImagew[i][j][k];
        }
      }
    }
  }
};

void Display(void);
