#ifndef DATE_H
#define DATE_H
class Date{
	
	public:
		Date(int =1900,int =1,int =1);
		Date(Date &);//���쿽������ 
		~Date();//�������� 
		void setDate(int ,int ,int ); //��������������Ч����֤ 
	  inline int getYear()const;
	  inline int getMonth()const;//��ʾ������������ 
	  inline int getDay()const;
		
		void displayDate()const;//����Ա���� 
	    //void addOneDay();//����һ�� (Date ���ͷ��أ�
		 //Date* addOneDay(); 
		 Date& addOneDay();
		
		bool isLeapYear();	//�ж��Ƿ�Ϊ����
		 
	
	
	private:
		int year;
	    int month;
	    int day;
};
#endif
