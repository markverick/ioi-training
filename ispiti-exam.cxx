#include<bits/stdc++.h>
using namespace std;
int a[200135],b[200135],seg[200135],n=0,cu;
char ch[200135][3];
pair<int,int> c[200135];
void build(int idx,int fst,int lst)
{
    if(fst==lst)
    {
        seg[idx]=1;
        return;
    }
    int mid=(fst+lst)/2;
    build(idx*2,fst,mid);
    build(idx*2+1,mid+1,lst);
    seg[idx]=seg[idx*2]+seg[idx*2+1];
}
int sum(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2,L,R;
    if(k==0)
        return 0;
    if(k>=seg[idx*2])
    {
        k-=seg[idx*2];
        return seg[idx*2]+sum(idx*2+1,mid+1,lst);
    }
    else
    {
        return sum(idx*2,fst,mid);
    }
}
void del(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
}
int main()
{
    int T,i,j,k;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%s",ch[i]);
        if(ch[i][0]=='D')
        {
            scanf("%d %d",&b[i],&a[i]);
            n++;
            c[n]=MP(a[i],b[i]);
        }
        else
        {
            scanf("%d",&a[i]);
        }
    }
    sort()
    build(1,1,n);
}
