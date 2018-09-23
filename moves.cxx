#include<bits/stdc++.h>
using namespace std;
long long ncr[5005][5005];
int main()
{
     long long n,k,i,j;
    for(i=0;i<=5000;i++)
        ncr[0][i]=1,ncr[i][0]=1;
    for(i=1;i<=5000;i++)
        for(j=1;j<=5000-i+1;j++)
            ncr[i][j]=(ncr[i-1][j]+ncr[i][j-1])%1000000007;
    while(scanf("%lld %lld",&n,&k)!=EOF)
    {
        if(n==0&&k==0)
            return 0;
        if(k%2==1)
            printf("%lld\n",(2*ncr[n-2-k/2][k/2]*ncr[n-2-k/2][k/2])%1000000007);
        else
            printf("%lld\n",(2*ncr[n-2-k/2][k/2]*ncr[n-2-k/2+1][k/2-1])%1000000007);
    }
}
