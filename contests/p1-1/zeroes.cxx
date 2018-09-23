#include<bits/stdc++.h>
using namespace std;
vector<int> prime;
int hsh[100135];
int ha[100135];
int primes[100135];
int primeS[100135];
int isPrime[100135];
int main()
{
    int n,i,j,k,a,q,mn=1000000000,cot;
    scanf("%d",&n);
    for(i=2;i<=100000;i++)
    {
        if(hsh[i]==0)
        {
            hsh[i]=1;
            prime.emplace_back(i);
            isPrime[i]=1;
            for(j=i*2;j<=100000;j+=i)
            {
                hsh[j]=1;
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        if(a<2)
            continue;
        j=0;
        while(a>=2)
        {
            while(a>=2&&a%prime[j]==0)
            {
                primes[j]++;
                primeS[prime[j]]++;
                a/=prime[j];
            }
            j++;
//            printf("%d %d\n",prime[j],a);
        }
    }
    scanf("%d",&q);
    for(i=1;i<=q;i++)
    {
        mn=1000000000;j=0;
        scanf("%d",&a);
        if(isPrime[a])
        {
            printf("%d\n",primeS[a]);
            continue;
        }
        while(a>=2)
        {
            if(a%prime[j]==0)
            {
                cot=0;
                while(a>=2&&a%prime[j]==0)
                {
                    cot++;
                    a/=prime[j];
                }
                mn=min(mn,primes[j]/cot);
            }
            j++;
        }
        printf("%d\n",mn);
    }
}
