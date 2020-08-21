// Example: 棋类游戏
#include <iostream>
#include <cstdlib>
using namespace std;
const int M=7; //规定棋盘大小
const int N=5; //玩几子棋
void InitChess(char*);
void HumanMove(char*);
void ComputerMove(char*);
void ShowChess(char*);
char WinCheck(char*);
int main()
{
char chess[M*M];
char done;
cout<<"---Game of Chess---"<<endl;
cout<<"Human against the stupid computer"<<endl;
done ='*';
InitChess(chess);
do{
ShowChess(chess);
HumanMove(chess);
done = WinCheck(chess); //检查是否有赢家
if(done!= '*')
{
break; //如有赢家，则跳出循环
} ComputerMove(chess);
done = WinCheck(chess); //检查是否有赢家
}while(done== '*');
ShowChess(chess); //显示棋局最终状态
if(done=='H')
{
cout<<"Human won!"<<endl;
} else
{
cout<<"Computer won!!!!"<<endl;
}
return 0;
}
//初始化棋盘
void InitChess( char chess[] )
{
  for(int i=0; i<M; i++)
 {
  for(int j=0; j<M; j++)
  {
   chess[i+M*j] ='*';
  }
 }
}

//下棋人的落子
void HumanMove( char chess[] )
{
int x, y;
cout<<"Enter X,Y coordinates for your move: ";
cin>>x>>y;
cout<<endl;
x--;
y--;
if(chess[x+M*y]!= '*')
{
cout<<"Invalid move, try again."<<endl;
HumanMove(chess);
} else
chess[x+M*y] = 'H';
} 



//计算机落子
void ComputerMove( char chess[] )
{
int i, j;
for( i=0; i<M; i++ )
{
for( j=0; j<M; j++ )
{
if(chess[i+M*j]=='*')
{
break;
}
} 
if(chess[i+M*j]=='*')
{
break;
}
} 
if(i*j==M*M)
{
cout<<"Diamond cut diamond"<<endl;
exit(0);
} 
else
{
chess[i+M*j] = 'C';
}
} 
//在屏幕上显示棋局 

void ShowChess( char chess[] )
{
for(int i=0; i<M; i++)
{
for(int j=0; j<M; j++)
{
cout<<chess[i+M*j]<<"\t";
cout<<endl<<endl;
} 
}
} 





//检查是否有赢家
char WinCheck( char chess[] )
{
for(int i=0; i<M; i++)
{
for(int j=0; j<M; j++)
{
 char t=chess[i+M*j];
 int count=1;
for(int a=i+1,b=j+1; chess[a+M*b]==t&&a<M&&b<M; a++,b++)
{
count++;
} 
if( count>=N)
{
return t;
} 
count=1;
for(int a=i,b=j+1; chess[a+M*b]==t&&b<M; b++)
{
count++;
} 
if(count>=N)
{
return t;
} 
count=1;
for(int a=i+1,b=j; chess[a+M*b]==t&&a<M; a++)
{
count++;
} 
if(count>=N)
{
return t;
} 
count=1;
for(int a=i+1,b=j-1; chess[a+M*b]==t&&a<M&&b>=0; a++,b--)
{
count++;
} 
if(count>=N)
{
return t;
}
}
} 
return '*';
} 
