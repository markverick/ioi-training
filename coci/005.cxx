#include<bits/stdc++.h>
using namespace std;
int n;
double jum[1050005],adj[22][22];
double dp(int idx,int bit)
{
    if(__builtin_popcount(bit)==n)
    {
        return 1.0;
    }
    if(jum[bit]<=101)
        return jum[bit];
    double mc=0;
    int i;
    for(i=0;i<n;i++)
    {
        if((bit|(1<<i))==bit)
            continue;
        mc=max(mc,dp(idx+1,bit|(1<<i))*adj[idx][i]);
    }
    return jum[bit]=mc;
}
int main()
{
    int i,j,k;
    for(j=0;j<=1050000;j++)
        jum[j]=105;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%lf",&adj[i][j]),adj[i][j]/=100;
    printf("%f",dp(0,0)*100);
}
