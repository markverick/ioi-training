#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
long long hsh[23];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	long long n,i,j,k,a;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
    {
        scanf("%lld",&a);
        for(j=0;j<=20;j++)
        {
            if((1<<j)&a)
                hsh[j]++;
        }
    }
    long long sum=0;
    for(j=0;j<=20;j++)
    {
        sum+=hsh[j]*(n-hsh[j])*(1<<j);
//        printf("%lld %lld\n",hsh[j],n-hsh[j]);
    }
    printf("%lld",sum);
}
