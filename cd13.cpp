#include<bits/stdc++.h>
using namespace std;

int n,k;
int jum[1200];
int dp(int sum)
{
    if(jum[sum]>=0)
        return jum[sum];
    if(sum==n)
        return 0;
    else if(sum>n)
        return 999999999;
    int mn=999999999;
    int i;
    for(i=1;i<=n-sum&&i<=k;i++)
    {
        if(i==13)
            continue;
        mn=min(mn,dp(sum+i)+1);
    }
    return jum[sum]=mn;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(jum,-1,sizeof jum);
        scanf("%d %d",&n,&k);
        printf("%d\n",dp(0));
    }
}
