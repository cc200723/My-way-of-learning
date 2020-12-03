#include<iostream> 
#include<cstdio>
using namespace std;
    int a[50000],n,k,x,cnt;
    int main()
    {
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        a[x]=1;
    }
    for (int i=1;i<=30000;i++)
    {
        if (a[i]==1) cnt++;
        if (cnt==k)
        {
            printf("%d\n",i);
            return 0;
        }
    }
    printf("NO RESULT");
    return 0;
    }
