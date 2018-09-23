#include<bits/stdc++.h>
using namespace std;
long long a[500135];
int main()
{
	long long n,i,j,k,fs,md,ls,hi=0,op,cl,sum,mn;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
        scanf("%lld",&a[i]),hi+=a[i];
    sort(&a[1],&a[n+1]);
    fs=0;ls=hi;mn=hi;
    while(fs<=ls)
    {
        md=(fs+ls)/2;sum=0;cl=n;
        for(i=1;i<=n;i++)
        {
            if(sum+a[i]>md)
                break;
            sum+=a[i];
            cl--;
        }
        if(md+1>=cl)
        {
            mn=min(mn,md);
            ls=md-1;
        }
        else
            fs=md+1;
    }
    printf("%lld",mn);
}
