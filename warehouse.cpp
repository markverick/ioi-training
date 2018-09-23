#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define PB push_back
#define INF 1073741824
using namespace std;

int d[12000];
int dist[10][10];
int mar[10];
int market;
int n,m;
vector<pair<int,int> > adj[12000];
int shortest_path(int a,int b)
{
    printf("%d %d\n",a,b);
    //v,w
    priority_queue<pair<int,int> > q;
    //w,v
    if(dist[a][b]>0)
        return dist[a][b];
    int a2=mar[a];
    int b2=mar[b];
    int i;
    for(i=0;i<=n;i++)
        d[i]=INF;
    d[a2]=0;
    q.push(MP(0,a2));
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
    dist[a][b]=d[b2];
    return d[b2];
}
int main()
{
    int i,j,k;
    scanf("%d %d %d",&n,&m,&market);
    for(i=0;i<market;i++)
    {
        scanf("%d",&mar[i]);
    }
    for(i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        adj[a].PB(MP(b,c));
        adj[b].PB(MP(a,c));
    }
    int perm[10]={0,1,2,3,4,5,6,7};
    int mn=9999999;
    while(true)
    {
        int sum=0;
        for(i=0;i<market-1;i++)
        {
            sum+=shortest_path(perm[i],perm[i+1]);
        }
        sum+=shortest_path(perm[market-1],perm[0]);
        printf("%d\n",sum);
        mn=min(mn,sum);
        if(next_permutation(perm,perm+market)==0)
            break;
    }
    printf("%d\n",mn);
}
