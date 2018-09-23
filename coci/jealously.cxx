#include<bits/stdc++.h>
#define MI 1000000000
using namespace std;
long long a[300135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	long long n,m,i,j,k,fs=0,md,ls=MI,sum,mn=MI;
	scanf("%lld %lld",&n,&m);
	for(i=1;i<=m;i++)
        scanf("%lld",&a[i]);
    while(fs<=ls)
    {
        md=(fs+ls)/2;sum=0;
        for(i=1;i<=m;i++)
        {
            sum+=a[i]/md;
            if(a[i]%md)
                sum++;
        }
        if(sum<=n)
        {
            mn=min(mn,md);
            ls=md-1;
        }
        else
            fs=md+1;
    }
    printf("%lld",mn);
}
