#include<bits/stdc++.h>
#define INF 2000000005
using namespace std;
int n,h[100135];
vector<int> adj[100135];
int L[100135],R[100135],ste[100135],C=1,result[200135],Min[800135],cot[800135],lazy[800135],x,y,val;
void shift(int idx,int fst,int lst)
{
    if(lazy[idx])
    {
        if(fst!=lst)
        {
            lazy[idx*2]+=lazy[idx];
            lazy[idx*2+1]+=lazy[idx];
        }
        Min[idx]-=lazy[idx];
        lazy[idx]=0;
    }
}
void update(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    shift(idx,fst,lst);
    if(lst<x||fst>y)
    {
        return;
    }
    if(fst>=x&&lst<=y)
    {
        lazy[idx]+=val;
        shift(idx,fst,lst);
        return;
    }
    update(idx*2,fst,mid);
    update(idx*2+1,mid+1,lst);
    Min[idx]=min(Min[idx*2],Min[idx*2+1]);
    cot[idx]=cot[idx*2]+cot[idx*2+1];
}
int sum(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    shift(idx,fst,lst);
    if(lst<x||fst>y)
    {
        return 0;
    }
    if(fst>=x&&lst<=y)
    {
        return cot[idx];
    }
    return sum(idx*2,fst,mid)+sum(idx*2+1,mid+1,lst);
}
void build(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(fst==lst)
    {
        cot[idx]=1;
        Min[idx]=h[result[fst]];
        return;
    }
    build(idx*2,fst,mid);
    build(idx*2+1,mid+1,lst);
    Min[idx]=min(Min[idx*2],Min[idx*2+1]);
    cot[idx]=cot[idx*2]+cot[idx*2+1];
}
void rem(int idx,int fst,int lst)
{
    shift(idx,fst,lst);
    if(Min[idx]>0)
        return;
    int mid=(fst+lst)/2;
    if(lst<x||fst>y)
    {
        return;
    }
    if(fst==lst)
    {
        Min[idx]=INF;cot[idx]=0;
        return;
    }
    rem(idx*2,fst,mid);
    rem(idx*2+1,mid+1,lst);
    Min[idx]=min(Min[idx*2],Min[idx*2+1]);
    cot[idx]=cot[idx*2]+cot[idx*2+1];
    return;
}
void dfs(int idx)
{
    int i;
//    printf("%d %d\n",idx,C);
    ste[idx]=1;
    L[idx]=C;
    result[C++]=idx;
    for(i=0;i<adj[idx].size();i++)
    {
        if(ste[adj[idx][i]])continue;
        dfs(adj[idx][i]);
        R[adj[idx][i]]=C;
        result[C++]=adj[idx][i];
    }
}
int main()
{
//        freopen("outom.txt","w",stdout);

    int i,j,k,q,a,ch;
    scanf("%d",&n);
    h[0]=INF;
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&h[i],&a);
        adj[a].emplace_back(i);
    }
    dfs(0);
    result[C]=0;
    R[0]=C;
//    for(i=1;i<=C;i++)
//        printf("%d ",h[result[i]]);
//    printf("\n");
//    for(i=1;i<=C;i++)
//        printf("%d ",result[i]);
//    printf("\n");
//    for(i=0;i<=n;i++)
//        printf("%d <-> %d\n",L[i],R[i]);
//    printf("\n");
    scanf("%d",&q);
    build(1,1,C);
    while(q--)
    {
        scanf("%d %d",&ch,&a);
        x=L[a];y=R[a];
        x++;y--;
        if(ch==1)
        {
            scanf("%d",&val);
            if(x<=y)
                update(1,1,C);
        }
        else
        {
            if(x<=y)
            {
                rem(1,1,C);
                printf("%d\n",sum(1,1,C)/2);
            }
            else
                printf("0\n");
        }
    }
}
