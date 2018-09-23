#include<bits/stdc++.h>
using namespace std;
long long n,m;
char str[1000];
bool notPrime[1200000];
long long prime[1200000];
int len=0;
int main()
{
    long long i,j,k,hi=0,b,p,q;
    notPrime[1]=1;
    for(i=2;i<=1000000;i++)
    {
        //chk[i]=1;
        if(!notPrime[i])
        {
            for(j=i+i;j<=1000000;j+=i)
            {
                //chk[j]=1;
                notPrime[j]=1;
            }
        }
    }
    int idx=0;
    prime[idx++]=2;
    for(i=2;i<=1000000;i++)
    {
        if(!notPrime[i])
        {
            prime[idx++]=i;
        }
    }
    len=idx;
    //printf("%d",!notPrime[18]);
    while(scanf("%lld",&n)!=EOF)
    {
        p=0;q=0;
        b=n;m=0;
        while(b>0)
        {
            m=m*10+(b%10);
            b/=10;
        }
        if(n==m)
        {
            m=4;
        }
        if(n<1000000)
        {
            if(n<1000000&&!notPrime[n])
                p=1;
        }
        else
        {
            p=1;
            for(i=0;i<len;i++)
            {
                if(n%prime[i]==0)
                {
                    p=0;
                }
            }
        }
        if(m<1000000)
        {
            if(m<1000000&&!notPrime[m])
                q=1;
        }
        else
        {
            q=1;
            for(i=0;i<len;i++)
            {
                if(m%prime[i]==0)
                {
                    q=0;
                }
            }
        }

        if(n!=1)
        {
            if(p==1)
            {
                if(q==1)
                {
                    printf("%lld is emirp.\n",n);
                }
                else
                {
                    printf("%lld is prime.\n",n);
                }
            }
            else
            {
                printf("%lld is not prime.\n",n);
            }
        }
        else
        {
            printf("1 is not prime.\n");
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
