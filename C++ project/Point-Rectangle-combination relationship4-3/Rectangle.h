#include "Point.h"

#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle{
	public:
		Rectangle(Point &,double ,double );
		Rectangle(Rectangle &);
		~Rectangle();
		
		void setRectangle(Point &,double ,double );//����Ҫ��Ϊ����
		Point getLeftPoint() const;
		double getWidth() const;
		double getlength() const;
		
		void displayRectangle() const;//������ε����Ͻ�����ͳ���		
		double areaRectangle();//��� 
		double perimeterRectangle();//�ܳ� 
		void moveRectangle(double ,double); 		
		
	private:
		//�ص㣺���Ͻ����꣬�����ݳ�ԱΪPoint��Ķ���so Point���Rectangle�๹������Ϲ�ϵ 
		Point leftPoint;
		double width;//�� 
		double length;//�� 
};

#endif
