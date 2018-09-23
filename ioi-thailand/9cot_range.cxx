#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
using namespace std;
int n,k,m,val,toSet,x,y;
pair<int,int> st[500135];
int a[100135];
int i,j;
pair<int,int> Min[15];
pair<int,int> Max[15];
void Set(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(fst>=lst)
    {
        st[idx].X=val;
        st[idx].Y=val;
        return;
    }
    if(toSet<=mid)
    {
        Set(idx*2,fst,mid);
        st[idx].X=min(st[idx*2].X,st[idx*2+1].X);
        st[idx].Y=max(st[idx*2].Y,st[idx*2+1].Y);
    }
    else
    {
        Set(idx*2+1,mid+1,lst);
        st[idx].X=min(st[idx*2+1].X,st[idx*2+1].X);
        st[idx].Y=max(st[idx*2+1].Y,st[idx*2+1].Y);
    }
    return;
}
void del(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(fst>=lst)
    {
        Max[i]=MP(fst,st[idx]);
        st[idx].X=0;
        st[idx].Y=1000000000;
        return;
    }
    if(toSet<=mid)
    {
        del(idx*2,fst,mid);
        st[idx].X=min(st[idx*2].X,st[idx*2+1].X);
        st[idx].Y=max(st[idx*2].Y,st[idx*2+1].Y);
    }
    else
    {
        del(idx*2+1,mid+1,lst);
        st[idx].X=min(st[idx*2+1].X,st[idx*2+1].X);
        st[idx].Y=max(st[idx*2+1].Y,st[idx*2+1].Y);
    }
    return;
}
pair<int,int> mnm(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(x>lst||y<fst)
    {
        return MP(1000000000,0);
    }
    if(fst>=x&&lst<=y)
    {
        return st[idx];
    }
    pair<int,int> t1=mnm(idx*2,fst,mid);
    pair<int,int> t2=mnm(idx*2+1,mid+1,lst);
    return MP(min(t1.X,t2.X),max(t1.Y,t2.Y));
}

int main()
{
    scanf("%d %d %d",&n,&k,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        toSet=i;
        val=a[i];
        Set(1,1,n);
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&x,&y);
        for(i=1;i<=k;i++)
        {
            pair<int,int> tmp=mnm(1,n,n);
            toSet=tmp.Y;
            Del(1,1,n);
        }
    }
}
