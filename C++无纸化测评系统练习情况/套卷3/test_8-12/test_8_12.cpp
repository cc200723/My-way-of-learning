#include <iostream>
#include<string.h>
using namespace std;

/*class A
{
public :
    A(){
    cout<<"A";
    }

    ~A(){
    cout<<"~A";
    }
};

class B:public A
{
   A*p;
public :
    B(){
    cout<<"B";p=new A();
    }

    ~B(){
    cout<<"~B"; delete p;
    }
};

int main()
{
    B obj;
    return 0;
}*/
//ABA~B~A~A

/*class Myclass{
public:
    Myclass(int x):val(x){}
    void Print () const{
        cout<<"const:val="<<val<<'\t';
        }
    void Print () {
        cout<<"val="<<val<<'\t';
        }
private:
    int val;
};

int main(){
    const Myclass obj1(10);
    Myclass obj2(20);
    obj1.Print();
    obj2.Print();
    return 0;
}*/

//const:val=10   val=20

/*class Name{
char name[20];
public:
    Name(){
    strcpy(name," ");
    cout<<'?';
    }
    Name(char *fname){
    strcpy(name,fname);
    cout<<'?';
    }
};

int main(){
    Name names[3]={Name ("张三"),Name("李四")};
    return 0;
}*/

//???

class AA
{
public :
    AA(){
    cout<<'1';
    }
};


class BB:public AA
{
   int k;
public :
    BB():k(0){
    cout<<'2';
    }
    BB(int n):k(n){
    cout<<'3';
    }
};


int main()
{
    BB b(4),c;
    return 0;
}

//1312




