#include<bits/stdc++.h>
using namespace std;
int x[5200];
int y[5200];
int main()
{
    int s,i,j,k,n;
    scanf("%d %d",&s,&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&x[i],&y[i]);
    }
    sort(&x[1],&x[n+1]);
    sort(&y[1],&y[n+1]);
    double mx=0,my=0;
    for(i=2;i<=n;i++)
    {
        mx=max(mx,(double)abs(x[i]-x[i-1])/2);
        my=max(my,(double)abs(y[i]-y[i-1])/2);
    }
    mx=max(mx,(double)x[1]);
    my=max(my,(double)y[1]);
    mx=max(mx,s-(double)x[n]);
    my=max(my,s-(double)y[n]);
    printf("%.3lf",min(mx,my));
}
