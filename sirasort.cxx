#include<bits/stdc++.h>
using namespace std;
int ft[100135];
int a[100135],b[100135],c[100135];
vector<int> d;
int n;
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
        b[a[i]]=sum(1+n-a[i])-sum(a[i]-1);
        add(a[i],1);
    }
    for(i=1;i<=n;i++)
        add(i,-1);
    for(i=n;i>=1;i--)
    {
        c[a[i]]=sum(a[i]-1)-sum(n+1-a[i]);
        add(a[i],1);
    }
    for(i=1;i<=n/2;i++)
    {
        d.emplace_back(b[i]);
        d.emplace_back(c[n+1-i]);
    }
    if(n%2)
        d.emplace_back(0);
    for(i=0;i<d.size();i++)
        printf("%d\n",d[i]);
}
