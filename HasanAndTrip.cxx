#include<bits/stdc++.h>
using namespace std;
int n;
double x[3135],y[3135],w[3135];
double jum[3135];
double dp(int idx)
{
    if(jum[idx]>-1000000000)
        return jum[idx];
    if(idx==n)
    {
        return 0;
    }
    double mc=-1000000000;
    for(int i=idx+1;i<=n;i++)
    {
        mc=max(mc,dp(i)+w[i]-hypot(x[i]-x[idx],y[i]-y[idx]));
    }
    return jum[idx]=mc;
}
int main()
{
    int i,j,k;
    scanf("%d",&n);
    for(i=0;i<=n+1;i++)
        jum[i]=-1000000000;
    for(i=1;i<=n;i++)
    {
        scanf("%lf %lf %lf",&x[i],&y[i],&w[i]);
    }
    printf("%.6f",dp(1)+w[1]);
}
