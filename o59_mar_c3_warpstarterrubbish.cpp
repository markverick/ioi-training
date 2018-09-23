#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
using namespace std;
pair<long long,long long> p[100135];
set<pair<long long,long long> > st;
set<pair<long long,long long> > ::iterator it;
set<pair<long long,long long> > ::iterator it2;
long long dist(long long a,long long b)
{
    return abs(p[a].X-p[b].X)+abs(p[a].Y-p[b].Y);
}
int main()
{
    long long i,j,k,n,m;
    scanf("%lld %lld",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%lld %lld",&p[i].Y,&p[i].X);
    }
    if(m==1)
    {
        printf("0\n");return 0;
    }
    sort(&p[1],&p[n+1]);
    for(i=1;i<=n-m;i++)
    {
        sum=0;

    }
    printf("%lld",mn);

}
