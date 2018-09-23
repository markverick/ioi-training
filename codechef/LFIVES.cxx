#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
long long a[2135];
vector<pair<long long,long long> > v;
long long ft[7][2135];
long long dp[2135][2135][6],n;
void add(long long idx,long long f,long long val)
{
    while(idx<=n)
    {
        ft[f][idx]+=val;
        idx+=idx&-idx;
    }
}
long long sum(long long idx,long long f)
{
    long long sm=0;
    while(idx>0)
    {
        sm+=ft[f][idx];
        idx-=idx&-idx;
    }
    return sm;
}
int main()
{
    long long i,j,k,q,x,y;
    scanf("%lld %lld",&n,&q);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        v.emplace_back(a[i],i);
    }
    sort(v.begin(),v.end());
    a[v[0].Y]=1;j=1;
    for(i=1;i<n;i++)
    {
        if(v[i]!=v[i-1])
            j++;
        a[v[i].Y]=j;
    }
    for(i=1;i<=n;i++)
    {
        dp[i][i][1]=1;
    }
    for(i=1;i<=n;i++)
    {
        memset(ft,0,sizeof ft);
        add(a[i],1,1);
        for(k=i+1;k<=n;k++)
        {
            for(j=2;j<=5;j++)
            {
                if(j%2==0)
                {
                    dp[i][k][j]=sum(n,j-1)-sum(a[k],j-1);
                    add(a[k],j,dp[i][k][j]);
                }
                else
                {
                    dp[i][k][j]=sum(a[k]-1,j-1);
                    add(a[k],j,dp[i][k][j]);
                }
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=i;j<=n;j++)
        {
            printf("%d\n",dp[i][j][5]);
        }
    }
    while(q--)
    {
        scanf("%lld %lld",&x,&y);
        printf("%lld\n",dp[x][y][5]);
    }
}
