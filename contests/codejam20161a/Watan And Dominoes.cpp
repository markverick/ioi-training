#include<bits/stdc++.h>
using namespace std;
int ft[1000135],h[1000135];
void add(int idx,int val)
{
    while(idx<=1000005)
    {
        ft[idx]+=val;
        idx+=idx&-idx;
    }
}
int sum(int idx)
{
    int sm=0;
    while(idx>0)
    {
        sm+=ft[idx];
        idx-=idx&-idx;
    }
    return sm;
}
int main()
{
    int T,n,i,j,k;
    scanf("%d",&T);
    while(T--)
    {
        memset(ft,0,sizeof ft);
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&h[i]);
            h[i]++;
            printf("%d\n",sum(h[i]-1));
            add(h[i],1);
        }
    }
}
