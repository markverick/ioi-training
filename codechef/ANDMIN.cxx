#include<bits/stdc++.h>
using namespace std;
int a[100135],seg[400135],bit[400135],x,y,val;
void build(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2,i;
    if(fst==lst)
    {
        seg[idx]=a[fst];
        bit[idx]=a[fst];
        return;
    }
    build(idx*2,fst,mid);
    build(idx*2+1,mid+1,lst);
    bit[idx]=bit[idx*2]|bit[idx*2+1];
    seg[idx]=min(seg[idx*2],seg[idx*2+1]);
}
void update(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(lst<x||fst>y)
    {
        return;
    }
    if(fst>=x&&lst<=y)
    {
        if(fst==lst)
        {
            bit[idx]&=val;
            seg[idx]=bit[idx];
            return;
        }
        if(~((~bit[idx])|val))
        {
            update(idx*2,fst,mid);
            update(idx*2+1,mid+1,lst);
            bit[idx]=bit[idx*2]|bit[idx*2+1];
            seg[idx]=min(seg[idx*2],seg[idx*2+1]);
        }
        return;
    }
    update(idx*2,fst,mid);
    update(idx*2+1,mid+1,lst);
    bit[idx]=bit[idx*2]|bit[idx*2+1];
    seg[idx]=min(seg[idx*2],seg[idx*2+1]);
}
int Min(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(lst<x||fst>y)
    {
        return 1000000000;
    }
    if(fst>=x&&lst<=y)
    {
        return seg[idx];
    }
    return min(Min(idx*2,fst,mid),Min(idx*2+1,mid+1,lst));
}
int main()
{
    int i,j,k,n,q,ch;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    build(1,1,n);
    while(q--)
    {
        scanf("%d",&ch);
        if(ch==0)
        {
            scanf("%d %d",&x,&y);
            printf("%d\n",Min(1,1,n));
        }
        else
        {
            scanf("%d %d %d",&x,&y,&val);
            update(1,1,n);
        }
    }
}
