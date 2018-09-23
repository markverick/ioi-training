#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int ft[100135],a[100135],out[100135],n;
void add(int idx,int val)
{
    while(idx<=n)
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
	int i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<=n;i++)
    {
        if(a[i]<=n/2)
        {
            out[a[i]]=sum(n-a[i]+1)-sum(a[i]-1);
        }
        add(a[i],1);
    }
    memset(ft,0,sizeof ft);
    for(i=n;i>=1;i--)
    {
        if(a[i]>(n+1)/2)
        {
            out[a[i]]=sum(a[i])-sum(n-a[i]+1);
        }
        add(a[i],1);
    }
    for(i=1;i<=n/2;i++)
    {
        printf("%d\n%d\n",out[i],out[n-i+1]);
    }
    if(n%2)
        printf("0 ");
}
