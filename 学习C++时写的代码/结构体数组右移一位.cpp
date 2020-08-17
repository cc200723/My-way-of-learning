#include <iostream>
using namespace std;
    struct Student{
     int ID;
     int score;
    }; 
	 Student stu[5]={{1,71},{2,73},{3,82},{4,85},{5,75}};
    int len = sizeof(stu) / sizeof(stu[0]);
    void PrintArray(){
	
	cout << "数组是:" << '\n'; 
	for (int i = 0; i < len; i++){
			cout<<stu[i].ID<<"    "<<stu[i].score<<endl;;
		    cout << ' ';
	}
	cout << '\n';
	}//打印数组
 
	void Right_Move_Array(){
	int temp;
	int n = 0;

	cout << "请输入右移几位\n" << '\n';
	
	cout << ' ';
	cin >> n;
	for (int i = 0; i < n; i++){
		temp = stu[len - 1].ID;
		for (int j = len - 1; j >0; j--){
			stu[j].ID = stu[j - 1].ID;
		}
		stu[0].ID = temp;
	}
   	for (int i = 0; i < n; i++){
		temp = stu[len - 1].score;
		for (int j = len - 1; j >0; j--){
			stu[j].score = stu[j - 1].score;
		}
		stu[0].score = temp;
	}
	PrintArray();
}
int main(){
PrintArray();
Right_Move_Array();
return 0;
}
	
	

