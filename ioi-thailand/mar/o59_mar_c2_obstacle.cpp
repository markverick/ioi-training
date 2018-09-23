#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define EB emplace_back;
using namespace std;
int n,s;
int h[2135];
int maps[2005][2005],qs[2005][2005];
map<pair<int,int>,int > jum;
int dp(int idx,int energy)
{
    if(idx==n+1||energy<-1)
    {
        return 0;
    }
    if(jum.find(MP(idx,energy))!=jum.end())
        return jum[MP(idx,energy)];
    int mc=0,i,j;
    mc=max(mc,dp(idx+1,energy-1));
    for(i=1;i<=h[idx];i++)
    {
        if(energy-i>=0)
            mc=max(mc,dp(idx+1,energy-i-1)+qs[idx][i]);
    }
    return jum[MP(idx,energy)]=mc;
}
int main()
{
    int i,j,k,a;
    scanf("%d %d",&n,&s);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&h[i]);
        for(j=1;j<=h[i];j++)
        {
            scanf("%d",&maps[i][j]);
            qs[i][j]=qs[i][j-1]+maps[i][j];
        }
    }
    printf("%d\n",dp(1,s));
}
