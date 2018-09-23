#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int n,x[18],y[18];
double jum[70000];
double dp(int bit)
{
    if(__builtin_popcount(bit)==n)
    {
        return 0;
    }
    if(jum[bit]>0.000000001)
        return jum[bit];
    double mn=MI;
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if((bit|(1<<i))==bit||(bit|(1<<j))==bit)
                continue;
            mn=min(mn,dp(bit|(1<<i)|(1<<j))+hypot(x[i]-x[j],y[i]-y[j]));
        }
    }
    return jum[bit]=mn;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,t=0;
	while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            return 0;
            t++;
        n*=2;
        memset(jum,0,sizeof jum);
        for(i=0;i<n;i++)
            scanf("%*s %d %d",&x[i],&y[i]);
        printf("Case %d: %.2f\n",t,dp(0));
    }
}
