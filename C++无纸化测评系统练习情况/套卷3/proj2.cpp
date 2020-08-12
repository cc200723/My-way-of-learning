#include <iostream>
#include <iomanip>
using namespace std;
template <class T>
class Array
{
  T *elems ;
  int size ;
public:
  Array(int s) ;
  ~Array() ;
  T& operator[](int) ;  // 重载下标运算符
  void operator=(T) ;   // 重载等号运算符
};
template <class T> Array<T>::Array(int s)
{
  size = s ;
//**********found**********
elems = new T[size] ;
  for(int i = 0 ; i < size ; i++) elems[i] = 0 ;
}
template <class T> Array<T>::~Array()
{
//**********found**********
 delete elems ;
}
template <class T> T& Array<T>::operator[](int index)
{
//**********found**********
 return elems [index];
}
template <class T>void Array<T>::operator=(T temp)
{
  for(int i = 0 ; i < size ; i++)
//**********found**********
   elems[i] = temp ;

}
int main()
{
  int i, n = 10 ;
  Array<int> arr1(n) ;  // 产生整数型模板类及其对象arr1
  Array<char> arr2(n) ; // 产生字符型模板类及其对象arr2
  for(i = 0 ; i < n ; i++)
  {
    arr1[i] = 'a' + i ; // 调用重载运算符
    arr2[i] = 'a' + i ;
  }
  cout << "  ASCII码   字符" << endl ;
  for( i = 0 ; i < n ; i++) cout << setw(8) << arr1[i] << setw(8) << arr2[i] << endl ;
}

