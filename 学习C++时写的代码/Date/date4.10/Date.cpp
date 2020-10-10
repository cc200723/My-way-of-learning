#include<cmath>
#include<iostream>
using namespace std;
#include "Date.h"

Date::Date(int y,int m,int d)
{
	setDate( y, m, d);
	cout<<"constructor"<<year<<"-"<<month<<"-"<<day<<endl;
}

Date::Date(Date & date2)
{ 
	year=date2.year;
	month=date2.month;
	day=date2.day;
	cout<<"copy_constructor"<<year<<"-"<<month<<"-"<<day<<endl;
}

Date::~Date()
{
	cout<<"destructor"<<year<<"-"<<month<<"-"<<day<<endl;
}

void Date::setDate(int y,int m,int d)
{
	int days;
	switch(m)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        days = 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        days = 30;
        break;
    case 2:
    	if((y%4==0&&y%100!=0)||(y%400==0))
    	{
    		days=29;
		}
    	else days=28; 
        break;
    }
     //cout<<"days="<<days<<endl; 
	 if(y<1900 || m<=0||m>12 || d<=0||d>days)
	 {
        cout<<"Error invalid date"<<endl;
        exit(-1);
     }
     else
	 {
	 	year=y;
     	month=m;
     	day=d; 
	 }
}

inline int Date::getYear()const
{
	return year;
}

inline int Date::getMonth()const
{
	return month;
}

inline int Date::getDay()const
{
	return day;
}



bool Date::isLeapYear()
    {
      
	if((year%4==0&&year%100!=0)||(year%400==0))
	{
		cout<<year<<" is a leap year "<<endl;
		return true;	
	}
	else
	 {
		cout<<year<<" is not a leap year "<<endl; 
		return false;
     }
   } 

/*void Date::addOneDay()
{
	switch(month)
	{
		case 1:
    	case 3:
    	case 5:
    	case 7:
    	case 8:
    	case 10:
    		{
    			if(day<31)
    			{
    				day++;
				}
				else
				{
					day = 1;
					month++;
				}
			}break;
		case 2:
			{
				if((year%4==0&&year%100!=0)||(year%400==0))
				{
					if(day<29)
					{
							day++;
					}		
					else 
					{
						day = 1;
						month++;
					}
				}
				else
				{
					if(day<28)
						day++;
					else
					{
						day = 1;
						month++;
					}	
				}
			}break;	
		case 12:
			{
				if(day<31)
					day++;
				else
				{
					day=1;
					month=1;
					year++;
				}	
			}break;
		case 4:
		case 6:
		case 9:
			{
				if(day<30)
					day++;
				else
				{
					day=1;
					month++;
				}
			}break;
	}          
  cout<<getYear()<<"-"<<getMonth()<<"-"<<getDay()<<endl;
} */ 
//void Date::addOneDay() 
//Date*Date::addOneDay()
Date&Date::addOneDay()
{
	if((month==2&&day==29)||((year%4!=0||(year%100==0&&year%400!=0))&&month==2&&day==28))
	{
		day=1;
		month++; 
	}
	else if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
	{
		if(month==12&&day==31)
		{ 
		  year++;
		  month=1;
		  day=1;	
		}
		else if(day==31)
		{
		  month++;
		  day=1;	
		}
		else 
		{
			day++;
		}
		//cout<<getYear()<<"-"<<getMonth()<<"-"<<getDay()<<endl;
		return this; 
	}
}
void Date::displayDate()const
{   
     cout<<getYear()<<"-"<<getMonth()<<"-"<<getDay()<<endl;
}	  
   
    
 	  
	
 
     
 
  
    
 
	
	
	
	
	
	

	

	
	
	
	
	

	

