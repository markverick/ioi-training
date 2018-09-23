#include<bits/stdc++.h>
using namespace std;
int n,i;
int dp(int idx,int h)
{
    if(idx==i)
    {
        return 1;
    }
    int sm=dp(idx+1,h+1);
    sm+=dp(idx+1,h);
    if(h-1>=0)
        sm+=dp(idx+1,h-1);
    return sm;
}
int main()
{
    scanf("%d",&n);
    for(i=0;i<=n;i++)
    {
        printf("%d\n",dp(0,0));
    }
}
