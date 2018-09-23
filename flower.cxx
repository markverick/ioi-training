#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
using namespace std;
int m,n;
int cost[135],beauty[135],type[135];
map<pair<int,int>,int> jum[105][105];
int dp(int idx,int small,int big,int money)
{
    if(jum[idx][money].find(MP(small,big))!=jum[idx][money].end())
        return jum[idx][money][MP(small,big)];
    if(idx==n)
    {
        if(big>=small&&small>=(big-1)/2)
            return 0;
        if(small>big&&big>=(small-1)/2)
            return 0;
        return -1000000000;
    }
    int mc=0,tmp=0,i;
    for(i=idx+1;i<=n;i++)
    {
        if(money+cost[i]>m)
            continue;
        if(type[i]==0)
            mc=max(mc,dp(i,small+1,big,money+cost[i])+beauty[i]);
        else
            mc=max(mc,dp(i,small,big+1,money+cost[i])+beauty[i]);
    }
    return jum[idx][money][MP(small,big)]=mc;
}
int main()
{
    int i,j,k;
    scanf("%d %d",&m,&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d %d",&cost[i],&beauty[i],&type[i]);
    }
    int mc=0;
    for(i=1;i<=n;i++)
    {
        if(type[i]==0)
            mc=max(mc,dp(i,1,0,cost[i])+beauty[i]);
        else
            mc=max(mc,dp(i,0,1,cost[i])+beauty[i]);
    }
    printf("%d",mc);
}
