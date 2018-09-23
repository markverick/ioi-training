#include<bits/stdc++.h>
using namespace std;
int n,x,y;
int seg[800135],lazy[800135];
void shift(int idx,int fst,int lst)
{
    if(lazy[idx]>0)
    {
        seg[idx]=lst-fst+1-seg[idx];
        lazy[idx*2]^=lazy[idx];
        lazy[idx*2+1]^=lazy[idx];
        lazy[idx]=0;
    }
}
void inv(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    shift(idx,fst,lst);
    if(x>lst||y<fst)
    {
        return;
    }
    if(fst>=x&&lst<=y)
    {
        lazy[idx]^=1;
        shift(idx,fst,lst);
        return;
    }
    inv(idx*2,fst,mid);
    inv(idx*2+1,mid+1,lst);
    seg[idx]=seg[idx*2]+seg[idx*2+1];
}
int sum(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    shift(idx,fst,lst);
    if(x>lst||y<fst)
    {
        return 0;
    }
    if(fst>=x&&lst<=y)
    {
        return seg[idx];
    }
    return sum(idx*2,fst,mid)+sum(idx*2+1,mid+1,lst);
}
int main()
{
    int i,j,k,Q,ch;
    scanf("%d %d",&n,&Q);
    while(Q--)
    {
        scanf("%d %d %d",&ch,&x,&y);
        x++;y++;
        if(ch==0)
        {
            inv(1,1,n);
        }
        else
        {
            printf("%d\n",sum(1,1,n));
        }
    }
}
