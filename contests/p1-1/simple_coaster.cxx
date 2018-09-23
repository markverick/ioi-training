#include<bits/stdc++.h>
using namespace std;
int n;
char ch[3];
int lazy[8000135],seg[8000135],x,y,val,Hi[8000135];
void shift(int idx,int fst,int lst)
{
    if(lazy[idx]!=-2000000005)
    {
        seg[idx]=lazy[idx]*(lst-fst+1);
        Hi[idx]=max(0,seg[idx]);
        if(fst!=lst)
        {
            lazy[idx*2]=lazy[idx];
            lazy[idx*2+1]=lazy[idx];
        }
        lazy[idx]=-2000000005;
    }
}
void Set(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    shift(idx,fst,lst);
    if(lst<x||fst>y)
    {
        return;
    }
    if(fst>=x&&lst<=y)
    {
        seg[idx]=val*(lst-fst+1);
        Hi[idx]=max(0,seg[idx]);
        if(fst!=lst)
        {
            lazy[idx*2]=val;
            lazy[idx*2+1]=val;
        }
        return;
    }
    Set(idx*2,fst,mid);
    Set(idx*2+1,mid+1,lst);
    seg[idx]=seg[idx*2]+seg[idx*2+1];
    Hi[idx]=max(seg[idx*2]+Hi[idx*2+1],Hi[idx*2]);
}
int sum(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    shift(idx,fst,lst);
    if(fst==lst)
    {
        return seg[idx];
    }
    if(y<fst)
    {
        return 0;
    }
    if(y>lst)
    {
        return Hi[idx];
    }
    if(y>mid)
    {
        shift(idx*2,fst,mid);
        return max(sum(idx*2,fst,mid),seg[idx*2]+sum(idx*2+1,mid+1,lst));
    }
    if(y<=mid)
    {
        return sum(idx*2,fst,mid);
    }
}
int main()
{
    int i,j,k,fst,mid,lst,mc;
    for(i=0;i<=8000005;i++)
        lazy[i]=-2000000005;
    scanf("%d",&n);
    while(scanf("%s",ch)!=EOF)
    {
        if(ch[0]=='E')
            return 0;
        if(ch[0]=='I')
        {
            scanf("%d %d %d",&x,&y,&val);
            Set(1,1,n);
        }
        else
        {
            scanf("%d",&k);
            fst=0;lst=n;x=1;mc=0;
            while(fst<=lst)
            {
                mid=(fst+lst)/2;
                y=mid;
                if(sum(1,1,n)<=k)
                {
                    mc=max(mc,mid);
                    fst=mid+1;
                }
                else
                {
                    lst=mid-1;
                }
            }
            printf("%d\n",mc);
        }
    }
}
