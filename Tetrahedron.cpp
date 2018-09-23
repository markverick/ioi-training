#include<bits/stdc++.h>
using namespace std;
long long n;
long long jum[12000000][5];
long long dp(long long idx,int pos)
{
    //cout << idx <<"\n";
    if(jum[idx][pos]>=0)
        return jum[idx][pos];
    if(idx<=0)
    {
        if(pos==0)
            return 1;
        else
            return 0;
    }
    int i,j;
    long long sum=0;
    for(i=0;i<4;i++)
    {
        if(pos==i)
            continue;
        sum+=dp(idx-1,i);
        sum%=1000000007;
    }

   // printf("%d\n",sum);
    return jum[idx][pos]=sum;
}
int main()
{
    int i;
    memset(jum,-1,sizeof jum);
    /*for(i=0;i<10000000;i++)
    {
        n=i;
        dp(0,0);
    }*/
    scanf("%lld",&n);

    printf("%lld",dp(n,0)%1000000007);
}
