#include<iostream>
#include<string.h>
using namespace std;

//狗的颜色：黑、白、黄、褐、花、其他
enum DOGCOLOR{BLACK, WHITE, YELLOW, BROWN, PIEBALD, OTHER};

class Dog{  //狗类
  DOGCOLOR color;
  char name[20];
  static int count;
public:
  Dog(char name[], DOGCOLOR color){
    strcpy(this->name,name);
    // ERROR **********found**********
    this->color=color;
  }
  DOGCOLOR getColor()const{ return color; }
    // ERROR **********found**********
    const char* getName()const{ return name; }
    const char* getColorString()const{
      switch(color){
        case BLACK: return "black";
        case WHITE: return "white";
        case YELLOW: return "yellow";
        case BROWN: return "brown";
        case PIEBALD: return "piebald";
      }
      return "motley";
  }
  void show()const{
    cout<<"There is a "<<getColorString()<<" dog named "<<name<<'.'<<endl;
  }
};

int main(){
// ERROR **********found**********
  Dog dog1("Hoho", WHITE), dog2("Haha", BLACK), dog3("Hihi", OTHER);
  dog1.show();
  dog2.show();
  dog3.show();
  return 0;
}
