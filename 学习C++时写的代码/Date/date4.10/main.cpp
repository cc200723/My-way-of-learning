#include<cmath>
#include <iostream>
using namespace std;
#include "Date.h"
 Date date1(1900,1,1);
 int main(){
	Date date2(2020,1,1);
	static Date date3(2010,1,2);
	const Date date4(1979,7,1);
	Date date5(date2);
    date1.isLeapYear();
    //cout<<"add one day is" ;
    //date1.addOneDay();// DateÀàĞÍ·µ»Ø 
	//date1.displayDate();
	
	//Date *date=date2.addOneDay();
	//date->displayDate(); //Date*
	
	Date &date=date2.addOneDay();
	date.displayDate();//Date&
	
	return 0;
}
