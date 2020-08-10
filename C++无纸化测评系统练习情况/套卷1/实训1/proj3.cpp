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
  void getdata(Sample &s) ;  // �����ݺ���
  void funSort(Sample &s) ;  // Ҫ������д�ĺ���
  void putdata(Sample &s) ;  // д�������
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
  cout << "��ȡ����������:" << endl ;
  for(int i = 0 ; i < Max ; i++) {
    cout << s.getNumber(s, i) << " " ;
    if((i + 1) % 10 == 0) cout << endl ;
  }
  cout << endl ;
  s.funSort(s) ;
  s.putdata(s) ;
  cout << "������:" << endl ;
  for(i = 0 ; i < 10 ; i++)
    cout << s.getNumber(s, i) << " " ;
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
  for(int i = 0 ; i < 10 ; i++) fp << s.A[i] << endl ;
  fp.close() ;
}

