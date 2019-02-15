/*Romanova Polina 11-2 13.11.2014*/
#include <iostream>

using namespace std;

template<class Type>
class list {
public:
  list & AddBegin(Type NewData)
  {
    ListStart = new entry(NewData, ListStart); 
    return *this;
  } 
  list & AddEnd(Type NewData)
  {
    entry **p = &ListStart;
    while (*p != NULL)
      p = &(*p)->Next;
    *p = new entry(NewData, NULL);
    return *this;
  }
  bool DelBegin(Type *OldData)
  {
    if (ListStart == NULL)
      return false;
    entry *p = ListStart;
    ListStart = ListStart->Next;
    if (OldData != NULL)
      *OldData = p->Data;
    delete p;
    return true;
  }
  bool DelEnd(Type *OldData)
  {
    if (ListStart == NULL)
      return false;
    entry **p = &ListStart;
    while ((*p)->Next != NULL)
      p = &(*p)->Next;
    *OldData = (*p)->Data;  
    delete *p;
    *p = NULL;
    return true;
  } 
  void Display(void) const
  {
    if (ListStart == NULL)
      cout << "Empty list\n";
    else {
      entry *L = ListStart;
      while (L != NULL) {
        cout << L->Data << (L->Next == NULL ? "\n" : ", ");
        L = L->Next;
      }
    }
  }
  list(void) : ListStart(NULL)
  {
  }
  ~list(void)
  {
    Type Old;
    while(DelEnd(&Old))
      ;
  }
private:
  class entry
  {
  public:
    Type Data;
    entry *Next;
    entry(Type &NewData, entry *NewNext) : Data(NewData), Next(NewNext)
    {
    }
  } *ListStart;
};
