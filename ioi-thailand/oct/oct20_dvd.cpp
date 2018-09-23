#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
pair<int,int> seg[400135];
int n,m,x,y;
void build(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(fst==lst)
    {
        seg[idx]={fst,fst};
        return;
    }
    build(idx*2,fst,mid);
    build(idx*2+1,mid+1,lst);
    seg[idx].X=min(seg[idx*2].X,seg[idx*2+1].X);
    seg[idx].Y=max(seg[idx*2].Y,seg[idx*2+1].Y);
    return;
}
int Find(int idx,int fst,int lst,int tofnd)
{
    int mid=(fst+lst)/2;
    if(fst==lst)
        return idx;
    if(tofnd<=mid)
        return Find(idx*2,fst,mid,tofnd);
    else
        return Find(idx*2+1,mid+1,lst,tofnd);
}
void update(int idx,int fst,int lst,int toup)
{
    int mid=(fst+lst)/2;
    if(fst==lst)
    {
        return;
    }
    if(toup<=mid)
    {
        update(idx*2,fst,mid,toup);
    }
    else
    {
        update(idx*2+1,mid+1,lst,toup);
    }
    seg[idx].X=min(seg[idx*2].X,seg[idx*2+1].X);
    seg[idx].Y=max(seg[idx*2].Y,seg[idx*2+1].Y);
}
void Swap()
{
    int st=Find(1,1,n,x),ed=Find(1,1,n,y);
    int L=seg[st].X,R=seg[ed].X;
    seg[st]={R,R};
    seg[ed]={L,L};
    update(1,1,n,x);
    update(1,1,n,y);
}
bool chk(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(lst<x||fst>y)
        return 1;
    if(fst>=x&&lst<=y)
    {
        if(seg[idx].X>=x&&seg[idx].Y<=y)
            return 1;
        else
            return 0;
    }
    return min(chk(idx*2,fst,mid),chk(idx*2+1,mid+1,lst));
}
int main()
{
    int i,j,k,ch;
    scanf("%d %d",&n,&m);
    build(1,1,n);
    for(i=1;i<=m;i++)
    {
        scanf("%d",&ch);
        if(ch==0)
        {
            scanf("%d %d",&x,&y);
            x++;y++;
            Swap();
        }
        else
        {
            scanf("%d %d",&x,&y);
            x++;y++;
            if(chk(1,1,n))
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
}
