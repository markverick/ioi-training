#include<bits/stdc++.h>
using namespace std;

vector<int> a;
int jum[10135][135];
int dp(int n,int idx)
{
    if(n==0)
    {
        return 0;
    }
    if(jum[n][idx]>=0)
        return jum[n][idx];
    int mn=1000000000,i;
    for(i=idx;i<100;i++)
    {
        if(n-a[i]>=0)
            mn=min(mn,dp(n-a[i],i)+1 );
    }
    return jum[n][idx]=mn;
}
int main()
{
    int n,i,T;
    scanf("%d",&T);
    memset(jum,-1,sizeof jum);
    for(i=1;i<=100;i++)
    {
        a.emplace_back(i*i);
    }
    while(T--)
    {
        scanf("%d",&n);
        printf("%d\n",dp(n,0));
    }
}
