#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
pair<long long,long long> p[100135];
long long n;
long long cp(long long fst,long long lst)
{
    if(fst==lst)
    {
        return 1000000000;
    }
    long long mid=(fst+lst)/2,i,j;
    long long a,b,mn,x,md;
    a=cp(fst,mid);
    b=cp(mid+1,lst);
    mn=min(a,b);
    x=mn;
    md=(long long)(p[mid].X+p[mid+1].X)/2;
    for(i=mid;i>=fst;i--)
    {
        if(md-p[i].X>x)
            break;
        for(j=mid+1;j<=lst;j++)
        {
            if(p[j].X-md>x)
                break;
            mn=min(mn,(p[i].X-p[j].X)*(p[i].X-p[j].X)+(p[i].Y-p[j].Y)*(p[i].Y-p[j].Y));
        }
    }
    return mn;
}
int main()
{
    long long i,j,k;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lld %lld",&p[i].X,&p[i].Y);
    }
    sort(&p[1],&p[n+1]);
    printf("%lld",cp(1,n));
}
