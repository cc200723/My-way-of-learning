// proj2.cpp
#include <iostream>
using namespace std;
class CharShape {
public:
  CharShape(char ch) : _ch(ch) {};
  virtual void Show() = 0;
protected:
  char _ch;   // 组成图形的字符
};
class Triangle : public CharShape {
public:
  Triangle(char ch, int r) : CharShape(ch), _rows(r) {}
  void Show();
private:
  int _rows;  // 行数
};
class Rectangle: public CharShape {
public:
  Rectangle(char ch, int r, int c):CharShape(ch),_rows(r), _cols(c) {}
  void Show();
private:
  int _rows, _cols;   // 行数和列数
};
void Triangle::Show()  // 输出字符组成的三角形
{
  for (int i = 1; i <= _rows; i++) {
//********found********
    for (int j = 1; j <=2*i-1; j++)
      cout << _ch;
    cout << endl;
  }
}

void Rectangle::Show()  // 输出字符组成的矩形
{
//********found********
  for (int i = 1; i <=_rows; i++) {
//********found********
    for (int j = 1; j <= _cols; j++)
      cout << _ch;
    cout << endl;
  }
}

//********found********  为fun函数添加形参
void fun(CharShape &cs) { cs.Show(); }
int main()
{
  Triangle tri('*', 4);
  Rectangle rect('#', 3, 8);
  fun(tri);
  fun(rect);
  return 0;
}

