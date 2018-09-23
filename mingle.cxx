#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,i,j,k,a,b,c;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lld/%lld",&a,&b);
        c=__gcd(a,b);
        a/=c;b/=c;
        if((b&(b-1))==0)
        {
            if(a>=b/2)
                printf("1\n");
            else
            {
                for(i=1;true;i++)
                {
                    b/=2;
                    if(b<=a)
                    {
                        printf("%lld\n",i);
                        break;
                    }
                }
            }
        }
        else
        {
            printf("NO\n");
        }
    }
}
