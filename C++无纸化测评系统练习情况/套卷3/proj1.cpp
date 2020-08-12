//proj1.cpp
#include <iostream>
using namespace std;
class Member
{
public:
  Member(int x) { val=x; }
  int GetData() { return val; }
private:
// ERROR  ********found********
  int val;
};

class MyClass
{
public:
// ERROR  ********found********
  MyClass(int x):data(x){}
  void Print()
// ERROR  ********found********
  { cout<<"The value of member object is "<<data.GetData()<<endl; }
private:
  Member data;
};

int main()
{
  MyClass obj(8);
  obj.Print();
  return 0;
}
