#include <iostream>
using namespace std;
    struct Student{
     int ID;
     int score;
    }; 
	 Student stu[5]={{1,71},{2,73},{3,82},{4,85},{5,75}};
    int len = sizeof(stu) / sizeof(stu[0]);
    void PrintArray(){
	
	cout << "������:" << '\n'; 
	for (int i = 0; i < len; i++){
			cout<<stu[i].ID<<"    "<<stu[i].score<<endl;;
		    cout << ' ';
	}
	cout << '\n';
	}//��ӡ����
 
		void Left_Move_Array(){
	    int temp;
	    int n = 0;
    cout << "���������Ƽ�λ\n" << '\n';
	cout << ' ';
	cin >> n;
	for (int i = 0; i < n; i++){
		temp = stu[0].score;
		for (int j = 0; j <len - 1; j++){
			stu[j].score = stu[j + 1].score;
		}
		stu[len - 1].score = temp;
	}
		for (int i = 0; i < n; i++){
		temp = stu[0].ID;
		for (int j = 0; j <len - 1; j++){
			stu[j].ID = stu[j + 1].ID;
		}
		stu[len - 1].ID = temp;
	}
	PrintArray();
}//���ƺ��� 
int main(){
 PrintArray();
 Left_Move_Array();
 return 0;
}


	

 
	




