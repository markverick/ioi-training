#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
vector<long long> primes;
long long hsh[4135],L;
long long A[4135],B[4135],C[4135];
vector<long long> v;
long long inex(long long idx,long long cot,long long prod)
{
    if(cot==0)
        return L/prod;
    long long sum=0;
    if(v.size()-idx>cot)
        sum+=inex(idx+1,cot,prod);
    sum+=inex(idx+1,cot-1,prod*v[idx]);
    return sum;
}
int main()
{
	long long a,b,i,j,k,H,sum=0;
    scanf("%lld %lld %lld",&a,&b,&L);
    H=a+b;
	for(i=2;i<=H+1;i++)
    {
        if(!hsh[i])
        {
            primes.emplace_back(i);
            for(j=i;j<=H+1;j+=i)
                hsh[j]=1;
        }
    }
    for(i=0;i<=H;i++)
    {
        k=i;
        v.clear();
        for(j=0;j<primes.size();j++)
        {
            if(k<=1)break;
            if(k%primes[j]==0)
                v.emplace_back(primes[j]);
            while(k%primes[j]==0)
                k/=primes[j];
        }
        sum=L;
        for(j=1;j<=v.size();j++)
        {
            if(j%2)
                sum-=inex(0,j,1);
            else
                sum+=inex(0,j,1);
        }
        A[i]=sum;
        B[H-i]=sum;
        if(i==0)
            A[i]=1;
        if(i==H)
            B[H]=1;
        k=H-i;
        for(j=0;j<primes.size();j++)
        {
            if(k<=1)break;
            if(k%primes[j]==0)
                v.emplace_back(primes[j]);
            while(k%primes[j]==0)
                k/=primes[j];
        }
        sort(v.begin(),v.end());
        auto it=unique(v.begin(),v.end());
        v.resize(distance(v.begin(),it));
        sum=L;
        for(j=1;j<=v.size();j++)
        {
            if(j%2)
                sum-=inex(0,j,1);
            else
                sum+=inex(0,j,1);
        }
        C[i]=sum;
        if(i==0||i==H)
            C[i]=1;
    }
    long long x=0,y=0,z=0;
    for(i=0;i<=H;i++)
    {
        x+=C[i];
        y+=A[i]+B[i]-C[i]*2;
        z+=L-A[i]-B[i]+C[i];
    }
    printf("%lld\n%lld\n%lld",z,y,x);
}
