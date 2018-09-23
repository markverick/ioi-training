#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int t,h,f,maps[2135][2135],dp[2135][2135],m[2135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,T,a,b,mc;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d %d",&t,&h,&f);
        memset(dp,0,sizeof dp);
        memset(maps,0,sizeof maps);
        memset(m,0,sizeof m);
        for(i=1;i<=t;i++)
        {
            scanf("%d",&a);
            for(j=1;j<=a;j++)
                scanf("%d",&b),maps[b][i]++;
        }
        for(i=h+1;i>0;i--)
        {
            for(j=1;j<=t;j++)
                m[i]=max(m[i],dp[i][j]);
            for(j=1;j<=t;j++)
                dp[i-1][j]=max(dp[i-1][j],dp[i][j]+maps[i-1][j]);
            for(j=1;j<=t;j++)
            {
                if(i-f>=0)
                    dp[i-f][j]=max(dp[i-f][j],m[i]+maps[i-f][j]);
            }
        }
        mc=0;
        for(i=1;i<=t;i++)
            mc=max(mc,dp[0][i]);
        printf("%d\n",mc);
    }
    scanf("%*d");
}
