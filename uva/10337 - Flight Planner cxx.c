#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int maps[12][1135],jum[12][1135];
int dp(int idx,int al)
{
    if(jum[idx][al]>=0)
        return jum[idx][al];
    if(idx==n+1)
    {
        return 0;
    }
    int mn=0;
    mn=min(mn,dp(idx+1,al)+30+maps[idx][al]);
    if(al>0)
        mn=min(mn,dp(idx+1,al)+20+maps[idx][al]);
    if(al<9)
        mn=min(mn,dp(idx+1,al)+60+maps[idx][al]);
    return mn;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,T,i,j,k;
	scanf("%d",&T);
	while(T--)
    {
        memset(jum,-1,sizeof jum);
        scanf("%d",&n);
        n/=100;
        for(i=0;i<=9;i++)
        {
            for(j=1;j<=n;j++)
                scanf("%d",&maps[i][j]);
        }
        printf("%d",dp(1,0));
    }
}
