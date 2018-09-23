#include<bits/stdc++.h>
using namespace std;
int jum[1000005];
int dp(int n)
{
    if(jum[n]>=0)
        return jum[n];
    if(n==0)
    {
        return 0;
    }
    int m=n,mn=1000000000,mc=1;
    while(m>0)
    {
        if(m%10>0)
            mn=min(mn,m%10);
        mc=max(mc,m%10);
        m/=10;
    }
    return jum[n]=1-min(dp(n-mn),dp(n-mc));
}
int main()
{
    int T,n,i;
    i=scanf("%d",&T);
    memset(jum,-1,sizeof jum);
    while(T--)
    {
        scanf("%d",&n);
        if(dp(n))
        {
            printf("YES\n");
        }
        else
            printf("NO\n");
    }
}
