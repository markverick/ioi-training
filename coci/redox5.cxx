#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char a[250135];
int lazy[1000135],seg[1000135][11];
int tmp[11],x,y,val;
void shift(int idx,int fst,int lst)
{
    if(lazy[idx])
    {
        int i;
        if(fst!=lst)
        {
            lazy[idx*2]+=lazy[idx];
            lazy[idx*2+1]+=lazy[idx];
        }
        for(i=0;i<10;i++)
            tmp[i]=seg[idx][i];
        for(i=0;i<10;i++)
            seg[idx][(i+lazy[idx])%10]=tmp[i];
        lazy[idx]=0;
    }
}
void build(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(fst==lst)
    {
        seg[idx][a[fst]]=1;
        return;
    }
    build(idx*2,fst,mid);
    build(idx*2+1,mid+1,lst);
    for(int i=0;i<10;i++)
        seg[idx][i]=seg[idx*2][i]+seg[idx*2+1][i];
}
void update(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    shift(idx,fst,lst);
    if(lst<x||fst>y)
    {
        return;
    }
    if(fst>=x&&lst<=y)
    {
        lazy[idx]+=val;
        shift(idx,fst,lst);
        return;
    }
    update(idx*2,fst,mid);
    update(idx*2+1,mid+1,lst);
    for(int i=0;i<10;i++)
        seg[idx][i]=seg[idx*2][i]+seg[idx*2+1][i];
}
int sum(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2,i,sm=0;
    shift(idx,fst,lst);
    if(lst<x||fst>y)
    {
        return 0;
    }
    if(fst>=x&&lst<=y)
    {
        for(i=0;i<10;i++)
            sm+=seg[idx][i]*i;
        return sm;
    }
    return sum(idx*2,fst,mid)+sum(idx*2+1,mid+1,lst);
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,n,m;
	scanf("%d %d",&n,&m);
	scanf("%s",a+1);
	for(i=1;i<=n;i++)
        a[i]-='0';
    build(1,1,n);
	while(m--)
    {
        scanf("%d %d",&x,&y);
        val=sum(1,1,n);
        printf("%d\n",val);
        val=1;
        update(1,1,n);

    }
}
