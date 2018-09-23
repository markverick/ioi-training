#include<bits/stdc++.h>
using namespace std;
int n,m;
int seg[400135],a[400135];
int L[400135],R[400135],len=2,x,y,val;
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
void update(int idx,int fst,int lst)
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
        update(L[idx],fst,mid);
    }
    else
    {
        if(R[idx]==0)
            R[idx]=len++;
        update(R[idx],mid+1,lst);
    }
    seg[idx]=seg[L[idx]]+seg[R[idx]];
}
int main()
{
    int i,j,k,ch;
    scanf("%d %d",&n,&m);
//    for(i=1;i<=n;i++)
//    {
//        scanf("%d",&a[i]);
//    }
    len=2;
    for(i=1;i<=m;i++)
    {
        scanf("%d",&ch);
        if(ch==2)
        {
            scanf("%d %d",&x,&y);
            printf("%d\n",sum(1,1,n));
        }
        else
        {
            scanf("%d %d",&val,&x);
            update(1,1,n);
        }
    }
}
