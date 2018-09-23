#include<bits/stdc++.h>
int a[1000090],b[1000090],c[1000090],d[1000090];
int main()
{
    int n;

    int i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        b[i]=(b[i-1]+a[i])%2553;
        c[i]=(c[i-1]+b[i])%2553;
        d[i]=(d[i-1]+c[i])%2553;
    }
    printf("%d",d[n]);
}
