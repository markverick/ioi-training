#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int maps[66][66],hsh[7100],C=0,jum[66][66][7100],n;
int dp(int x,int y,int sum)
{
    if(x<0||y<0||maps[x][y]<0)
        return 0;
//    printf("%d %d %d\n",x,y,sum);
    if(x==1&&y==n+1)
    {
//        printf("!\n");
        if(hsh[sum+3000]==0)
        {
//            printf("%d\n",sum);
            hsh[sum+3000]=1;
            C++;
        }
        return 1;
    }
    if(jum[x][y][sum+3000]>=0)
        return jum[x][y][sum+3000];
    int i,mc=0;
    if(x%2)
    {
        mc=max(mc,dp(x-1,y,sum+maps[x-1][y]));
        mc=max(mc,dp(x-1,y-1,sum+maps[x-1][y-1]));
        mc=max(mc,dp(x-1,y,sum-maps[x-1][y]));
        mc=max(mc,dp(x-1,y-1,sum-maps[x-1][y-1]));
    }
    else
    {
        mc=max(mc,dp(x-1,y,sum+maps[x-1][y]));
        mc=max(mc,dp(x-1,y+1,sum+maps[x-1][y+1]));
        mc=max(mc,dp(x-1,y,sum-maps[x-1][y]));
        mc=max(mc,dp(x-1,y+1,sum-maps[x-1][y+1]));
    }
    return jum[x][y][sum+3000]=mc;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,mn=0;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)return 0;
        C=0;
        memset(maps,-1,sizeof maps);
        memset(hsh,0,sizeof hsh);
        memset(jum,-1,sizeof jum);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=i;j++)
            {
                scanf("%d",&maps[i][n-i/2+j]);
                maps[i][n-i/2+j]=abs(maps[i][n-i/2+j]);
            }
        }
        for(i=n-1;i>=1;i--)
        {
            for(j=1;j<=i;j++)
            {
                scanf("%d",&maps[n*2-i][n-i/2+j]);
                maps[n*2-i][n-i/2+j]=abs(maps[n*2-i][n-i/2+j]);
            }
        }
//        for(i=1;i<=n*2;i++)
//        {
//            for(j=1;j<=n*2;j++)
//            {
//                printf("%2d ",maps[i][j]);
//            }
//            printf("\n");
//        }
//        printf("!%d\n",maps[n*2-1][n+1]);
        dp(n*2-1,n+1,-maps[n*2-1][n+1]);
        dp(n*2-1,n+1,maps[n*2-1][n+1]);
        mn=MI;
        for(i=0;i<=6000;i++)
        {
            if(hsh[i])
                mn=min(mn,abs(3000-i));
        }
        printf("%d\n",mn);
    }
}
