#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
using namespace std;
int n,k,m,val,toAdd,x,y;
pair<int,int> st[500135];
int a[100135];
void add(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    st[idx].X=min(st[idx].X,val);
    st[idx].Y=max(st[idx].Y,val);
    if(fst>=lst)
        return;
    if(toAdd<=mid)
    {
        add(idx*2,fst,mid);
    }
    else
    {
        add(idx*2+1,mid+1,lst);
    }
    return;
}
void del(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    //st[idx].X=min(st[idx].X,1000000000);
    //st[idx].Y=max(st[idx].Y,0);
    if(fst>=lst)
    {
        st[idx].X=a[fst];
        st[idx].Y=a[fst];
        return;
    }

    if(toAdd<=mid)
    {
        add(idx*2,fst,mid);
        st[idx].X=min(st[idx*2].X,1000000000);
        st[idx].Y=max(st[idx*2].Y,0);
    }
    else
    {
        add(idx*2+1,mid+1,lst);
        st[idx].X=min(st[idx*2+1].X,1000000000);
        st[idx].Y=max(st[idx*2+1].Y,0);
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
    int i,j;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        toAdd=i;
        val=a[i];
        add(1,1,n);
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&x,&y);
        for(i=1;i<=k;i++)
        {
            pair<int,int> tmp=mnm(1,n,n);

        }
    }
}
