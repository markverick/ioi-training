#include<bits/stdc++.h>
using namespace std;
long long a=1;
long long cat[1000005];
long long poww(long long b,long long p)
{
   // printf("%lld %lld\n",b,p);
    if(p==0)
        return 1;
    long long temp=poww(b,p/2);
    temp*=temp;
    temp%=1000000007;
    if(p%2)temp*=b;
    temp%=1000000007;
    return temp;
}
int main()
{
    int T,i,j,k;
    long long n;
    scanf("%d",&T);
    cat[1]=1;
    for(i=2;i<=1000000;i++)
    {
        cat[i]=( ( (cat[i-1]*(2*i) )%1000000007)*(2*i-1) )%1000000007;
        a=i*(i+1);a%=1000000007;
        //printf("%lld\n",a);
        cat[i]*=poww(a,1000000005);
        //printf("%lld\n",poww(a,1000000005));
        cat[i]%=1000000007;
        //printf("%lld\n",cat[i]);
        //system("pause");
    }
    while(T--)
    {
        scanf("%lld",&n);
        printf("%lld\n",(cat[n-1]*2)%1000000007 );
    }
}
