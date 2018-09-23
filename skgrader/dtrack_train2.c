#include<bits/stdc++.h>
using namespace std;
int n,k,m;
int a[100135];
vector<pair<int,int> > adj[100135];
vector<int>::iterator it;
unordered_map<int,bool> state;
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
        q.pop();
        if(u==n)
        {
            printf("%d",state[n]-1);
            return 0;
        }
        for(i=0;i<adj[u].size();i++)
        {
            if(state[adj[u][i]])
                continue;
            state[adj[u][i]]=state[u]+1;
            q.emplace(adj[u][i]);
        }
    }
    printf("-1");
}

