#include<bits/stdc++.h>
using namespace std;
vector<tuple<int,int,int> > edge;
int n,m,p[333],h[333],hsh[333][333],mat[333][333];
vector<int> adj[333];
int Find(int idx)
{
    while(p[idx]!=idx)
    {
        idx=p[idx];
    }
    return idx;
}
void Union(int x,int y)
{
    x=Find(x);
    y=Find(y);
    if(h[x]>=h[y])
    {
        p[y]=x;
        h[x]=max(h[x],h[y]+1);
    }
    else
    {
        p[x]=y;
        h[y]=max(h[y],h[x]+1);
    }
}
int main()
{
    int a,b,c,i,j,x,y,w,t;
    scanf("%d %d",&n,&t);
    for(i=1;i<=n;i++)
    {
        p[i]=i;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a);
            if(i!=j)
                edge.emplace_back(a,i,j);
            mat[i][j]=a;
        }
    }
    sort(edge.begin(),edge.end());
    int sum=0;
    for(i=0;i<edge.size();i++)
    {
        tie(w,x,y)=edge[i];
//        w=-w;
        if(Find(x)!=Find(y))
        {
            //sum+=w;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
            Union(x,y);
        }
    }
    int root=0;
    for(i=1;i<=n;i++)
    {
        if(adj[i].size()>=3)
            root=i;
    }
    printf("%d\n",root);
    if(t==2)
    {
        printf("%d ",adj[root].size());
    }
}
