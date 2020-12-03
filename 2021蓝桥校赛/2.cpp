#include <iostream>
using namespace std;

int main()
{
    int sum=0;
    string str;
    getline(cin,str);
    int length=str.length();
    for(int i=0;i<length;i++)
    {
        if(str[i]=='M')
            sum+=1000;
        if(str[i]=='D')
            sum+=500;
        if(str[i]=='C')
        {
            if(str[i+1]=='D')
            {
                sum+=400;
                i++;
            }
            else if(str[i+1]=='M')
            {
                sum+=900;
                i++;
            }
            else
                sum+=100;
        }
        if(str[i]=='L')
            sum+=50;
        if(str[i]=='X')
        {
            if(str[i+1]=='L')
                {
                    sum+=40;
                    i++;
                }
            else if(str[i+1]=='C')
                {
                    sum+=90;
                    i++;
                }
            else
                sum+=10;
        }
        if(str[i]=='V')
            sum+=5;
        if(str[i]=='I')
        {
            if(str[i+1]=='V')
                {
                    sum+=4;
                    i++;
                }

            else if(str[i+1]=='X')
                {
                    sum+=9;
                    i++;
                }
            else
                sum+=1;
        }

    }
    cout<<sum;
    return 0;
}
