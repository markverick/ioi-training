#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[1000135];
int sum=0;
int main()
{
    int i;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    sum=0;
    int mc=-2000000000;
    for(i=1;i<=k;i++)
    {
        sum+=a[i];
    }
    mc=max(mc,sum);
    for(i=k+1;i<=n;i++)
    {
        sum-=a[i-k];
        sum+=a[i];
        mc=max(mc,sum);
    }
    printf("%d",mc);
}
