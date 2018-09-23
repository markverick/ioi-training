#include<bits/stdc++.h>
using namespace std;
int jum[1135];
int dp(int idx)
{
    if(jum[idx]>=0)
        return jum[idx];
    if(idx==1)
        return 1;
    if(idx==0)
        return 1;
    int sum=0,i;
    for(i=0;i<idx;i++)
    {
        sum+=dp(i)*dp(idx-i-1);
        sum%=10001;
    }
    return jum[idx]=sum;
}
int main()
{
    int n,sum,i;
    memset(jum,-1,sizeof jum);
    scanf("%d",&n);
    printf("%d",dp(n));
}
