#include<bits/stdc++.h>
using namespace std;
int n,m;
int d[10135];
int jum[10135];
int qs[10135];
int dp(int idx)
{
    if(jum[idx]>=0)
        return jum[idx];
    if(idx==n)
    {
        return 0;
    }
    int mc=0,i;
    mc=max(mc,dp(idx+1));
    for(i=1;i<=min((n-idx)/2,m);i++)
    {
        mc=max(mc,dp(idx+2*i)+qs[idx+i]-qs[idx]);
    }
    return jum[idx]=mc;
}
int main()
{
    int i,j,k;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&d[i]);
        qs[i]=qs[i-1]+d[i];
    }
    memset(jum,-1,sizeof jum);
    printf("%d",dp(0));
}
