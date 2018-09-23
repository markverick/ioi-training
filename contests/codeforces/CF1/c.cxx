#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int n,a[135],jum[135][5];
int dp(int idx,int did)
{
    if(jum[idx][did]>=0)
        return jum[idx][did];
    if(idx==n+1)
    {
        return 0;
    }
    int mn=1000000000;
    if(did==0)
    {
        mn=min(mn,dp(idx+1,0)+1);
        if(a[idx]==1||a[idx]==3)
            mn=min(mn,dp(idx+1,1));
        if(a[idx]==2||a[idx]==3)
            mn=min(mn,dp(idx+1,2));
    }
    else if(did==1)
    {
        mn=min(mn,dp(idx+1,0)+1);
        if(a[idx]==2||a[idx]==3)
            mn=min(mn,dp(idx+1,2));
    }
    else
    {
        mn=min(mn,dp(idx+1,0)+1);
        if(a[idx]==1||a[idx]==3)
            mn=min(mn,dp(idx+1,1));
    }
    return jum[idx][did]=mn;
}
int main()
{
    int i,j,k;
    memset(jum,-1,sizeof jum);
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("%d\n",dp(1,0));
}
