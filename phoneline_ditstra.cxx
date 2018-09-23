#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int n,p,k;
vector<pair<int,int> >adj[1135];
//v w
priority_queue<tuple<int,int,int> >pq;
//-Value Vertex FreeTime
int d[1135][1135];
//Vertex Free
int main()
{
    int i,j,k,a,b,c,v,w,f;
    scanf("%d %d %d",&n,&p,&k);
    for(i=1;i<=p;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        adj[a].emplace_back(b,c);
        adj[b].emplace_back(a,c);
    }
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=k;j++)
        {
            d[i][j]=1000000000;
        }
    }
    //d[n][0]=0;
    pq.emplace(0,n,0);
    while(!pq.empty())
    {
        tie(w,v,f)=pq.top();
        pq.pop();w=-w;
        for(i=0;i<adj[v].size();i++)
        {
            if(w+adj[v][i].Y<d[adj[v][i].X][f])
            {
                d[adj[v][i].X][f]=w+adj[v][i].Y;
                pq.emplace(-(w+adj[v][i].Y),adj[v][i].X,f);
            }
            if(f<k&&w<d[adj[v][i].X][f+1])
            {
                d[adj[v][i].X][f+1]=w;
                pq.emplace(-w,adj[v][i].X,f+1);
            }
        }
    }
    int mc=0;
    for(i=1;i<n;i++)
    {
        printf("%d\n",d[i][k]);
        mc=max(mc,d[i][k]);
    }
    printf("%d",mc);
}
