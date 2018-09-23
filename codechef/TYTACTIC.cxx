#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
long long n,sk[100135],seg[800135],res[200135],C=1,L[100135],R[100135],x,y,val;
vector<long long> adj[100135];
void dfs(long long idx,long long pa)
{
    long long i;
    L[idx]=C;
    res[C++]=idx;
    for(i=0;i<adj[idx].size();i++)
    {
        if(adj[idx][i]==pa)continue;
        dfs(adj[idx][i],idx);
        R[adj[idx][i]]=C;
        res[C++]=adj[idx][i];
    }
}
void build(long long idx,long long fst,long long lst)
{
    long long mid=(fst+lst)/2;
    if(fst==lst)
    {
        seg[idx]=sk[res[fst]];
        return;
    }
    build(idx*2,fst,mid);
    build(idx*2+1,mid+1,lst);
    seg[idx]=seg[idx*2]+seg[idx*2+1];
}
void update(long long idx,long long fst,long long lst)
{
    long long mid=(fst+lst)/2;
    if(fst==lst)
    {
        seg[idx]=val;
        return;
    }
    if(x<=mid)
    {
        update(idx*2,fst,mid);
    }
    else
    {
        update(idx*2+1,mid+1,lst);
    }
    seg[idx]=seg[idx*2]+seg[idx*2+1];
}
long long sum(long long idx,long long fst,long long lst)
{
    long long mid=(fst+lst)/2;
    if(lst<x||fst>y)
    {
        return 0;
    }
    if(fst>=x&&lst<=y)
    {
        return seg[idx];
    }
    return sum(idx*2,fst,mid)+sum(idx*2+1,mid+1,lst);
}
int main()
{
	long long i,j,k,m,a,b;
	scanf("%lld %lld",&n,&m);
	for(i=1;i<=n;i++)
    {
        scanf("%lld",&sk[i]);
    }
    for(i=1;i<n;i++)
    {
        scanf("%lld %lld",&a,&b);
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    dfs(1,0);
    res[C]=1;R[1]=C;
//    for(i=1;i<=C;i++)
//    {
//        printf("%lld ",res[i]);
//    }
//    printf("\n");
//    for(i=1;i<=n;i++)
//    {
//        printf("%lld <-> %lld\n",L[i],R[i]);
//    }
    char ch[4];
    build(1,1,C);
    while(m--)
    {
        scanf("%s",ch);
        if(ch[0]=='Q')
        {
            scanf("%lld",&a);
            x=L[a];y=R[a];
            printf("%lld\n",sum(1,1,C)/2);
        }
        else
        {
            scanf("%lld %lld",&a,&val);
            x=L[a];
            update(1,1,C);
            x=R[a];
            update(1,1,C);
        }
    }
}
