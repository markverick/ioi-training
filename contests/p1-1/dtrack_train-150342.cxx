#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int n,k,m;
int a[100135];
vector<pair<int,int> > adj[100135];
vector<int>::iterator it;
map<int,bool> state[100135];
queue<tuple<int,int,int> > q;
int main()
{
    int i,j,u,w,id;
    scanf("%d %d %d",&n,&k,&m);
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=k;j++)
        {
            scanf("%d",&a[j]);
            if(a[j]==1)
            {
                q.emplace(1,i,1);
                state[1][i]=1;
            }
        }
        for(j=1;j<k;j++)
        {
            adj[a[j]].emplace_back(a[j+1],i);
            adj[a[j+1]].emplace_back(a[j],i);
        }
    }
//    for(i=1;i<=n;i++)
//    {
//        sort(adj[i].begin(),adj[i].end());
//        it=unique(adj[i].begin(),adj[i].end());
//        adj[i].resize(distance(adj[i].begin(),it));
//    }
    while(!q.empty())
    {
        tie(u,id,w)=q.front();
//        printf("%d %d %d\n",u,id,w);
        q.pop();
        state[u][id]=1;
        if(u==n)
        {
            printf("%d",w+1);
            return 0;
        }
        for(i=0;i<adj[u].size();i++)
        {
            if(state[adj[u][i].X][adj[u][i].Y])
                continue;
            if(adj[u][i].Y==id)
            {
                q.emplace(adj[u][i].X,id,w);
            }
            else
            {
                q.emplace(adj[u][i].X,adj[u][i].Y,w+1);
            }
        }
    }
    printf("-1");
}
