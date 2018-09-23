#include<bits/stdc++.h>
using namespace std;
double d[20][20];
int x[20],y[20];
int n;
double jum[70000];
double dp(int bit)
{
    if(jum[bit]>=0)
        return jum[bit];
    if(__builtin_popcount(bit)==n*2)
    {
        return 0;
    }
    double mn=1000000000;
    int i,j;
    for(i=1;i<=n*2;i++)
    {
        for(j=1;j<=n*2;j++)
        {
            if(i==j)
                continue;
            if( (((1<<(i-1))|bit)!=bit)&& (((1<<(j-1))|bit)!=bit))
            {
                mn=min(mn,d[i][j]+dp( ((bit|(1<<(i-1)) )|(1<<(j-1)) ) ) );
            }
        }
    }
    return jum[bit]=mn;
}
int main()
{
    int i,j,k,T=0;
    while(scanf("%d",&n)!=EOF)
    {
        T++;
        if(n==0)
            return 0;
        for(i=0;i<=68000;i++)
            jum[i]=-1;
        for(i=1;i<=n*2;i++)
        {
            scanf("%*s %d %d",&x[i],&y[i]);
        }
        for(i=1;i<=n*2;i++)
        {
            for(j=1;j<=n*2;j++)
            {
                d[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
               // printf("%d\n",d[i][j]);
            }
        }
        printf("Case %d: %.2f\n",T,dp(0));
    }
}
