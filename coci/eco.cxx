#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
long long h[1000135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	long long n,m,i,j,k,fs,md,ls,sum,mc=0;
    scanf("%lld %lld",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%lld",&h[i]);
    fs=0;ls=2000000000;
    while(fs<=ls)
    {
        md=(fs+ls)/2;sum=0;
        for(i=1;i<=n;i++)
        {
            sum+=max(0ll,h[i]-md);
        }
        if(sum>=m)
        {
            mc=max(mc,md);
            fs=md+1;
        }
        else
        {
            ls=md-1;
        }
    }
    printf("%lld",mc);
}
