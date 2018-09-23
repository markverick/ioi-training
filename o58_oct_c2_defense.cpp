#include<bits/stdc++.h>
#define X first
#define Y second
#define EB emplace_back
using namespace std;
int n,k;
int a[3135];
int jum[3135],st;
inline int dp(int idx)
{
    if(jum[idx]>=0)
        return jum[idx];
    int i;
    int mn=1000000000;
    if(idx==n)
        return 0;
    if(st>=n-k+1)
        return 0;
    if(idx>=n-k+1)
    {
        for(i=idx+1;i<=n;i++)
        {
            mn=min(mn,a[i]);
        }
        return mn;
    }
    for(i=idx+1;i<idx+k;i++)
    {
        mn=min(mn,dp(i)+a[i]);
    }
    return jum[idx]=mn;
}
int main()
{
    int i,j,Min=1000000000,mn,sum=0;
    memset(jum,-1,sizeof jum);
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<=k;i++)
    {
        mn=1000000000;
        for(j=i-1;j>=1;j--)
        {
            st=j;
            Min=min(Min,dp(i)+a[j]+a[i]);
        }
    }
    printf("%d",Min);
}
