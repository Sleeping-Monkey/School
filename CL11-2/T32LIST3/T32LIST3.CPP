/*Romanova Polina 11-2 13.11.2014*/
#include <iostream>
#include <conio.h>
#include "list.h"

using namespace std;
void main(void)
{
  int flag = 1;
  list<int> L;
  while (flag) {
    L.Display();
    cout << "0 - Exit" << endl; 
    cout << "1 - Add to Begin" << endl;
    cout << "2 - Add to End" << endl;
    cout << "3 - Delete Begin" << endl;
    cout << "4 - Delete End" << endl; 
    switch(_getch())
    {
    case '0': 
      {
        flag = 0;
        break;
      }
    case '1':
      {
        int NewData;
        cout << "Element:" << endl;
        cin >> NewData;
        L.AddBegin(NewData);
        break;
      }
    case '2':
      {
        int NewData;
        cout << "Element:" << endl;
        cin >> NewData;
        L.AddEnd(NewData);
        break;
      }
    case '3':
      {
        int Old = -1;
        L.DelBegin(&Old);
        cout << "Deleted El = " << Old << endl;
        break;
      }
    case '4':
      {
        int Old = -1;
        L.DelEnd(&Old);
        cout << "Deleted El = " << Old << endl;
        break;
      }
    }
  }
}