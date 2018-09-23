#include<bits/stdc++.h>
#define MI 1000000000000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
long long a[100135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	long long i,j,k,n,m,fs=0,md,ls=MI,sum,mn=MI;
	scanf("%lld %lld",&n,&m);
	for(i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    while(fs<=ls)
    {
        md=(fs+ls)/2;
        sum=0;
        for(i=1;i<=n;i++)
        {
            sum+=md/a[i];
            if(sum>=m)
                break;
        }
        if(sum>=m)
        {
            mn=min(mn,md);
            ls=md-1;
        }
        else
            fs=md+1;
    }
    printf("%lld",mn);
}
