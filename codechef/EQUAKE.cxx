#include<bits/stdc++.h>
using namespace std;
int n,seg[3200005][14],lazy[3200005],len[800135],x,y,val;
char a[800135][14];
void build(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2,i,j,k;
    if(fst==lst)
    {
        j=0;
        k=1;
        for(i=0;i<len[fst];i++)
        {
            j*=10;
            j+=a[fst][i]-'0';
            k*=10;
        }
        for(i=0;i<len[fst];i++)
        {
            seg[idx][i]=j;
            j=(j*10)%k+a[fst][i]-'0';
        }
        for(i=len[fst];i<12;i++)
        {
            seg[idx][i]=seg[idx][i%len[fst]];
        }
//        for(i=0;i<12;i++)
//            printf("%d ",seg[idx][i]);
//        printf("\n");
        return;
    }
    build(idx*2,fst,mid);
    build(idx*2+1,mid+1,lst);
    for(i=0;i<12;i++)
    {
        seg[idx][i]=max(seg[idx*2][i],seg[idx*2+1][i]);
    }
}
int tmp[14];
//void slide(int idx,int amp)
//{
//    int i;
//    for(i=0;i<12;i++)
//        tmp[i]=seg[idx][i];
//    for(i=0;i<12;i++)
//        seg[idx][i]=tmp[(i+amp)%12];
//
//}
void shift(int idx,int fst,int lst)
{
    if(lazy[idx]>0)
    {
        if(fst!=lst)
        {
            lazy[idx*2]+=lazy[idx];
            lazy[idx*2+1]+=lazy[idx];
        }
        int i;
        for(i=0;i<12;i++)
            tmp[i]=seg[idx][(i+lazy[idx])%12];
        for(i=0;i<12;i++)
            seg[idx][i]=tmp[i];
        lazy[idx]=0;
    }
}
void add(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2,i;
    shift(idx,fst,lst);
    if(fst>=x&&lst<=y)
    {
        lazy[idx]+=val;
        shift(idx,fst,lst);
        return;
    }
    if(lst<x||fst>y)
    {
        return;
    }
    add(idx*2,fst,mid);
    add(idx*2+1,mid+1,lst);
    for(i=0;i<12;i++)
        seg[idx][i]=max(seg[idx*2][i],seg[idx*2+1][i]);
}
int Max(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    shift(idx,fst,lst);
    if(fst>=x&&lst<=y)
    {
        return seg[idx][0];
    }
    if(lst<x||fst>y)
    {
        return 0;
    }
    return max(Max(idx*2,fst,mid),Max(idx*2+1,mid+1,lst));
}
int main()
{
    int i,j,k,Q,ch;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%s",a[i]);
        j=strlen(a[i]);
        len[i]=j;
        for(k=j;k<12;k++)
        {
            a[i][k]=a[i][k%j];
        }
//        printf("%s\n",a[i]);
    }
//    system("pause");
    build(1,1,n);
    scanf("%d",&Q);
    while(Q--)
    {
        scanf("%d",&ch);
        if(ch==0)
        {
            scanf("%d %d %d",&x,&y,&val);
            x++;y++;
            add(1,1,n);
        }
        else
        {
            scanf("%d %d",&x,&y);
            x++;y++;
            printf("%d\n",Max(1,1,n));
        }
    }
}
