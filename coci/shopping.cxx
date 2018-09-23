#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int d[12][100135],S,s[12],jum[12][3000];
priority_queue<pair<int,int> > pq;
vector<pair<int,int> > adj[100135];
int dp(int idx,int bit)
{
    if(jum[idx][bit]>=0)
        return jum[idx][bit];
    if(__builtin_popcount(bit)==S+1)
    {
        if(idx==0)
            return 0;
        return MI;
    }
    int i,mn=MI;
    for(i=0;i<=S;i++)
    {
        if(i==idx||((1<<i)|bit)==bit)continue;
        mn=min(mn,dp(i,bit|(1<<i))+d[idx][s[i]]);
    }
    return jum[idx][bit]=mn;
}
int main()
{
//	freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,m,i,j,k,T,a,b,c,w,u;
	scanf("%d",&T);
	while(T--)
    {
        memset(jum,-1,sizeof jum);
        scanf("%d %d",&n,&m);
        for(i=0;i<=n;i++)
            adj[i].clear();
        for(i=1;i<=m;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            adj[a].emplace_back(b,c);
            adj[b].emplace_back(a,c);
        }
        scanf("%d",&S);
        for(i=1;i<=S;i++)
            scanf("%d",&s[i]);
        for(i=0;i<=S;i++)
        {
            pq.emplace(0,s[i]);
            for(j=0;j<=n;j++)
                d[i][j]=MI;
            d[i][s[i]]=0;
            while(!pq.empty())
            {
                tie(w,u)=pq.top();w=-w;
                pq.pop();
                for(j=0;j<adj[u].size();j++)
                {
                    if(w+adj[u][j].Y<d[i][adj[u][j].X])
                    {
                        d[i][adj[u][j].X]=w+adj[u][j].Y;
                        pq.emplace(-d[i][adj[u][j].X],adj[u][j].X);
                    }
                }
            }
//            for(j=0;j<=S;j++)
//            {
//                printf("%d ",d[i][s[j]]);
//            }
//            printf("\n");
        }
        printf("%d\n",dp(0,0));
    }
}
