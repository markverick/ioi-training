#include<bits/stdc++.h>
using namespace std;
long long maps[531][531],a[505][505],b[505][505],c[505],d[505];
int main()
{
//    freopen("outom.txt","w",stdout);
    long long T,n,i,j,k,mc,sum;
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld",&n);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=i;j++)
            {
                scanf("%lld",&maps[i][j]);
            }
        }
        memset(a,0,sizeof a);
        memset(d,0,sizeof d);
        memset(c,0,sizeof c);
        memset(b,0,sizeof b);
        a[1][1]=maps[1][1];
        for(i=2;i<=n;i++)
        {
            for(j=1;j<=i;j++)
            {
                for(k=-1;k<=1;k++)
                {
                    if(j+k>=1&&j+k<=i)
                    {
                        a[i][j]=max(a[i][j],a[i-1][j+k]+maps[i][j]);
                        if(n-i+1==j)
                        {
                            if(k!=1)
                                c[j]=max(c[j],a[i-1][j+k]+maps[i][j]);
                        }
                    }
                }
            }
        }
        b[n][n]=maps[n][n];
        sum=0;
        for(i=n-1;i>=1;i--)
        {
            for(j=n;j>=i;j--)
            {
                for(k=-1;k<=1;k++)
                {
                    if(j+k<=n&&j+k>=i)
                    {
                        b[j][i]=max(b[j][i],b[j+k][i+1]+maps[j][i]);
                        if(i==n-j+1)
                        {
                            if(k!=-1)
                            {
                                d[i]=max(d[i],b[j+k][i+1]+maps[j][i]);
                            }
                        }
                    }
                }
            }
        }
        mc=0;sum=0;
        for(i=1;i<=n;i++)
        {
            mc=max(mc,a[n-i+1][i]+d[i]+sum-maps[n-i+1][i]);
            mc=max(mc,b[n-i+1][i]+c[i]+sum-maps[n-i+1][i]);
            sum+=maps[n-i+1][i];
        }
        printf("%lld\n",mc);
    }
}
