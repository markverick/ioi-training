#include<bits/stdc++.h>
using namespace std;
int x[22],y[22];
int dist[22][22];
int fin=0;
int n;
int dp(int idx,int bit)
{
    //printf("%d %d\n",idx,bit);
    //printf("%d %d\n",bit,fin);
    if(jum[idx][bit]>=0)
        return jum[idx][bit];
    if(bit==fin)
    {
        return dist[idx][0];
    }
    int i,j,k;
    int tmp=bit;
    int mn=1000000000;
    for(i=1;i<=n;i++)
    {
        if((tmp|(1<<(i-1)))!=tmp)
        {
            mn=min(mn,dp(i,tmp| (1<<(i-1)) )+dist[idx][i]);
        }
    }
    return jum[idx][bit]=mn;
}
int main()
{
    int sx,sy;
    scanf("%d %d",&sx,&sy);
    x[0]=sx;
    y[0]=sy;
    int i,j,k;
    scanf("%d",&n);
    memset(jum,-1,sizeof jum);
    fin=(1<<(n))-1;
    //printf("%d\n",fin);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&x[i],&y[i]);
    }
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            dist[i][j]=abs(x[i]-x[j])+abs(y[i]-y[j]);
            dist[j][i]=dist[i][j];
        }
    }
    printf("%d",dp(0,0));
}
