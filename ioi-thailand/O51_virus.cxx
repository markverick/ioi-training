#include<bits/stdc++.h>
using namespace std;
int n,i,a[100135],b[100135],mc=0;
int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=n;i++)
        scanf("%d",&b[i]);
    sort(&a[1],&a[n+1]);
    sort(&b[1],&b[n+1]);
    for(i=1;i<=n/2;i++)
    {
        mc=max(mc,a[i]);
        mc=max(mc,b[i]);
    }
    if(n%2)
    {
        mc=max(mc,a[n/2+1]);
        mc=max(mc,b[n/2+1]);
    }
    printf("%d",mc);
}
