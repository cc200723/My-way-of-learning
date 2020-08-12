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
  T& operator[](int) ;  // �����±������
  void operator=(T) ;   // ���صȺ������
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
  Array<int> arr1(n) ;  // ����������ģ���༰�����arr1
  Array<char> arr2(n) ; // �����ַ���ģ���༰�����arr2
  for(i = 0 ; i < n ; i++)
  {
    arr1[i] = 'a' + i ; // �������������
    arr2[i] = 'a' + i ;
  }
  cout << "  ASCII��   �ַ�" << endl ;
  for( i = 0 ; i < n ; i++) cout << setw(8) << arr1[i] << setw(8) << arr2[i] << endl ;
}

