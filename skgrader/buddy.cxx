#include<bits/stdc++.h>
using namespace std;
char s[24];
long long hsh[2135],h[12],inex[2135];
void dfs(long long idx,long long bit,long long amp)
{
    if(idx==11)
    {
        inex[bit]+=amp;
        return;
    }
    if(h[idx]==1)
        dfs(idx+1,bit*2+1,amp);
    dfs(idx+1,bit*2,amp);
}
long long Sum(long long num,long long idx,long long bit)
{
    if(num<0)
        return 0;
    if(idx==11)
    {
        if(num==0)
            return inex[bit]*(inex[bit]-1)/2;
        return 0;
    }
    return Sum(num-1,idx+1,bit*2+1)+Sum(num,idx+1,bit*2);
}
int main()
{
	long long n,i,j,k,sum=0;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
    {
        scanf("%s",s);
        memset(h,0,sizeof h);
        for(j=0;s[j];j++)
            h[s[j]-'0']=1;
        k=0;
        for(j=0;j<=9;j++)
            k=k*2+h[j];
        hsh[k]++;
    }
    for(i=0;i<1024;i++)
    {
        if(hsh[i])
        {
            memset(h,0,sizeof h);
            k=i;j=9;
            while(k>0)
            {
                h[j--]=k%2;
                k/=2;
            }
            dfs(0,0,hsh[i]);
        }
    }
    long long x;
    for(i=1;i<=10;i++)
    {
        x=Sum(i,0,0);
        if(i%2)
            sum+=x;
        else
            sum-=x;
    }
    printf("%lld",sum);
}
