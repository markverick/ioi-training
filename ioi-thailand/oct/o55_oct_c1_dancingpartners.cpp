#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int a[100135],b[100135],x[100135],y[100135],n;
pair<int,int> seg[100135]; //HeightDiff Beauty
int lazy[100135];
void build(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(fst==lst)
    {
        seg[idx]={a[fst],b[fst]};
        return;
    }
    build(idx*2,fst,mid);
    build(idx*2+1,mid+1,lst);
    if(seg[idx*2].Y-abs(seg[idx*2].X)>=seg[idx*2+1].Y-abs(seg[idx*2+1].X))
    {
        seg[idx]=seg[idx*2];
    }
    else
    {
        seg[idx]=seg[idx*2+1];
    }
}
int Max(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(lazy[idx]>0)
    {
        if(seg[idx*2].Y-abs(seg[idx*2].X-lazy[idx])>=seg[idx*2+1].Y-abs(seg[idx*2+1].X-lazy[idx]))
        {
            seg[idx]={seg[idx*2].X-lazy[idx],seg[idx*2].Y};
        }
        else
        {
            seg[idx]={seg[idx*2].X-lazy[idx],seg[idx*2].Y}
        }
        lazy[idx*2]+=lazy[idx];
        lazy[idx*2+1]+=lazy[idx];
        lazy[idx]=0;
    }
    if(seg[])
    Max(idx*2,fst,mid+1);
}
int main()
{
    int i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&x[i],&y[i]);
    }
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&a[i],&b[i]);
    }
    for(i=1;i<=n;i++)
    {
        lazy[1]+=x[i];
    }
}
