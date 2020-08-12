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
  void getdata(Sample &s) ;  // �����ݺ���
  void funSort(Sample &s) ;  // Ҫ������д�ĺ���
  void putdata(Sample &s) ;  // д�������
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
  cout << "��ȡ����������:" << endl ;
  for(int i = 0 ; i < Max ; i++) {
    cout << s.getNumberA(s, i) << " " ;
    if((i + 1) % 10 == 0) cout << endl ;
  }
  cout << endl ;
  s.funSort(s) ;
  s.putdata(s) ;
  cout << "������:" << endl ;
  for(i = 0 ; i < 10 ; i++)
    cout << s.getNumberB(s, i) << " " ;
  cout << endl ;
}
//***********�����뿼����Ҫ�޸�************
void Sample::getdata(Sample &s)  // �������ļ��ж�ȡ����
{
  fstream fp ;
  fp.open(".\\in.dat", ios::in) ;
  for(int i = 0 ; i < Max ; i++) fp >> s.A[i] ;
  fp.close() ;
}
void Sample::putdata(Sample &s)  // д����ļ�
{
  fstream fp ;
  fp.open(".\\out.dat", ios::out) ;
  for(int i = 0 ; i < 10 ; i++) fp << s.B[i] << endl ;
  fp.close() ;
}

