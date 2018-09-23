#include<bits/stdc++.h>
using namespace std;
int cost[135],val[135],type[135],n,m;
map<pair<int,int>,int> jum[135][135];
int dp(int idx,int small,int big,int sze)
{
    if(jum[idx][sze].find({small,big})!=jum[idx][sze].end())
        return jum[idx][sze][{small,big}];
    if(idx==n)
    {
        if(big<=2*(small)+2&&small<=2*big+2)
            return 0;
        return -100000000;
    }
    int mc=0,i;
    mc=max(mc,dp(idx+1,small,big,sze));
    if(type[idx+1]==1&&sze+cost[idx+1]<=m)
        mc=max(mc,dp(idx+1,small+1,big,sze+cost[idx+1])+val[idx+1]);
    if(type[idx+1]==0&&sze+cost[idx+1]<=m)
        mc=max(mc,dp(idx+1,small,big+1,sze+cost[idx+1])+val[idx+1]);
    return jum[idx][sze][{small,big}]=mc;
}
int main()
{
    int i,j,k;
    scanf("%d %d",&m,&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d %d",&cost[i],&val[i],&type[i]);
    }
    int mc=0;
    mc=max(mc,dp(0,0,0,0));
    printf("%d",mc);
}
