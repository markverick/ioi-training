#include<bits/stdc++.h>
using namespace std;
int n,m;
int jum[135][135][5];
int dp(int idx,int custom,int type)
{
    if(jum[idx][custom][type]>=0)
        return jum[idx][custom][type];
    if(idx>=n)
    {
        if(type==0&&idx==n)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int sum=0;
    if(type==0)
    {
        sum+=dp(idx+1,custom,0);
        sum+=dp(idx+2,custom,0);
        sum%=9241;
        if(custom>0)
        {
            sum+=dp(idx+2,custom-1,0);
            sum+=dp(idx+1,custom-1,1);
            sum+=dp(idx+1,custom-1,2);
        }
        sum%=9241;
    }
    else if(type==1)
    {
        sum+=dp(idx+1,custom,2);
        sum%=9241;
        if(custom>0)
        {
            sum+=dp(idx+2,custom-1,0);
            sum%=9241;
        }
    }
    else if(type==2)
    {
        sum+=dp(idx+1,custom,1);
        sum%=9241;
        if(custom>0)
        {
            sum+=dp(idx+2,custom-1,0);
            sum%=9241;
        }
    }
    return jum[idx][custom][type]=sum%9241;
}
int main()
{
    int T,i;
    scanf("%d",&T);
    while(T--)
    {
        memset(jum,-1,sizeof jum);
        scanf("%d %d",&n,&m);
        printf("%d\n",dp(0,m,0));
    }
}
