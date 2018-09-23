#include<bits/stdc++.h>
using namespace std;
int a[100135][5],n;
int jum[100135][5];
int dp(int idx,int food)
{
    if(idx==n)
        return 0;
    if(jum[idx][food]>=0)
        return jum[idx][food];
    int mn=1000000005,i;
    for(i=1;i<=3;i++)
    {
        if(i==food)continue;
        mn=min(mn,dp(idx+1,i)+a[idx+1][i] );
    }
    return jum[idx][food]=mn;
}
int main()
{
    int T,i,j;
    scanf("%d",&T);
    while(T--)
    {
        memset(jum,-1,sizeof jum);
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=3;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        printf("%d\n",dp(0,0));
    }
}
