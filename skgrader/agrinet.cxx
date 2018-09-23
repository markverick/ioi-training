#include<bits/stdc++.h>
using namespace std;
vector<tuple<int,int,int> > edge;
int n,m,p[100135],h[100135];
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
    int a,b,c,i,j,x,y,w;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        p[i]=i;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&c);
            edge.emplace_back(c,i,j);
        }
    }
    sort(edge.begin(),edge.end());
    int sum=0;
    for(i=0;i<edge.size();i++)
    {
        tie(w,x,y)=edge[i];
        if(Find(x)!=Find(y))
        {
            sum+=w;
            Union(x,y);
        }
    }
    printf("%d",sum);
}
