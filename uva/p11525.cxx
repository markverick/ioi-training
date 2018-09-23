#include<bits/stdc++.h>
using namespace std;
int a[60000];
int ft[60000],n;
void add(int idx,int val)
{
    while(idx<=n)
    {
        ft[idx]+=val;
        idx+=idx&-idx;
    }
    return;
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
    int T,i,j,k,fst,lst,mid,mn;
    scanf("%d",&T);
    while(T--)
    {
        memset(ft,0,sizeof ft);
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            add(i,1);
        }
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(i==n)
                a[i]=0;
            a[i]++;fst=1;lst=n,mn=n;
            while(fst<=lst)
            {
                mid=(fst+lst)/2;
                if(sum(mid)<a[i])
                {
                    fst=mid+1;
                }
                else
                {
                    mn=min(mn,mid);
                    lst=mid-1;
                }
            }
            if(i>1)
                printf(" ");
            printf("%d",mn);
            add(mn,-1);
        }
        //printf("%d ",sum())
        printf("\n");
    }
}
