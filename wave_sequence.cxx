#include<bits/stdc++.h>
using namespace std;
int a[100135];
int ft[3][100135];
//int dp[100135][4];
void add0(int idx,int val)
{
    while(idx<=100000)
    {
        ft[0][idx]+=val;
        ft[0][idx]%=1000000007;
        idx+=idx&-idx;
    }
}
int sum0(int idx)
{
    int sm=0;
    while(idx>0)
    {
        sm+=ft[0][idx];
        sm%=1000000007;
        idx-=idx&-idx;
    }
    return sm;
}
void add1(int idx,int val)
{
    while(idx<=100000)
    {
        ft[1][idx]+=val;
        ft[1][idx]%=1000000007;
        idx+=idx&-idx;
    }
}
int sum1(int idx)
{
    int sm=0;
    while(idx>0)
    {
        sm+=ft[1][idx];
        sm%=1000000007;
        idx-=idx&-idx;
    }
    return sm;
}
int main()
{
    int n,i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
//    dp[0][0]=0;
//    dp[0][1]=0;
    int sum=0,tmp;
    for(i=1;i<=n;i++)
    {
//        dp[i][0]=sum1(a[i])+1;
        tmp=sum1(a[i]-1)+1;
        add0(a[i],tmp);
        sum+=tmp;sum%=1000000007;
//        dp[i][1]=sum0(100000)-sum0(a[i])+1;

        tmp=sum0(100000)-sum0(a[i])+1;
        if(tmp<0)
            tmp+=1000000007;
        tmp%=1000000007;
        add1(a[i],tmp);
        sum+=tmp;sum%=1000000007;
    }
    sum-=n*2;
    if(sum<0)
        sum+=1000000007;
    sum%=1000000007;
    printf("%d\n",sum);
}
