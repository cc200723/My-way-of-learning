#include<iostream> 
#include<cstring>
using namespace std;

int stringLength(char *s)
{
	int len=0;
	int i=0;
	while(s[i]!='\0')
	{
		i++;
		len++;
	}
	return len;
}

char * stringCat(char *s1,char *s2)
{
	//求出s1,s2的长度 
	int l1=stringLength(s1); 
	int l2=stringLength(s2);
	
	
	char *strP=s1;
	int i;
	
	
	    
	for(int j=l1,i=0;j<l1+l2,i<l2;i++,j++)//复制s2
	    strP[j]=s2[i];
	    
	 strP[l1+l2]='\0';//复制结束符 
	 
	 
	 return strP;
}

int main()
{
	char s1[]="abc";// 
	char s2[]="22fg";
	
	int l1=stringLength(s1); 
	int l2=stringLength(s2);
	char s3[l1+l2+1];
	char * strP=s3;
	strcpy(strP,s1); 
	//cout<<stringLength(s1)<<endl;
	//cout<<stringLength(s2)<<endl;
	strP=stringCat(s1,s2);
	cout<<strP<<endl;
	
	return 0;
}























	  
	    
	
