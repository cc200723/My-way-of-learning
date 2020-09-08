#ifndef DATE_H
#define DATE_H
class Date{
	
	public:
		Date(int =1900,int =1,int =1);
		Date(Date &);//构造拷贝函数 
		~Date();//析构函数 
		void setDate(int ,int ,int ); //对输入日期做有效性验证 
	  inline int getYear()const;
	  inline int getMonth()const;//显示定义内联函数 
	  inline int getDay()const;
		
		void displayDate()const;//常成员函数 
	    //void addOneDay();//增加一天 (Date 类型返回）
		 //Date* addOneDay(); 
		 Date& addOneDay();
		
		bool isLeapYear();	//判断是否为闰年
		 
	
	
	private:
		int year;
	    int month;
	    int day;
};
#endif
