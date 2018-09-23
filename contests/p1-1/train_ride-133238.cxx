#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int a[5135],b[5135];
vector<int> adj[50135];
pair<int,int> v[5135];
pair<int,int> jum[5135];
pair<int,int> dp(int idx)
{
    if(jum[idx].X>=0)
    {
        return jum[idx];
    }
    int i;
    if(adj[idx].empty())
    {
        return make_pair(0,b[idx]);
    }
    int mc=-1,dmc=-1;
    pair<int,int> p;
    for(i=0;i<adj[idx].size();i++)
    {
        p=dp(adj[idx][i]);
        if(mc<p.X)
        {
            mc=p.X;
            dmc=p.Y;
        }
        else if(mc==p.X)
        {
            dmc=max(dmc,p.Y);
        }
    }
    return jum[idx]=make_pair(mc+1,dmc);
}
int main()
{
    int i,j,k,n,m;
    for(i=0;i<=5001;i++)
    {
        jum[i]=make_pair(-1,-1);
    }
    memset(jum,-1,sizeof jum);
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&v[i].X,&v[i].Y);
    }
    sort(&v[1],&v[m+1]);
    for(i=1;i<=m;i++)
    {
        tie(a[i],b[i])=v[i];
        if(a[i]<=1)
        {
            adj[0].emplace_back(i);
        }
    }
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(i==j)
                continue;
            if(a[j]>a[i]&&a[j]<=b[i])
                adj[i].emplace_back(j);
        }
    }
    pair<int,int> p=dp(0);
    printf("%d %d",p.X,p.Y);
}
