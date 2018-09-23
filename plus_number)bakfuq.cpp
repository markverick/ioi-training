#include<bits/stdc++.h>
using namespace std;
int n,m;
char str[1000];
bool notPrime[1200000];
int prime[1200000];
int len=0;
int jum[1200000];
int dp(int idx)
{
    //printf("%d\n",idx);
    if(jum[idx]>=0)
        return jum[idx];
    int i;
    int lo=99999999;
    if(idx==m)
    {
        return jum[idx] = 0;
    }
    else if(idx>m)
    {
        return jum[idx] = 99999999;
    }
    for(i=0;i<len,prime[i]<idx;i++)
    {
        if(idx%prime[i]==0)
        {
            lo=min(dp(idx+prime[i])+1,lo);
        }
    }
    return jum[idx]= lo;
}
int main()
{
    memset(jum,-1,sizeof jum);
    int i,j,k;
    notPrime[1]=1;
    for(i=2;i<=1000000;i++)
    {
        //chk[i]=1;
        if(!notPrime[i])
        {
            for(j=i+i;j<=1000000;j+=i)
            {
                //chk[j]=1;
                notPrime[j]=1;
            }
        }
    }
    int idx=0;
    prime[idx++]=2;
    for(i=2;i<=1000000;i++)
    {
        if(!notPrime[i])
        {
            prime[idx++]=i;
        }
    }
    len=idx;
    scanf("%d %d",&n,&m);
    /*for(i=m-1;i>n;i--)
        dp(i);*/
    if(n<=m)
    {
        int out=dp(n);
        if(out==99999999)
        {
            printf("-1");
        }
        else
        {
            printf("%d",out);
        }
    }
    else
    {
        printf("-1");
    }





}
/*
for(i=1;i<n;i++)
        {
            if(!notPrime[i])
            {
                printf("%d\n",i);
            }
        }

*/
