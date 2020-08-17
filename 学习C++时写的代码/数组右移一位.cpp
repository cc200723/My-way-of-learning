#include <iostream>
using namespace std;
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    int len = sizeof(arr) / sizeof(arr[0]);
    void PrintArray(){
	
	cout << "数组是:" << '\n'; 
	for (int i = 0; i < len; i++){
			cout << arr[i];
		    cout << ' ';
	}
	
	cout << '\n';
}
	void Right_Move_Array(){
	int temp;
	int n = 0;
    cout << "请输入右移几位\n" << '\n';
	cout << ' ';
	cin >> n;
	for (int i = 0; i < n; i++){
		temp = arr[len - 1];
		for (int j = len - 1; j >0; j--){
			arr[j] = arr[j - 1];
		}
		arr[0] = temp;
	}
	PrintArray();
}
int main(){
PrintArray();
Right_Move_Array();
return 0;
}

    
  





	






	
	
	

	
	
	
	
	

   
   





	  
 



 

 
 
	  
	  
	  
	



