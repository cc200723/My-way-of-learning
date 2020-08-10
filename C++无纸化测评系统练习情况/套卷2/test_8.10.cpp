/*#include<iostream>
#include<string.h>
using namespace std;
int main (){
	char st [20]="hello\0\t\\";
	cout<<strlen(st);
	cout<<sizeof(st)<<endl;
	cout<<st;
}*/
/*520
hello*/
  
/*#include<iostream>
using namespace std;
class Base {
public:
	void output(){
		cout<<1;
	}
virtual void Print(){
	cout<<'B';
}
};
class Derived:public Base
{
public:
	void output(){
		cout<<2;
	}
 void Print(){
	cout<<'D';
}
};
int main(){
	Base*ptr=new Derived;
	ptr->output();
	ptr->Print();
	delete ptr;
	return 0;
}*/
//1D

#include<iostream>
using namespace std;
class XA
{
	int a;
public:
	 static int b;
	 XA(int aa):a(aa){
	 	b++;
	 }
	~XA(){}
	int get(){
		return a;
	}
};	

int XA::b=0;
int main(){
	XA d1(2),d2(3);
	cout<<d1.get()+d2.get()+XA::b<<endl;
	return 0;
}