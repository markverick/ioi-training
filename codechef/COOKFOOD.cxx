#include<bits/stdc++.h>
#define M 1000000007
using namespace std;
long long Pow(long long b,long long p)
{
    if(p==0)
        return 1;
    long long tmp=Pow(b,p/2);
    tmp*=tmp;tmp%=M;
    if(p%2)
        tmp*=b;
    return tmp%M;
}

int main()
{
    long long T,n,i,j,k;
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld %lld",&n,&k);
        printf("%lld\n",((k*(k-1))%M)*Pow(((k-1)+(k-2)*(k-2)%M)%M,n-1)%M);
    }
}
