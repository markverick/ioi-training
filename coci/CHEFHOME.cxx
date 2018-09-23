#include<bits/stdc++.h>
using namespace std;
int x[1135],y[1135];
int main()
{
    int T,i,j,k,a,b,mx,my,n,xx,yy;
    scanf("%d",&T);
    while(T--)
    {
        mx=0;my=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d %d",&x[i],&y[i]);
        }
        sort(&x[1],&x[n+1]);
        sort(&y[1],&y[n+1]);
        if(n%2==0)
        {
            xx=x[n/2+1]-x[n/2]+1;
            yy=y[n/2+1]-y[n/2]+1;
            printf("%lld\n",(long long)xx*yy);
        }
        else
            printf("%d\n",1);
    }
}
