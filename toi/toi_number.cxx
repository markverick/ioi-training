#include<bits/stdc++.h>
using namespace std;
int cost[12];
char str[135];
char out[135];
int n,len,Min=1000000000,Max=0;
int qs[12];
int main()
{
    int i,j,k,m;
    scanf("%d",&n);
    for(i=1;i<=9;i++)
    {
        scanf("%d",&cost[i]);
        if(Min>=cost[i])
        {
            Min=cost[i];m=i;
        }
    }
    len=n/Min;
    for(i=0;i<len;i++)
    {
        out[i]=m+'0';
    }
    int sum=len*cost[m];
    for(i=0;i<len;i++)
    {
        for(j=9;j>m;j--)
        {
            if(sum+cost[j]-cost[m]<=n)
            {
                out[i]=j+'0';
                sum=sum+cost[j]-cost[m];
                break;
            }
        }
    }
    printf("%s",out);
}
