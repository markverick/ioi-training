#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
using namespace std;
int n,m;
pair<int,int> st[800002];
int toAdd,val;
int x,y;
void add(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(fst>=lst)
    {
        st[idx].X=val;
        st[idx].Y=val;
        return;
    }

    if(toAdd<=mid)
    {
        add(idx*2,fst,mid);
        st[idx].X=min(st[idx*2].X,st[idx*2+1].X);
        st[idx].Y=max(st[idx*2].Y,st[idx*2+1].Y);
    }
    else
    {
        add(idx*2+1,mid+1,lst);
        st[idx].X=min(st[idx*2+1].X,st[idx*2+1].X);
        st[idx].Y=max(st[idx*2+1].Y,st[idx*2+1].Y);
    }
    return;
}
pair<int,int> sum(int idx,int fst,int lst)
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
    pair<int,int> t1=sum(idx*2,fst,mid);
    pair<int,int> t2=sum(idx*2+1,mid+1,lst);
    return MP(min(t1.X,t2.X),max(t1.Y,t2.Y));
}
int main()
{
    int i,j,k;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++)
    {
        int a;
        scanf("%d",&a);
        if(a==1)
        {
            scanf("%d %d",&val,&toAdd);
            add(1,1,n);
        }
        else
        {
            scanf("%d %d",&x,&y);
            pair<int,int> tmp=sum(1,1,n);
            printf("%d %d\n",tmp.X,tmp.Y);
        }
    }
}
