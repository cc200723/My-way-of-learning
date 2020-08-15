// proj1.cpp
#include <iostream>
using namespace std;

class MyClass {
    char * p;
public:
  MyClass(char c) { p = new char;  *p = c; }
// ERROR  ********found********
  MyClass(const MyClass& copy) { p = new char;  *p = *(copy.p); }
// ERROR  ********found********  下列析构函数用于释放字符指针
  ~MyClass() { delete p; }
  MyClass& operator=(const MyClass & rhs)
  {
    if ( this == &rhs ) return *this;
    *p = *(rhs.p);
// ERROR  ********found********
    return *this;
  }
  char GetChar() const { return *p; }
};

int main()
{
  MyClass obj1('C'), obj2('P');
  MyClass obj3(obj1);
  obj3 = obj2;
  cout << "The extension is: "
       << obj1.GetChar() << obj2.GetChar()
       << obj3.GetChar() << endl;
  return 0;
}

