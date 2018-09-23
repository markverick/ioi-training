#include<bits/stdc++.h>
using namespace std;
long long n,i,j,k;
char str[135];
long long a[25];
long long b[25];
long long totalG;
long long totalL;
int main()
{
    scanf("%lld",&n);

    for(i=1;i<=n;i++)
    {
        scanf("%s",str);
        sscanf(str,"%lld/%lld",&a[i],&b[i]);
    }
    totalL=b[1];
    for(i=2;i<=n;i++)
    {
        totalL=(b[i]*totalL)/__gcd(b[i],totalL);
    }
    long long sum=0;
    for(i=1;i<=n;i++)
    {
        sum+=(totalL/b[i])*a[i];
    }
    printf("%lld\n",(sum-1)/totalL+1);
    if(totalL-sum%totalL!=totalL)
        printf("%lld/%lld",totalL-sum%totalL,totalL);
    else
        printf("0");
}
