#include <iostream>
#include <fstream>
using namespace std;
#define Max 160
class Sample
{
  int A[Max] ;
  int totCnt ;
  double totPjz ;
public:
  Sample() { totCnt = 0 ; totPjz = 0.0 ; }
  void getNumber(Sample s, int &num, double &pjz) { num = s.totCnt ; pjz = s.totPjz ; }
  int getNumber(Sample s, int k) { return s.A[k] ; }
  void getdata(Sample &s) ;   // �����ݺ���
  void calValue(Sample &s) ;  // Ҫ������д�ĺ���
  void putdata(Sample &s) ;   // д�������
};
void Sample::calValue(Sample &s)
{
	int i,sw;
	double he = 0.0;
	for(i=0;i<Max;i++){
		sw=(s.A[i]%100)/10;
		if(sw==2||sw==4||sw==8)
		s.totCnt++;
		else 
		he = he+s.A[i];
	}
	s.totPjz=he/(160-s.totCnt);
		
	 
} 


int main()
{
  int num ; double pjz ;
  Sample s ;
  s.getdata(s) ;
  cout << "��ȡ����������:" << endl ;
  for(int i = 0 ; i < Max ; i++) {
    cout << s.getNumber(s, i) << " " ;
    if((i + 1) % 10 == 0) cout << endl ;
  }
  cout << endl ;
  s.calValue(s) ;
  s.putdata(s) ;
  cout << "������:" << endl ;
  s.getNumber(s, num, pjz) ;
  cout << num << endl << pjz <<  endl ;
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
  fp << s.totCnt << endl << s.totPjz << endl ;
  fp.close() ;
}

