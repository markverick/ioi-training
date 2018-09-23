#include<bits/stdc++.h>
int jum[2100][2100];
int dp(int idx,int sum)
{
    if(jum[idx][sum]>=0)
        return jum[idx][sum];
    if(sum==0)
        return 1;
    if(sum<0)
        return 0;
    if(idx<0)
        return 0;
    int i;
    int cot=0;
    for(i=idx-1;i>=1;i--)
    {
        if(jum[i][sum-i]>=0)
            cot+=jum[i][sum-i];
        else
            cot+=dp(i,sum-i);
        cot=cot%100999;
    }
    return jum[idx][sum] = cot%100999;
}
int main()
{
    int T,t;
    scanf("%d",&T);
    int i,j,k;
    int n;
    memset(jum,-1,sizeof jum);
    for(t=0;t<T;t++)
    {
        scanf("%d",&n);
        printf("%d\n",dp(n+1,n));
    }
}
