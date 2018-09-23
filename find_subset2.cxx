#include<bits/stdc++.h>
using namespace std;

long long arr[135135];
long long kb[135];
long long tmp[135];
long long Pow(long long a,long long b)
{
    if(b==0)
        return 1;
    long long tmp=Pow(a,b/2);
    tmp*=tmp;
    tmp%=1000000007;
    if(b%2==1)
        tmp*=a;
    return tmp%=1000000007;
}
int main()
{
    int n,i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&arr[i]);
    }
    kb[0]=1;
    for(i=1;i<=n;i++)
    {
        for(j=127;j>=0;j--)
        {
            tmp[j^arr[i]]+=kb[j];
            tmp[j^arr[i]]%=1000000007;
        }
        for(j=127;j>=0;j--)
        {
            kb[j]+=tmp[j];
            kb[j]%=1000000007;
            tmp[j]=0;
        }
    }
    /*for(i=0;i<=127;i++)
    {
        printf("%lld ",kb[i]);
    }*/
    kb[0]--;
    long long pow2inv=Pow(2,1000000005);
    //system("pause");
    long long sum=0;
    for(i=0;i<=127;i++)
    {
        sum+=((kb[i]*(kb[i]-1))%1000000007*pow2inv)%1000000007;
        sum%=1000000007;
    }
    printf("%lld",sum);
}
