#include<bits/stdc++.h>
using namespace std;
long long x[2135],y[2135],d[2135][2135];
int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    long long t,T,i,j,k,n,sum,cot;
    scanf("%I64d",&T);
    for(t=1;t<=T;t++)
    {
        sum=0;cot=0;
        memset(x,0,sizeof x);
        memset(y,0,sizeof y);
        memset(d,0,sizeof d);
        scanf("%I64d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%I64d %I64d",&x[i],&y[i]);
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                d[i][j]=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
            }
            sort(&d[i][1],&d[i][n+1]);
            cot=1;
            for(j=2;j<=n;j++)
            {
                if(d[i][j]==d[i][j-1])
                {
                    cot++;
                }
                else
                {
                    sum+=cot*(cot-1)/2;
                    cot=1;
                }
            }
            sum+=cot*(cot-1)/2;
        }
        printf("Case #%I64d: %I64d\n",t,sum);
    }
}
