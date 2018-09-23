#include<bits/stdc++.h>
using namespace std;
int lim[135],bes[135];
int a[135],b[135],c[135],d[135];
int main()
{
    freopen("speeding.in","r",stdin);
    freopen("speeding.out","w",stdout);
    int i,j,k,n,m,sum=0;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&a[i],&b[i]);
        for(j=sum+1;j<=sum+a[i];j++)
            lim[j]=b[i];
        sum+=a[i];
    }
    sum=0;
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&c[i],&d[i]);
        for(j=sum+1;j<=sum+c[i];j++)
            bes[j]=d[i];
        sum+=c[i];
    }
    int mc=0;
    for(i=1;i<=100;i++)
        if(bes[i]>lim[i])
            mc=max(mc,bes[i]-lim[i]);
    printf("%d",mc);
}
