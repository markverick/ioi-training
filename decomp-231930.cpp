#include<bits/stdc++.h>
int in;
int result[24000];
int jum[2400][2400];
int dp(int idx,int sum)
{
    if(jum[idx][sum]>=0)
        return jum[idx][sum];
    int i,j,k;
    if(sum==in)
    {
        return 1;
    }
    else if(sum>in)
        return 0;
    int cot=0;
    for(i=result[idx-1]+1;i<=in-sum;i++)
    {
        result[idx]=i;
        cot+=dp(idx+1,sum+i);
        cot=cot%100999;
    }
    return jum[idx][sum] = cot%100999;
}
int main()
{
    int T,t,i,j,k;
    scanf("%d",&T);

    for(t=0;t<T;t++)
    {
        memset(jum,-1,sizeof jum);
        memset(result,0,sizeof result);
        scanf("%d",&in);
        printf("%d\n",dp(1,0));
    }
}
