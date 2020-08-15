// proj2.cpp
#include <iostream>
using namespace std;

class Array {
public:
  Array(int size)  // ���캯��
  {
//********found********  ������䶯̬����һ��int��������
    _p = new int[size];
    _size = size;
  }
  ~Array() { delete [] _p; }  // ��������
  void SetValue(int index, int value)  // ����ָ��Ԫ�ص�ֵ
  {
    if ( IsOutOfRange(index) ) {
      cerr << "Index out of range!" << endl;
      return;
    }
//********found********
    _p[index]=value;
  }
  int GetValue(int index) const  // ��ȡָ��Ԫ�ص�ֵ
  {
    if ( IsOutOfRange(index) ) {
      cerr << "Index out of range!" << endl;
      return -1;
    }
//********found********
     return _p[index];
  }
  int GetLength() const { return _size; }  // ��ȡԪ�ظ���
private:
  int *_p;
  int _size;
  bool IsOutOfRange(int index) const  // ��������Ƿ�Խ��
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

