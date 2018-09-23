#include<bits/stdc++.h>
///DONT FORGET CHAR INT 'C' PROBLEM!!!!
using namespace std;
char s[20];
int len,n;
int dp(int idx,int ban,int bd)
{
    if(idx>=len)
    {
        return 1;
    }
    int sum=0,i,j;
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
    return sum;
}
int main()
{
    int i,j,k,T,sum;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",s);
        sscanf(s,"%d",&n);
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
                for(k=1;k<=9;k++)
                {
                    if(k==i)continue;
                    sum+=dp(j+1,i,0);
                }
            }
        }
        n*=10;sum=n-sum;
        j=__gcd(n,sum);
        printf("%d/%d\n",sum/j,n/j);
    }
}
