#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int n,m,a,b,x,y;
pair<int,int> seg[4135];
int pos[1135];
vector<int> order,h;
vector<int> adj[1135];
void dfs(int idx,int hi)
{
    int i;
    order.emplace_back(idx);
    h.emplace_back(hi);
    for(i=0;i<adj[idx].size();i++)
    {
        dfs(adj[idx][i],hi+1);
        order.emplace_back(idx);
        h.emplace_back(hi);
    }
    return;
}
void build(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(fst==lst)
    {
        seg[idx].X=h[fst];
        seg[idx].Y=order[fst];
        return;
    }
    build(idx*2,fst,mid);
    build(idx*2+1,mid+1,lst);
    if(seg[idx*2].X>=seg[idx*2+1].X)
        seg[idx].X=seg[idx*2+1].X,seg[idx].Y=seg[idx*2+1].Y;
    else
        seg[idx].X=seg[idx*2].X,seg[idx].Y=seg[idx*2].Y;
}
pair<int,int> Min(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(x<=fst&&y>=lst)
    {
        return seg[idx];
    }
    if(lst<x||fst>y)
    {
        return {1000000000,0};
    }
    pair<int,int> a=Min(idx*2,fst,mid),b=Min(idx*2+1,mid+1,lst);
    return a.X<b.X?a:b;
}
int main()
{
    int i,j,k,t,T,Q,tmp;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        memset(seg,0,sizeof seg);
        memset(pos,0,sizeof pos);
        order.clear();h.clear();
        for(i=0;i<=1000;i++)
            adj[i].clear();
        printf("Case %d:\n",t);
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a);
            for(j=1;j<=a;j++)
            {
                scanf("%d",&b);
                adj[i].emplace_back(b);
            }
        }
        dfs(1,1);
        for(i=order.size()-1;i>=0;i--)
        {
            pos[order[i]]=i;
        }
        build(1,0,order.size());
        scanf("%d",&Q);
        for(i=1;i<=Q;i++)
        {
            scanf("%d %d",&x,&y);
            x=pos[x];y=pos[y];
            if(x>y)tmp=x,x=y,y=tmp;
            printf("%d\n",Min(1,0,order.size()).Y);
        }
    }
}
