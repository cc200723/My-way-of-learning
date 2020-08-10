// proj2.cpp
#include <iostream>
using namespace std;
class CharShape {
public:
  CharShape(char ch) : _ch(ch) {};
  virtual void Show() = 0;
protected:
  char _ch;   // ���ͼ�ε��ַ�
};
class Triangle : public CharShape {
public:
  Triangle(char ch, int r) : CharShape(ch), _rows(r) {}
  void Show();
private:
  int _rows;  // ����
};
class Rectangle: public CharShape {
public:
  Rectangle(char ch, int r, int c):CharShape(ch),_rows(r), _cols(c) {}
  void Show();
private:
  int _rows, _cols;   // ����������
};
void Triangle::Show()  // ����ַ���ɵ�������
{
  for (int i = 1; i <= _rows; i++) {
//********found********
    for (int j = 1; j <=2*i-1; j++)
      cout << _ch;
    cout << endl;
  }
}

void Rectangle::Show()  // ����ַ���ɵľ���
{
//********found********
  for (int i = 1; i <=_rows; i++) {
//********found********
    for (int j = 1; j <= _cols; j++)
      cout << _ch;
    cout << endl;
  }
}

//********found********  Ϊfun��������β�
void fun(CharShape &cs) { cs.Show(); }
int main()
{
  Triangle tri('*', 4);
  Rectangle rect('#', 3, 8);
  fun(tri);
  fun(rect);
  return 0;
}

