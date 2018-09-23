#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define PB push_back
#define INF 1073741824
using namespace std;
vector<pair<int,int> > adj[1200];
//v,w
priority_queue<pair<int,int> > q;
//w,v
int d[1200];
int main()
{
    int n,m,i,j,k;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        adj[a].PB(MP(b,c));
        adj[b].PB(MP(a,c));
    }
    for(i=0;i<=n;i++)
        d[i]=INF;
    d[1]=0;
    q.push(MP(0,1));
    while(!q.empty())
    {
        int w,v;
        w=-q.top().X;
        v=q.top().Y;
        q.pop();
        for(i=0;i<adj[v].size();i++)
        {
            if(w+adj[v][i].Y<d[adj[v][i].X])
            {
                d[adj[v][i].X]=w+adj[v][i].Y;
                q.push(MP(-d[adj[v][i].X],adj[v][i].X));
            }
        }
    }
    printf("%d\n",d[n]);
}
