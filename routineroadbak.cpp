#include<bits/stdc++.h>
#define X first
#define Y second
#define EB emplace_back
#define MP make_pair
#define MAX_INT 100000000000000000
using namespace std;
vector<pair<long long,long long> > adj[100135];
long long n,m,k;
long long jum[100135][10];
long long dp(long long idx,long long jeb)
{
    if(jum[idx][jeb]>=0)
        return jum[idx][jeb];
    if(idx==n)
        return 0;
    long long mn=MAX_INT,i;
    //for(i=upper_bound(adj[idx].begin(),adj[idx].end(),MP(idx,1000000000))-adj[idx].begin();i<adj[idx].size();i++)
    for(i=0;i<adj[idx].size();i++)
    {
        if(adj[idx][i].Y>=0)
            mn=min(mn,dp(adj[idx][i].X,jeb)+adj[idx][i].Y);
        else if(adj[idx][i].Y<0&&adj[idx][i].Y>=-100)
            mn=min(mn,dp(adj[idx][i].X,jeb));
        else if(jeb<k)
            mn=min(mn,dp(adj[idx][i].X,jeb+1));
//            prlong longf("UP = %lld\n",adj[idx][i].Y);
    }
    //prlong longf("%lld %lld = %lld\n",idx,jeb,mn);
    return jum[idx][jeb]=mn;
}
int main()
{
    long long i,j,a,b,c;
    scanf("%lld %lld %lld",&n,&m,&k);
    memset(jum,-1,sizeof jum);
    for(i=1;i<=m;i++)
    {
        scanf("%lld %lld %lld",&a,&b,&c);
        if(b>a)
            adj[a].EB(b,c);
    }
    long long out=dp(1,0);
    if(out==MAX_INT)
        printf("-1");
    else
        printf("%lld",out);
}
