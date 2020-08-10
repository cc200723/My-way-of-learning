// proj1.cpp
#include <iostream>
using namespace std;

class MyClass {
public:
// ERROR  **********found**********
 MyClass(int i = 0) :value (i) 

  { count++; }
  void Print()
  { cout << "There are " << count << " object(s)." << endl; }
private:
  const int value;
  static int count;
};
// ERROR  **********found**********
 int MyClass::count = 0;
int main()
{
  MyClass obj1, obj2;
// ERROR  **********found**********
 obj1.Print();
  return 0;
}

