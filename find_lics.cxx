#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int n,m;
pair<pair<int,int>,pair<int,pair<int,int> > > st[800002];
//FirstNum LastNum Whole FromFirst FromLast
int toAdd,val;
int x,y;
void add(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    //printf("%d\n",idx);
    if(fst>=lst)
    {
        st[idx].X.X+=val;
        st[idx].X.Y+=val;
        st[idx].Y.X=1;
        st[idx].Y.Y.X=1;
        st[idx].Y.Y.Y=1;
        return;
    }
    if(toAdd<=mid)
    {
        add(idx*2,fst,mid);
    }
    else
    {
        add(idx*2+1,mid+1,lst);
    }
    int mc=0;
    mc=max(st[idx*2].Y.X,st[idx*2+1].Y.X);
    if(st[idx*2].X.Y<st[idx*2+1].X.X)
        mc=max(mc,st[idx*2].Y.Y.Y+st[idx*2+1].Y.Y.X);
    st[idx].Y.X=mc;
    st[idx].X.X=st[idx*2].X.X;
    st[idx].X.Y=st[idx*2+1].X.Y;
    if(st[idx*2].Y.Y.X==mid-fst+1&&st[idx*2].X.Y<st[idx*2+1].X.X)
        st[idx].Y.Y.X=mid-fst+1+st[idx*2+1].Y.Y.X;
    else
        st[idx].Y.Y.X=st[idx*2].Y.Y.X;
    if(st[idx*2+1].Y.Y.Y==lst-mid && st[idx*2].X.Y<st[idx*2+1].X.X)
        st[idx].Y.Y.Y=lst-mid+st[idx*2].Y.Y.Y;
    else
        st[idx].Y.Y.Y=st[idx*2+1].Y.Y.Y;
    return;
}
pair<pair<int,int>,pair<int,pair<int,int> > > sum(int idx,int fst,int lst)
{
    pair<pair<int,int>,pair<int,pair<int,int> > >L,R,ppp;
    int mid=(fst+lst)/2;
    if(x>lst||y<fst)
    {
        return { {0,0} , {0 , { 0, 0}  } };
    }
    if(fst>=x&&lst<=y)
    {
        return st[idx];
    }
    L=sum(idx*2,fst,mid);
    R=sum(idx*2+1,mid+1,lst);
    int mc=0;
    mc=max(L.Y.X,R.Y.X);
    if(L.X.Y<R.X.X)
        mc=max(mc,L.Y.Y.Y+R.Y.Y.X);
    ppp.Y.X=mc;
    ppp.X.X=L.X.X;
    ppp.X.Y=R.X.Y;
    if(L.Y.Y.X==mid-fst+1&&L.X.Y<R.X.X)
        ppp.Y.Y.X=mid-fst+1+R.Y.Y.X;
    else
        ppp.Y.Y.X=L.Y.Y.X;
    if(R.Y.Y.Y==lst-mid && L.X.Y<R.X.X)
        ppp.Y.Y.Y=lst-mid+L.Y.Y.Y;
    else
        ppp.Y.Y.Y=R.Y.Y.Y;
    return ppp;
}
int main()
{
    int i,j,k,T,a;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a);
            val=a;toAdd=i;
            add(1,1,n);
        }
        for(i=0;i<m;i++)
        {
            scanf("%d",&a);
            if(a==1)
            {
                scanf("%d %d",&val,&toAdd);
                add(1,1,n);
            }
            else
            {
                scanf("%d %d",&x,&y);
                printf("%d\n",sum(1,1,n).Y.X);
            }
        }
    }
}
