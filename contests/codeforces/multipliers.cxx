#include<bits/stdc++.h>
using namespace std;
long long a[200135];
long long hsh[200135];
long long poww(long long b,long long p)
{
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
    long long n,i,j,prod=1,sum=1;
    scanf("%I64d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%I64d",&a[i]);
        prod*=a[i];
        prod%=1000000007;
        hsh[a[i]]++;
    }
    sum=prod;
    long long f=0,k=0;
    for(i=2;i<=200000;i++)
    {
        if(f==0&&hsh[i]!=0)
        {
            if((hsh[i]+1)%2==0)
            {
                sum=poww(sum,(hsh[i]+1)/2);
                f=2;
            }
            else
            {
                sum=poww(sum,(hsh[i]+1)/2);
                f=1;
            }
            sum%=1000000007;
        }
        else
        {
            sum=poww(sum,hsh[i]+1);
            sum%=1000000007;
        }
    }
    if(f==1)
    {
        sum*=prod;
        sum%=1000000007;
    }
    printf("%I64d",sum);
}
