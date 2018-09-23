#include<bits/stdc++.h>
using namespace std;
long long f[100135];
long long sp[100135][50];
long long ja[100135];
long long jb[100135];
int main()
{
    long long n,i,j,k,m,x,y,sz,a,b;
    scanf("%lld",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&f[i]);
        sp[i][0]=f[i];
    }
    for(j=1;(1<<j)<=n;j++)
    {
        for(i=0;i+(1<<j)<=n;i++)
        {
            sp[i][j]=max(sp[i][j-1],sp[i+(1<<(j-1))][j-1]);
        }
    }
    long long sm=0;
    scanf("%lld %lld %lld",&m,&x,&y);
    for(i=1;i<=m;i++)
    {
       // printf("%lld %lld\n",x,y);
        if(x<=y)
        {
            a=x;b=y;
        }
        else
        {
            a=y;b=x;
        }
        sz=(long long)floor(log2(b-a+1));
        sm+=max(sp[a][sz],sp[b-(1<<(sz))+1][sz]);
        //printf("%lld\n",sm);
        x+=7;x%=(n-1);
        y+=11;y%=(n);
    }
    printf("%lld",sm);
}
