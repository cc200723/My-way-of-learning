#include <iostream>
#include <fstream>
using namespace std;
#define Max 200
class Sample
{
  int A[Max] ;
  double B[10] ;
public:
  Sample()
  {
    for(int i = 0 ; i < 10 ; i++) B[i] = 0 ;
  }
  int getNumberA(Sample s, int k) { return s.A[k] ; }
  double getNumberB(Sample s, int k) { return s.B[k] ; }
  void getdata(Sample &s) ;  // 读数据函数
  void funSort(Sample &s) ;  // 要求考生编写的函数
  void putdata(Sample &s) ;  // 写结果函数
};
void Sample::funSort(Sample &s)
{
  int i,j=0, cnt=0;
  double val=0.0;
  for(int i = 0 ; i < Max ; i++) {
   cnt++;
   val += s.A[i];
   if(cnt%20==0){
   s.B[j++]=val/20;
   val=0;
   }
}
for(i = 0 ; i < 10 ; i++)
for(j = i+1 ; j < 10 ; j++)
if(s.B[i]>s.B[j]){
	val=s.B[i];
	s.B[i]=s.B[j];
	s.B[j]=val;
}
}
int main()
{
  int i;
  Sample s ;
  s.getdata(s) ;
  cout << "读取的数据如下:" << endl ;
  for(int i = 0 ; i < Max ; i++) {
    cout << s.getNumberA(s, i) << " " ;
    if((i + 1) % 10 == 0) cout << endl ;
  }
  cout << endl ;
  s.funSort(s) ;
  s.putdata(s) ;
  cout << "输出结果:" << endl ;
  for(i = 0 ; i < 10 ; i++)
    cout << s.getNumberB(s, i) << " " ;
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
  for(int i = 0 ; i < 10 ; i++) fp << s.B[i] << endl ;
  fp.close() ;
}

