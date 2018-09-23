#include<bits/stdc++.h>
using namespace std;
int n,m;
int seg[1000135],a[1000135];
int L[1000135],R[1000135],len=2,x,y,val,h,node;
int head[100135],q,t;
int sum(int idx,int fst,int lst)
{
    if(idx==0)
        return 0;
    int mid=(fst+lst)/2;
    if(fst>y||lst<x)
    {
        return 0;
    }
    if(fst>=x&&lst<=y)
    {
        return seg[idx];
    }
    return sum(L[idx],fst,mid)+sum(R[idx],mid+1,lst);
}
void build(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(fst==lst)
    {
        seg[idx]+=val;
        return;
    }
    if(x<=mid)
    {
        if(L[idx]==0)
            L[idx]=len++;
        build(L[idx],fst,mid);
    }
    else
    {
        if(R[idx]==0)
            R[idx]=len++;
        build(R[idx],mid+1,lst);
    }
    seg[idx]=seg[L[idx]]+seg[R[idx]];
}
void update(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(fst==lst)
    {
        node=len;
        seg[len++]=seg[idx]+val;
        return;
    }
    if(x<=mid)
    {
        update(L[idx],fst,mid);
        L[len]=node;
        R[len]=R[idx];
        node=len++;
    }
    else
    {
        update(R[idx],mid+1,lst);
        R[len]=node;
        L[len]=L[idx];
        node=len++;
    }
    seg[node]=seg[L[node]]+seg[R[node]];
}
int main()
{
    int i,j,k,ch,o;
    scanf("%d %d %d",&n,&m,&q);
    head[0]=1;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&val);
        x=i;
        build(1,1,n);
    }
    len=2;
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&x,&val);
        update(head[i-1],1,n);
        head[i]=node;
    }
    o=0;
    for(i=1;i<=q;i++)
    {
        scanf("%d %d",&x,&y);
        t=sum(head[o],1,n);
        printf("%d\n",t);
        o=(t)%(m+1);
    }
}
