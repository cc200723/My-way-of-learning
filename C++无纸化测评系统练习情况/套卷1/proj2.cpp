//proj2.cpp
#include <iostream>
using namespace std;

class Sort {
public:
  Sort(int* a0, int n0) : a(a0), n(n0) {}
  virtual void mySort() = 0;

  void static swap(int& x, int& y)
  {
     int tmp = x;
//**********found**********
    x=y;
     y = tmp;
  }
protected:
  int* a;
  int  n;
};

class InsertSort : public Sort {
public:
  InsertSort(int* a0, int n0)
//**********found**********
  :Sort(a0,n0)
  {
  }

  virtual void mySort()
  {
     for(int i = 1; i < n; ++i)
       for(int j = i; j > 0; --j)
         if(a[j] < a[j-1])
//**********found**********
           swap(a[j] , a[j-1]);
         else 
//**********found**********
           break;
  }
};

void fun(Sort& s) { s.mySort(); }

void print(int *a, int n)
{
  for(int i = 0; i < n; ++i)
    cout << a[i] << ", ";
  cout << endl;
}

int main(int argc, char *argv[])
{
  int a[] = {5, 1, 7, 3, 1, 6, 9, 4, 2, 8, 6};

  cout << "Before sorting a[]= \n";
  print(a, 11);

  InsertSort bs(a, 11);
  fun(bs);

  cout << "After sorting a[]= \n";
  print(a, 11);

  return 0;
}

