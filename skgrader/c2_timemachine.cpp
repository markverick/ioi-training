#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int x[15],y[15],p[15];
int jum[1135][15];
int dp(int bit,int idx)
{
    if(jum[bit][idx]!=1000000005)
        return jum[bit][idx];
    if(__builtin_popcount(bit)==k)
    {
        return ceil(hypot(n-x[idx],m-y[idx]));
    }
    int mn=1000000000,i;
    for(i=1;i<=k;i++)
    {
        if(bit== (bit|(1<<(i-1) )) )
            continue;
        mn=min(mn,dp(bit|(1<<(i-1)),idx));
        mn=min(mn,dp(bit|(1<<(i-1)),i)+ (int)ceil(hypot(x[i]-x[idx],y[i]-y[idx]))-p[i] ) ;
    }
    return jum[bit][idx]=mn;
}
int main()
{
    int i,j;
    for(i=0;i<=1100;i++)
        for(j=0;j<=12;j++)
            jum[i][j]=1000000005;
    scanf("%d %d %d",&n,&m,&k);
    for(i=1;i<=k;i++)
    {
        scanf("%d %d %d",&x[i],&y[i],&p[i]);
        x[i]++;y[i]++;
    }
    x[0]=1;y[0]=1;x[k+1]=n;y[k+1]=m;p[k+1]=0;
    printf("%d",dp(0,0));
}
