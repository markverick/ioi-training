#include<bits/stdc++.h>
using namespace std;
long long n,m;
int main()
{
    long long i,j,k,hi=0,b,p=0,q=0;
    while(scanf("%lld",&n)!=EOF)
    {
        p=0;q=0;
        b=n;m=0;
        while(b>0)
        {
            m=m*10+(b%10);
            b/=10;
        }
        for(i=2;i<=sqrt(n);i++)
        {
            if(n%i==0)
                p=1;
        }
        for(i=2;i<=sqrt(m);i++)
        {
            if(m%i==0)
                q=1;
        }
        if(n!=1)
        {
            if(p==0)
            {
                if(q==0)
                {
                    printf("%d is emirp.\n",n);
                }
                else
                {
                    printf("%d is prime.\n",n);
                }
            }
            else
            {
                printf("%d is not prime.\n",n);
            }
        }
        else
        {
            printf("1 is not prime\n");
        }

    }
}
/*
for(i=1;i<n;i++)
        {
            if(!notPrime[i])
            {
                printf("%d\n",i);
            }
        }

*/
