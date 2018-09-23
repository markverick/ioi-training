#include<bits/stdc++.h>
#define MI 1000000000000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
long long a[500135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	long long n,m,fs,md,ls,sum=0,i,j,k,mn=MI;
	scanf("%lld %lld",&n,&m);
	for(i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    fs=0;ls=MI;
    while(fs<=ls)
    {
        md=(fs+ls)/2;
        sum=0;
//        printf("%lld <- %lld -> %lld\n",fs,md,ls);
        for(i=1;i<=n;i++)
        {
            sum+=(a[i]-1)/md+1;
        }
//        printf("%lld\n",sum);
        if(sum<=m)
        {
            mn=min(mn,md);
            ls=md-1;
        }
        else
            fs=md+1;
    }
    printf("%lld",mn);
}
