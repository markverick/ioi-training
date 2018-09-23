#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
pair<int,int> seg[800135];
pair<int,int> lazy[800135];
int val,x,y,h;
void shift(int idx)
{
    if(lazy[idx].X==-1)
        return;
    seg[idx].X=min(lazy[idx].X,seg[idx].X);
    seg[idx].Y=max(lazy[idx].Y,seg[idx].Y);
    lazy[idx*2].X=min(lazy[idx*2].X,lazy[idx].X);
    lazy[idx*2+1].X=min(lazy[idx*2+1].X,lazy[idx].X);
    lazy[idx*2].Y=max(lazy[idx*2].Y,lazy[idx].Y);
    lazy[idx*2+1].Y=max(lazy[idx*2+1].Y,lazy[idx].Y);
    lazy[idx].X=-1;
    lazy[idx].Y=-1;
}
void add(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    shift(idx);
    if(lst<x||fst>y)
    {
        return;
    }
    if(fst>=x&&lst<=y)
    {
        seg[idx].X=max(seg[idx].X,val);
        seg[idx].Y=max(seg[idx].Y,val);
        if(lazy[idx].X>=0)
        {
            lazy[idx*2].X=min(lazy[idx*2].X,val);
            lazy[idx*2].Y=max(lazy[idx*2].Y,val);
            lazy[idx*2+1].X=min(lazy[idx*2+1].X,val);
            lazy[idx*2+1].Y=max(lazy[idx*2+1].Y,val);
            lazy[idx]=make_pair(-1,-1);
        }
        else
        {
            lazy[idx*2]=make_pair(val,val);
            lazy[idx*2+1]=make_pair(val,val);
        }
        return;
    }
    add(fst*2,fst,mid);
    add(fst*2+1,mid+1,lst);
    seg[idx].X=min(seg[idx*2].X,seg[idx*2+1].X);
    seg[idx].Y=max(seg[idx*2].Y,seg[idx*2+1].Y);
    return;
}
int sum(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    shift(idx);
    // printf("8=D %d %d %d\n",idx,fst,lst);
    if(lst<x||fst>y)
    {
        return 0;
    }
    if(fst>=x&&lst<=y)
    {
        printf("8=D %d %d\n",seg[idx].X,seg[idx].Y);
        if(h<seg[idx].X)
        {
            return 0;
        }
        else if(h>=seg[idx].Y)
        {
            return (lst-fst+1);
        }
        return sum(idx*2,fst,mid)+sum(idx*2+1,mid+1,lst);
    }
    return sum(idx*2,fst,mid)+sum(idx*2+1,mid+1,lst);
}
int main()
{
    int T,i,j,k,n,a,b,c,sm=0;
    scanf("%d",&T);
    while(T--)
    {
        for(i=0;i<=800005;i++)
        {
            seg[i]=make_pair(0,0);
            lazy[i]=make_pair(-1,-1);
        }
        scanf("%d",&n);
        sm=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            b--;
            x=a;y=b;h=c;
            sm+=sum(1,1,100000);
            val=c;
            add(1,1,100000);
            printf("%d\n",sm);
        }
        printf("%d\n",sm);
    }
    scanf("%*d");
}

