#include<bits/stdc++.h>
using namespace std;
int n,a,b,h;
int d[100135];
int qs[100135];
int ps[100135];
int jum[100135];
int dp(int idx)
{
    if(jum[idx]>=0)
        return jum[idx];
    if(idx==n)
        return 0;
    int mn=1000000000;
    for(int i=idx+1;i<=n;i++)
    {
        mn=min(mn,dp(i)+(ps[i-1]-ps[idx])*h+a+b*(qs[i]-qs[idx]));
    }
    return jum[idx]=mn;

}
int main()
{
    scanf("%d",&n);
    memset(jum,-1,sizeof jum);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&d[i]);
        qs[i]=qs[i-1]+d[i];
    }
    for(int i=n;i>=1;i--)
    {
        ps[i]=ps[i+1]+qs[i];
    }
    scanf("%d %d %d",&a,&b,&h);
    printf("%d",dp(0));

}
