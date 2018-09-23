#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define X first
#define Y second
using namespace std;

int main()
{
    int T,i,j,k;
    scanf("%d",&T);
    while(T--)
    {
        long long n,m;
        scanf("%lld %lld",&n,&m);
        long long deg=1;
        long long x=m;
        if(m==1)
        {
            printf("%lld\n",n);
            continue;
        }
        if(m>10000000||m*m>n)
        {
            printf("%lld\n",n/m+n%m);
            continue;
        }
        while(x<=n)
        {
            deg=x;
            x*=m;
        }
        //printf("%lld\n",deg);
        long long sum=0;
        for(1;deg>1;deg/=m)
        {
            while(n-deg>=0)
            {
                //printf("%lld\n",n);
                sum++;
                n-=deg;
            }
        }
        if(deg==1)
            sum+=n;
        printf("%lld\n",sum);
    }
}

