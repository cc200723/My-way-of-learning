#include <iostream>
#include <fstream>
using namespace std;
#define Max 200
class Sample
{
  int A[Max] ;
public:
  Sample() {}
  int getNumber(Sample s, int k) { return s.A[k] ; }
  void getdata(Sample &s) ;  // 读数据函数
  void funSort(Sample &s) ;  // 要求考生编写的函数
  void putdata(Sample &s) ;  // 写结果函数
};
void Sample::funSort(Sample &s)
{
  int i,j,t;
  for(j=0;j<Max-1;j++)
  {
  	  for(i=0;i<Max-1-j;i++)
  	  {
  	  	  if(s.A[i]>s.A[i+1])
  	  	  {
  	  	  	t=s.A[i];
  	  	  	s.A[i]=s.A[i+1];
  	  	  	s.A[i+1]=t;
		  }
	  }
  } 
}

int main()
{
  int i;
  Sample s ;
  s.getdata(s) ;
  cout << "读取的数据如下:" << endl ;
  for(int i = 0 ; i < Max ; i++) {
    cout << s.getNumber(s, i) << " " ;
    if((i + 1) % 10 == 0) cout << endl ;
  }
  cout << endl ;
  s.funSort(s) ;
  s.putdata(s) ;
  cout << "输出结果:" << endl ;
  for(i = 0 ; i < 10 ; i++)
    cout << s.getNumber(s, i) << " " ;
  cout << endl ;
}
//***********以下请考生不要修改************
void Sample::getdata(Sample &s)  // 从数据文件中读取数据
{
  fstream fp ;
  fp.open(".\\in.dat", ios::in) ;
  for(int i = 0 ; i < Max ; i++) fp >> s.A[i] ;
  fp.close() ;
}
void Sample::putdata(Sample &s)  // 写结果文件
{
  fstream fp ;
  fp.open(".\\out.dat", ios::out) ;
  for(int i = 0 ; i < 10 ; i++) fp << s.A[i] << endl ;
  fp.close() ;
}

