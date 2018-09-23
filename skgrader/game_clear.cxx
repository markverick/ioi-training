#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
vector<tuple<int,int,int> > adj[10135];
priority_queue<pair<int,int> > pq;
int dist[10135];
int main()
{
    int n,m,i,j,k,T,a,b,c,d,fst,lst,mid,mn=1000000005,w,u;
    scanf("%d %d %d",&n,&m,&T);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d %d %d",&a,&b,&c,&d);
        adj[a].emplace_back(b,c,d);
    }
    fst=0;lst=100000;
    while(fst<=lst)
    {
        mid=(fst+lst)/2;
        for(i=2;i<=n;i++)
            dist[i]=1000000005;
        dist[1]=0;
        pq.emplace(0,1);
        while(!pq.empty())
        {
            tie(w,u)=pq.top();
            w=-w;
            pq.pop();
            for(i=0;i<adj[u].size();i++)
            {
                tie(a,b,c)=adj[u][i];
                if(c>mid)
                    continue;
                if(w+b<dist[a])
                {
                    dist[a]=w+b;
                    pq.emplace(-w-b,a);
                }
            }
        }
        if(dist[n]<=T)
        {
            mn=min(mn,mid);
            lst=mid-1;
        }
        else
        {
            fst=mid+1;
        }
    }
    if(mn<1000000005)
        printf("%d",mn);
    else
        printf("-1");
}
