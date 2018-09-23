#include<bits/stdc++.h>
using namespace std;
queue<int> q;
int a,b,indeg[135];
set<int> st[135];
vector<int> adj[135];
int v[135];
int main()
{
    int n,m,i,j,k,u;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&a,&b);
        adj[a].emplace_back(b);
        indeg[b]++;
    }
    for(i=1;i<=n;i++)
    {
        if(indeg[i]==0)
        {
            //st[i].insert(0);
            //hsh[i][0]=1;
            q.emplace(i);
        }

    }
    while(!q.empty())
    {
        u=q.front();q.pop();

        for(i=0;i<adj[u].size();i++)
        {
            st[adj[u][i]].insert(u);
            for(auto it=st[u].begin();it!=st[u].end();it++)
            {
                st[adj[u][i]].insert(*it);
            }
            indeg[adj[u][i]]--;
            if(indeg[adj[u][i]]==0)
                q.emplace(adj[u][i]);
        }
    }
    int cot=0;
    for(i=1;i<=n;i++)
    {
        v[i]=st[i].size()+1;
    }
    sort(&v[1],&v[n+1]);
    for(i=1;i<=n;i++)
    {
        //printf("%d\n",v[i]);
        if(v[i]!=v[i-1]&&v[i]!=v[i+1]&&v[i]==i)
        {
            cot++;
        }
    }
    printf("%d",cot);
}
