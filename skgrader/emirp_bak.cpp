#include<bits/stdc++.h>
using namespace std;
long long n,m;
char str[1000];
map<long long,bool> notPrime;//1 trillion ley ro wa
map<long long,bool> chk;
int main()
{
    long long i,j,k,hi=0,b;
    notPrime[1]=1;
    while(scanf("%lld",&n)!=EOF)
    {
        b=n;m=0;
        while(b>0)
        {
            m=m*10+(b%10);
            b/=10;
        }
        //printf("%lld %lld\n",n,m);
        if(max(n,m)>hi)
        {

            hi=max(n,m);//printf("==%d==",hi);
            for(i=2;i<=sqrt(hi);i++)
            {
                //chk[i]=1;
                if(!notPrime[i])
                {
                    for(j=i+i;j<=hi;j+=i)
                    {
                        //chk[j]=1;
                        notPrime[j]=1;
                    }
                }
            }
        }



        if(!notPrime[n])
        {
            if(!notPrime[m])
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
