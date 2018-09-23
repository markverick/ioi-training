#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
pair<long long,long long> p[1200];
long long dis[1200][1200];
int main()
{
    long long n,m,i,j,k;
    scanf("%lld %lld",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&p[i].X,&p[i].Y);
    }
    sort(&p[1],&p[n+1]);
    for(i=1;i<=n;i++)
    {
        long long sum=0;
        for(j=1;j<=n;j++)
        {
            if(j==i)
                dis[i][j]=p[j].X/2+p[j].Y;
            else
                dis[i][j]=p[j].X+p[j].Y;
        }
        sort(&dis[i][1],&dis[i][n+1]);
    }
    long long fst=0,lst=1000,mid,mc=0;
    while(fst<=lst)
    {

        mid=(fst+lst)/2;
        //printf("%lld %lld %lld\n",fst,mid,lst);
        long long sum=0;
        long long fc=0;
        for(i=1;i<=n;i++)
        {
            sum=0;
            for(j=1;j<=mid;j++)
            {
                sum+=dis[i][j];
            }
            //printf("%d\n",sum);
            if(sum<=m)
            {
                fc=1;
            }
        }
        if(fc==1)
        {
            mc=max(mc,mid);
            fst=mid+1;
        }
        else
        {
            lst=mid-1;
        }
    }
    printf("%lld\n",mc);
}
