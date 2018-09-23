#include<bits/stdc++.h>
using namespace std;
int n,seg[800135],a[200135],out[200135],toAdd;
void build(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(fst==lst)
    {
        seg[idx]=1;
        return;
    }
    build(idx*2,fst,mid);
    build(idx*2+1,mid+1,lst);
    seg[idx]=seg[idx*2]+seg[idx*2+1];
}
int add(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2,x;
    if(fst==lst)
    {
        seg[idx]=0;
        return fst;
    }
    if(seg[idx*2]<toAdd)
    {
//        printf("R");
        toAdd-=seg[idx*2];
        x=add(idx*2+1,mid+1,lst);
    }
    else
    {
//        printf("L");
        x=add(idx*2,fst,mid);
    }
    seg[idx]=seg[idx*2]+seg[idx*2+1];
    return x;
}
int main()
{
    int T,i,j,k;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        build(1,1,n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=n;i>=1;i--)
        {
            toAdd=i-a[i];
            out[i]=add(1,1,n);
//            printf("%d ",out[i]);
        }
        for(i=1;i<=n;i++)
        {
            printf("%d ",out[i]);
        }
        printf("\n");
    }
}
