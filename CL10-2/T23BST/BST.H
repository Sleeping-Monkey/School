#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


typedef struct tagTREE TREE;
struct tagTREE
{
 int Key;
 TREE *Less, *More;
};

int AccessTree(TREE **T, int key);
int AccessTree2(TREE **T, int key);
void DrawTree(TREE *T, int level);
void PutTree(TREE *T);
void ClearTree(TREE **T);
void AddToTree(TREE **T, int n);
void PT(TREE *T, FILE F);
void SaveTree(TREE *T, char *fname);
void RTree(TREE **T, char *fname);
int Linearize(TREE **T);
void BalanceTree(TREE **T, int n);
void Del(TREE **T, int key);