#include <iostream>
#include "Point.h"
#include "Rectangle.h" 
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//主函数中定义点类对象，矩形类对象，分别调用相对应的成员函数 
int main() {
	Point p1,p2(1,1);
	cout<<p1.distance(&p2)<<endl;
	cout<<"sideways=2,lengthways=2 "<<endl;
	p2.movePoint(2,2);
	
	Rectangle r1(p2,6,2);
	r1.displayRectangle();
	cout<<"The perimeterof the rectangle is "<<r1.perimeterRectangle()<<endl;
	cout<<"The area of the rectangle is "<<r1.areaRectangle()<<endl;
	cout<<"sideways=3,lengthways=4 "<<endl;
	r1.moveRectangle(3,4);
	return 0;
}
