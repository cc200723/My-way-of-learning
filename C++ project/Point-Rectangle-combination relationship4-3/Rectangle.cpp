#include <iostream>
using namespace std;
#include "Point.h"
#include "Rectangle.h" 

Rectangle::Rectangle(Point &p,double width1,double length1):leftPoint(p)
{
	setRectangle(p,width1,length1);
}

Rectangle::Rectangle(Rectangle &r1)
{
	width=r1.width;
	length=r1.length;
	cout<<"Rectangle object copy_constructor: "<<endl;
}

Rectangle::~Rectangle()
{
	cout<<"Rectangle object destructor "<<endl;
}

void Rectangle::setRectangle(Point &p,double width1,double length1)
{
	
	while(1)
	{
		if(width1>0&&length1>0)
		{
			width=width1;
			length=length1;
			break;
		}
		else
		{
			cout<<"Please input again:"<<endl;
			cin>>width1>>length1;
		} 
	}
}
Point Rectangle::getLeftPoint() const
{ 
	return leftPoint;
}
 
double Rectangle::getWidth() const
{
	return width;
}

double Rectangle::getlength() const
{
	return length;
}

void Rectangle::displayRectangle() const
{
	cout<<"width="<<width<<" length="<<length<<"  ";
	cout<<"leftPoint";
	leftPoint.displayPoint();	
}

double Rectangle::areaRectangle()
{
	return(width*length);
}

double Rectangle::perimeterRectangle()
{
	return(2*(width+length));
}

void Rectangle::moveRectangle(double sideways,double lengthways)
{
	leftPoint.movePoint(sideways,lengthways);
	cout<<"width="<<width<<" length="<<length<<endl;

}

