#include<bits/stdc++.h>
using namespace std;
int b[30];
int a[30][30],n,m;
int mn=0;
int jum[30][531];
int dp(int idx,int sum)
{
    if(jum[idx][sum]>=0)
        return jum[idx][sum];
    if(idx>=n)
    {
        return sum;
    }
    int mc=0,i;
    for(i=1;i<=b[idx+1];i++)
    {
        if(sum+a[idx+1][i]<=m)
            mc=max(mc,dp(idx+1,sum+a[idx+1][i]));
    }
    return jum[idx][sum]=mc;
}
int main()
{
    int T,i,j,k;
    scanf("%d",&T);
    while(T--)
    {
        mn=0;
        memset(jum,-1,sizeof jum);
        memset(a,-1,sizeof a);
        memset(b,-1,sizeof b);
        scanf("%d %d",&m,&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&b[i]);
            for(j=1;j<=b[i];j++)
            {
                scanf("%d",&a[i][j]);
            }
            sort(&a[i][1],&a[i][b[i]+1]);
            mn+=a[i][1];
        }
        if(mn>m)
        {
            printf("no solution\n");
        }
        else
        {
            printf("%d\n",dp(0,0));
        }
    }
}
