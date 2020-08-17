#include <iostream>
#include <string>
using namespace std;
struct Student{
 int ID;
 int score;
}; 
int getMin( Student array[],int number);
int getMin( Student array[],int number){
Student temp=array[0];
int j=0;
for(int i=0;i<number;i++)
{
	if (temp.score>=array[i].score)
	{
		temp=array[i];
		j=i;
	}
}	
  return j;
} 
int main(){
	 
    Student stu[5]={{1,71},{2,73},{3,82},{4,85},{5,75}};
	int j=getMin(stu,5);
	cout<<stu[j].ID<<"    "<<stu[j].score<<endl;
	return 0;
}		
