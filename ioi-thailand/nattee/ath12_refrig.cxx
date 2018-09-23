#include<bits/stdc++.h>
#define MI 1000000000000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
long long a[222];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	long long T,i,j,k,n,fs,md,ls,sum,mc=0;
	scanf("%lld",&T);
	while(T--)
    {
        sum=0;mc=0;
        scanf("%lld",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
            a[i]--;
        }
        fs=0;ls=MI;
        while(fs<=ls)
        {
            md=(fs+ls)/2;
            sum=0;
//            printf("%lld <- %lld -> %lld\n",fs,md,ls);
            for(i=1;i<=n;i++)
            {
                if(a[i]<md)
                {
                    sum+=md-a[i];
                }
                if(sum>md)
                    break;
            }
            if(sum<=md)
            {
                mc=max(mc,md);
                fs=md+1;
            }
            else
                ls=md-1;
        }
        printf("%lld\n",mc+1);
    }
}
