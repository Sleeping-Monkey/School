#include <stdio.h>

double SyncTime;
unsigned int TexNames[4];

void LoadTexImage(char *FileName);
void Keyboard(unsigned char Key, int X, int Y);
void CutCone1(double h0, double h1, double s0, double s1, int n);
void CutCone2(double h0, double h1, double s0, double s1, int n);
void WirdMill(double y, double h, double s0, double s1);
void Fence(double y, double h, double s0, double s1);
void Pig();
void Birdy();