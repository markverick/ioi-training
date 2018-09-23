#include<bits/stdc++.h>
using namespace std;
int n;
int v[7];
int jum[1200000][6];
int dp(int idx,int coin)
{
    if(jum[idx][coin]>=0)
        return jum[idx][coin];
    if(idx==0)
    {
        return 1;
    }
    int sum=0;
    int i;
    for(i=coin;i>=1;i--)
    {
        if(idx-v[i]>=0)
        {
            sum+=dp(idx-v[i],i);
        }
    }
    return jum[idx][coin]=sum;
}
int main()
{
    memset(jum,-1,sizeof jum);
    int T;
    v[1]=1;v[2]=2;v[3]=5;v[4]=10;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        printf("%d\n",dp(n,4));
    }

}
