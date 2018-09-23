#include<bits/stdc++.h>
using namespace std;
int n,m;
int jum[200000];
int dp(int val)
{
    int i,j;
    if(val<0)
        return 0;
    if(jum[val]>=0)
    {
        return jum[val];
    }

    if(val==0)
    {
        return 1;
    }

    int temp=99999999;
    for(i=1;i<=m;i++)
    {
        j=i*i;
        if(dp(val-j)!=0)
            temp = min(temp,dp(val-j));
    }
   // printf("%d\n",temp);
   if(val>=0)
    return jum[val] = temp+1;
}
int main()
{
    int t,i;
    scanf("%d",&t);
    memset(jum,-1,sizeof jum);
    for(i=0;i<t;i++)
    {

        scanf("%d",&n);
        m=floor(sqrt(n));
        printf("%d\n",dp(n)-1);

    }
}
