#include<bits/stdc++.h>
#define MI 1000000000
#define B first
#define A second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
long long mn[500135];
pair<long long,long long> p[500135];
multiset<long long> in,ex,AB;
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	long long n,i,j,k,sum=0;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
    {
        scanf("%lld %lld",&p[i].A,&p[i].B);
        ex.insert(p[i].A);
    }
    sort(&p[1],&p[n+1]);
    mn[1]=*ex.begin();
    for(i=1;i<n;i++)
    {
        sum+=p[i].B;
        ex.erase(ex.find(p[i].A));
        mn[i+1]=sum+*ex.begin();
    }
    sum=0;
    for(i=1;i<=n;i++)
    {
        sum+=p[i].B;
        AB.insert(p[i].A-p[i].B);
        mn[i]=min(mn[i],sum+*AB.begin());
    }
    for(i=1;i<=n;i++)
    {
        printf("%lld\n",mn[i]);
    }
}
