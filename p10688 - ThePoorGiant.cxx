#include<bits/stdc++.h>
using namespace std;
int jum[1135][1135];
int dp(int n,int k)
{
    if(jum[n][k]>=0)
        return jum[n][k];
    if(n==1||n==0)
        return 0;
    else if(n==2)
    {
        return (k+1)*2;
    }
    int mn=1000000000;
    mn=min(mn,n*(k+1)+dp(n-1,k+1));
    mn=min(mn,n*(n+k)+dp(n-1,k));
    for(int i=1;i<n-1;i++)
    {
        mn=min(mn,dp(i,k)+n*(k+i+1)+dp(n-i-1,k+i+1));
    }
    return jum[n][k]=mn;
}
int main()
{
    int T,t,n,i,j,k;
    memset(jum,-1,sizeof jum);
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d %d",&n,&k);
        printf("Case %d: %d\n",t,dp(n,k));
    }
}
