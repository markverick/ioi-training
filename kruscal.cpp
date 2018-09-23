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
    int a,b,c,i,x,y,w;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        p[i]=i;
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        a++;b++;
        edge.emplace_back(c,a,b);
    }
    sort(edge.begin(),edge.end());
    int sum=0;
    for(i=0;i<m;i++)
    {
        tie(w,x,y)=edge[i];
//        w=-w;
        if(Find(x)!=Find(y))
        {
            sum+=w;
            Union(x,y);
        }
    }
    printf("%d",sum);
}
