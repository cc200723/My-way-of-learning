// proj2.cpp
#include <iostream>
using namespace std;

class Array {
public:
  Array(int size)  // 构造函数
  {
//********found********  下列语句动态分配一个int类型数组
    _p = new int[size];
    _size = size;
  }
  ~Array() { delete [] _p; }  // 析构函数
  void SetValue(int index, int value)  // 设置指定元素的值
  {
    if ( IsOutOfRange(index) ) {
      cerr << "Index out of range!" << endl;
      return;
    }
//********found********
    _p[index]=value;
  }
  int GetValue(int index) const  // 获取指定元素的值
  {
    if ( IsOutOfRange(index) ) {
      cerr << "Index out of range!" << endl;
      return -1;
    }
//********found********
     return _p[index];
  }
  int GetLength() const { return _size; }  // 获取元素个数
private:
  int *_p;
  int _size;
  bool IsOutOfRange(int index) const  // 检查索引是否越界
  {
//********found********
    if (index < 0 || index>= _size)
      return true;
    else return false;
  }
};

int main()
{
  Array a(10);
  for (int i = 0; i < a.GetLength(); i++)
    a.SetValue(i, i+1);
  for (int j = 0; j <  a.GetLength()-1; j++)
    cout << a.GetValue(j) << ", ";
  cout << a.GetValue(a.GetLength()-1) << endl;
  return 0;
}

