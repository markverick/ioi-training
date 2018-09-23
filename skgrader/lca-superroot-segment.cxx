#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int n,sk[100135],res[200135],C=1,pos[100135],x,y,val;
pair<int,int> seg[800135];
vector<int> adj[100135];
void dfs(int idx,int pa,int lv)
{
    int i;
    sk[idx]=lv;
    for(i=0;i<adj[idx].size();i++)
    {
        if(adj[idx][i]==pa)continue;
        pos[adj[idx][i]]=C;
        res[C++]=adj[idx][i];
        dfs(adj[idx][i],idx,lv+1);
        pos[idx]=C;
        res[C++]=idx;
    }
}
void build(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(fst==lst)
    {
        seg[idx]=MP(sk[res[fst]],res[fst]);
        return;
    }
    build(idx*2,fst,mid);
    build(idx*2+1,mid+1,lst);
    if(seg[idx*2].X<=seg[idx*2+1].X)
        seg[idx]=seg[idx*2];
    else
        seg[idx]=seg[idx*2+1];
}
pair<int,int> sum(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(lst<x||fst>y)
    {
        return make_pair(1000000000,0);
    }
    if(fst>=x&&lst<=y)
    {
        return seg[idx];
    }
    pair<int,int> a=sum(idx*2,fst,mid),b=sum(idx*2+1,mid+1,lst);
    if(a.X<=b.X)
        return a;
    else
        return b;
}
inline int lca(int a,int b)
{
    x=pos[a];y=pos[b];
    if(x>y)
        swap(x,y);
    return sum(1,1,C).Y;
}
int main()
{
	int i,j,k,m,a,b,c,r,ra,rb,rc;
	scanf("%d",&n);
    for(i=1;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    res[C]=1;pos[1]=C++;
    dfs(1,0,1);
    C--;
    build(1,1,C);
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d %d %d",&r,&a,&b);
        c=lca(a,b);
        ra=lca(r,a);
        rb=lca(r,b);
        rc=lca(r,c);
        if(rc!=c)
        {
            printf("%d\n",c);
        }
        else if(ra==rb&&ra==c)
        {
            printf("%d\n",c);
        }
        else if(ra==c)
        {
            printf("%d\n",rb);
        }
        else
        {
            printf("%d\n",ra);
        }
    }
}
