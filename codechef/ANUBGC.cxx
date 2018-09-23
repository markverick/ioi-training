#include<bits/stdc++.h>
///DONT FORGET CHAR INT 'C' PROBLEM!!!!
using namespace std;
char s[20];
long long len,n;
long long jum[20][12][4];
long long dp(long long idx,long long ban,long long bd)
{
    if(idx>=len)
    {
        return 1;
    }
    long long sum=0,i,j;
    if(bd==1)
    {
        if(s[idx]!=ban)
            sum+=dp(idx+1,ban,1);
        for(i=0;i<s[idx];i++)
            if(i!=ban)
                sum+=dp(idx+1,ban,0);
    }
    else
    {
        sum+=9*dp(idx+1,ban,0);
    }
    return jum[idx][ban][bd]=sum;
}
int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("outom.txt","w",stdout);
    long long i,j,k,T,sum;
    scanf("%lld",&T);
    while(T--)
    {
        memset(jum,-1,sizeof jum);
        memset(s,-1,sizeof s);
        scanf("%s",s);
        sscanf(s,"%lld",&n);
        len=strlen(s);
        for(i=0;i<len;i++)
            s[i]-='0';
        sum=0;
        for(i=0;i<=9;i++)
        {
            for(j=1;j<s[0];j++)
            {
                if(i!=j)
                    sum+=dp(1,i,0);
            }
            if(i!=s[0])
                sum+=dp(1,i,1);
            for(j=1;j<len;j++)
            {
                if(i>=1&&i<=9)
                    sum+=dp(j+1,i,0)*8;
                else
                    sum+=dp(j+1,i,0)*9;
            }
        }
        n*=10;sum=n-sum;
        j=__gcd(n,sum);
        printf("%lld/%lld\n",sum/j,n/j);
    }
}
