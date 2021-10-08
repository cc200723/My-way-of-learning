
#include <cmath>
#include <iostream>
using namespace std;

#include "Point.h" 

int Point::count=0;

 double distance(Point & p1,Point &p2){
	return  sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
	
}

 double distance(Point * p1,Point *p2){
	return sqrt((p1->x-p2->x)*(p1->x-p2->x)+(p1->y-p2->y)*(p1->y-p2->y));
	
}

Point::Point(double x1 ,double y1 ){
	//cout<<"constrcutor is run"<<endl;
	 
	setPoint(x1,y1);
	count++; 
}

Point::Point(const Point &p){
	x=p.x;
	y=p.y;
}

Point::~Point(){
	cout<<"destrcutor is run"<<endl;
	count--; 
}               
		
void Point::setPoint(double x1,double y1){
	x=x1;
	y=y1;
}

inline double Point::getX() const{
	return x;
}

inline double Point::getY() const{
	return y;
}

void Point::displayPoint() const{
	cout<<"the x is :"<<x<<";"<<"the y is :"<<y<<endl;
}

void Point::movePoint(double x1,double y1){
	x+=x1;
	y+=y1;
}

double Point::distance(Point &p2){
	//cout<<"the funtion with  reference parameter is run"<<endl;
	return  sqrt((x-p2.x)*(x-p2.x)+(y-p2.y)*(y-p2.y));
}


double Point::distance(Point * p2){
	cout<<"the funtion with  pointer parameter is run"<<endl;
	double dis=sqrt((x-p2->x)*(x-p2->x)+(y-p2->y)*(y-p2->y));
	return dis;	
	
}

int Point::getCount(){
	return count;
}






