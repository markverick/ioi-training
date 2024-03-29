#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
using namespace std;

vector<pair<int,int> >adj[2200];
int n;
int jum[2200];
int dp(int idx)
{
    if(jum[idx]>=0)
        return jum[idx];
    if(idx>=n)
        return 0;
    int mc=0;
    int i;
    for(i=0;i<adj[idx].size();i++)
    {
        mc=max(mc,dp(adj[idx][i].first)+adj[idx][i].second);
    }
    mc=max(mc,dp(idx+1));
    return jum[idx]=mc;
}
int main()
{
    int T,i,j,k;
    scanf("%d",&T);
    while(T--)
    {
        memset(jum,-1,sizeof jum);
        for(i=0;i<2200;i++)
            adj[i].clear();
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            adj[a].PB(MP(b,c));
        }
        printf("%d\n",dp(0));
    }
}
