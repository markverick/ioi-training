#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int hsh[135][135],adj[135][135],M[135],W[135];
vector<pair<int,int> > v[135];
queue<int> q;
int main()
{
    int i,j,k,n,mc,mn,ck,m,w;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        q.emplace(i);
        for(j=1;j<=n;j++)
        {
            scanf("%d",&adj[i][j]);
            v[i].emplace_back(-adj[i][j],j);
        }
        sort(v[i].begin(),v[i].end());
    }
    while(!q.empty())
    {
        m=q.front();q.pop();
        if(v[m].empty())continue;
        w=v[m][v[m].size()-1].Y;
        v[m].pop_back();
        if(W[w]==0)
            W[w]=m,M[m]=w;
        else if(adj[m][w]>adj[W[w]][w])
        {
            M[W[w]]=0;
            q.emplace(W[w]);
            M[m]=w;
            W[w]=m;
        }
        else
            q.emplace(m);
    }
    for(i=1;i<=n;i++)
        printf("%d ",M[i]);
}
