#include<bits/stdc++.h>
using namespace std;
int dp(int a,int b)
{
    if(a<=1&&b>1)
    {
        return 1;
    }
    else if(a>1&&b<=1)
    {
        return 1;
    }
    printf("%d %d\n",a,b);
    int i,mn=1;
    for(i=0;i<a;i++)
    {
        if((i^b)==0)
        {
            mn=min(mn,dp(i,b));
        }
    }
    for(i=0;i<b;i++)
    {
        if((i^a)==0)
        {
            mn=min(mn,dp(a,i));
        }
    }
    return 1-mn;
}
int main()
{
    int T,n,m,r,c;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d %d %d",&n,&m,&r,&c);
        printf("%d\n",dp(n-1,m-1));
    }
}
