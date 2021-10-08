#include "Point.h"

#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle{
	public:
		Rectangle(Point &,double ,double );
		Rectangle(Rectangle &);
		~Rectangle();
		
		void setRectangle(Point &,double ,double );//长宽要求为正数
		Point getLeftPoint() const;
		double getWidth() const;
		double getlength() const;
		
		void displayRectangle() const;//输出矩形的左上角坐标和长宽		
		double areaRectangle();//面积 
		double perimeterRectangle();//周长 
		void moveRectangle(double ,double); 		
		
	private:
		//重点：左上角坐标，此数据成员为Point类的对象，so Point类和Rectangle类构成了组合关系 
		Point leftPoint;
		double width;//宽 
		double length;//长 
};

#endif
