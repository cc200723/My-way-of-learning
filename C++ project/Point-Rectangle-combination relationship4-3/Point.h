#ifndef POINT_H
#define POINT_H
class Point{
	
	friend double distance(Point &,Point &);	//	友元函数实现求两点之间的距离
	friend double distance(Point *,Point *);	//	友元函数实现求两点之间的距离
	public:
		Point(double =0,double =0);
        Point(const Point &);
        ~Point(); 
               
		void setPoint(double,double);
        inline double getX() const;
        inline double getY() const;

        void displayPoint() const;
        void movePoint(double =0,double=0);//点的平移操作
        //重载求距离函数，形参类型不同
		double distance(Point &);	//	成员函数实现 求两点之间的距离
        double distance(Point *);	//	成员函数实现 求两点之间的距离
        
        static int getCount();//静态成员函数 
	private:
		double x;//横坐标
		double y;//纵坐标
		
		static int count;//静态数据成员 
};

#endif
