#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
pair<int,int> seg[4000135];
int val,toAdd;
void build(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(fst==lst)
    {
        seg[idx].X=fst;
        seg[idx].Y=0;
        return;
    }
    build(idx*2,fst,mid);
    build(idx*2+1,mid+1,lst);
    if(seg[idx*2+1].Y>=seg[idx*2].Y)
    {
        seg[idx]=seg[idx*2+1];
    }
    else
    {
        seg[idx]=seg[idx*2];
    }
}
void add(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(fst==lst)
    {
        seg[idx].Y+=val;
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
    if(seg[idx*2+1].Y>=seg[idx*2].Y)
    {
        seg[idx]=seg[idx*2+1];
    }
    else
    {
        seg[idx]=seg[idx*2];
    }
}
int main()
{
    int n,m,p,i,j,k;
    char ch[5];
    scanf("%d %d %d",&n,&m,&p);
    build(1,1,n);
    for(i=1;i<=m+p;i++)
    {
        scanf("%s",ch);
        if(ch[0]=='L')
        {
            scanf("%*d %d",&toAdd);
            val=1;
            add(1,1,n);
        }
        else if(ch[0]=='C')
        {
            scanf("%*d %d",&toAdd);
            val=3;
            add(1,1,n);
        }
        else if(ch[0]=='R')
        {
            printf("%d\n",seg[1].X);
        }
        else if(ch[0]=='D')
        {
            val=-1000000000;
            toAdd=seg[1].X;
            add(1,1,n);
        }
    }
}
