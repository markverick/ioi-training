#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
using namespace std;
int a,b,n;
vector<pair<int,int> > adj[1005];
// v weight
int p[1005];
int in[1005];
int m;
long long jum[1005][1005];
long long dp(int idx,int town)
{
    //printf("%d %d\n",idx,town);
    if(jum[idx][town]>=0)
        return jum[idx][town];
    if(town==b)
    {
        return 0;
    }
    long long mn=9999999999999ll;
    int i;
    for(i=0;i<adj[town].size();i++)
    {
        mn=min(mn,dp(idx+1,adj[town][i].first)+adj[town][i].second);
    }
    return jum[idx][town]=mn;
}
int main()
{
    int i,j,k;
    scanf("%d %d %d",&a,&b,&n);
    memset(jum,-1,sizeof jum);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&p[i],&m);
        for(j=1;j<=m;j++)
        {
            scanf("%d",&in[j]);
        }
        for(j=1;j<m;j++)
        {
            adj[in[j]].PB(MP(in[j+1],p[i]));
        }
    }


    dp(0,a);
    long long mn=9999999999999ll;
    long long x,y;
    for(i=0;i<=1000;i++)
    {
        for(j=1;j<=1000;j++)
        {
            if(jum[i][j]!=-1&&jum[i][j]<mn)
            {
                mn=jum[i][j];
                x=jum[i][j];y=i;
            }
        }
    }
    printf("%lld %lld",x,y+1);

}
