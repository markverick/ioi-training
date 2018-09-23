#include<bits/stdc++.h>
using namespace std;
int a,b;
int maps[12000];
int jum[12000][300];
int mod(int fu,int ck)
{
    return ((fu%ck+ck)%ck);
}
bool dp(int idx,int sum)
{
    if(idx<0)
    {//printf("%d\n",sum);
        if(mod(sum,b)==0)
        {

            return 1;
        }
        else
            return 0;
    }
    if(jum[idx][sum]!=-1)
        return jum[idx][sum];
    if(idx!=0)
        return jum[idx][sum] = max(dp(idx-1,mod(sum+maps[idx],b)),dp(idx-1,mod(sum-maps[idx],b)));
    else
        return jum[idx][sum] = dp(idx-1,mod(sum-maps[idx],b));
}
int main()
{
    int t,i,j,k;
    //printf("%d\n",mod(-22,7));
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        memset(maps,0,sizeof maps);
        memset(jum,-1,sizeof jum);
        scanf("%d %d",&a,&b);
        for(j=0;j<a;j++)
        {
            scanf("%d",&maps[j]);
            maps[j]=mod(maps[j],b);
        }
        printf("%d\n",dp(a-1,b));
    }
}
