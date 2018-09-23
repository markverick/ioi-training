#include<bits/stdc++.h>
using namespace std;
char s1[30],s2[30];
long long a[30],b[30],c;
long long len=0,la,lb;
long long mn;
long long jum[30][200][10];
long long dp(long long idx,long long sum,long long sp,long long v)
{
    if(jum[idx][sum][sp]>=0)
        return jum[idx][sum][sp];
    if(idx==len)
    {
        if(sum==c)
        {
            mn=min(mn,v);
            return 1;
        }
        else
            return 0;
    }
    long long cot=0,i;
    if(sp==0)
    {
        for(i=0;i<=9;i++)
        {
            cot+=dp(idx+1,sum+i,sp,v*10+i);
        }
    }
    else if(sp==1)
    {
        cot+=dp(idx+1,sum+a[idx+1],sp,v*10+a[idx+1]);
        for(i=a[idx+1]+1;i<=9;i++)
        {
            cot+=dp(idx+1,sum+i,0,v*10+i);
        }
    }
    else if(sp==2)
    {
        cot+=dp(idx+1,sum+b[idx+1],sp,v*10+b[idx+1]);
        for(i=b[idx+1]-1;i>=0;i--)
        {
            cot+=dp(idx+1,sum+i,0,v*10+i);
        }
    }
    else
    {
        if(a[idx+1]==b[idx+1])
        {
            cot+=dp(idx+1,sum+a[idx+1],3,v*10+a[idx+1]);
        }
        else
        {
            cot+=dp(idx+1,sum+a[idx+1],1,v*10+a[idx+1]);
            cot+=dp(idx+1,sum+b[idx+1],2,v*10+b[idx+1]);
            for(i=a[idx+1]+1;i<b[idx+1];i++)
            {
                cot+=dp(idx+1,sum+i,0,v*10+i);
            }
        }
    }
    return jum[idx][sum][sp]=cot;
}
int main()
{
    long long i,j,k,idx=0;
    scanf("%s %s %lld",s1+1,s2+1,&c);
    memset(jum,-1,sizeof jum);
    la=strlen(s1+1);
    lb=strlen(s2+1);
    len=lb;
    mn=1000000000000000000;
    for(i=1;i<=la;i++)
    {
        a[i+len-la]=s1[i]-'0';
    }
    for(i=1;i<=lb;i++)
    {
        b[i]=s2[i]-'0';
    }
    long long sum=0;
    if(a[1]==b[1])
    {
        sum+=dp(1,a[1],3,a[1]);
    }
    else
    {
        sum+=dp(1,a[1],1,a[1]);
        sum+=dp(1,b[1],2,b[1]);
        for(i=a[1]+1;i<b[1];i++)
        {
            sum+=dp(1,i,0,i);
        }
    }
    printf("%lld\n%lld",sum,mn);
}
