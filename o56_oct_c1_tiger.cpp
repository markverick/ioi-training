#include<bits/stdc++.h>
using namespace std;
int a[1135],b[1135],x[1135],y[1135];
int tiger[1135],hsh[1000135];
int main()
{
    int n,m,i,j,k;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&a[i],&b[i]);
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&x[i],&y[i]);
        tiger[i]=1000000000;
    }
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            tiger[i]=min(tiger[i],abs(x[i]-a[j])+abs(y[i]-b[j]));
        }
    }
    for(i=1;i<=m;i++)
    {
        hsh[tiger[i]]++;
    }
    int  mc=0;
    for(i=1;i<=1000000;i++)
    {
        mc=max(mc,hsh[i]);
    }
    printf("%d",mc);
}
