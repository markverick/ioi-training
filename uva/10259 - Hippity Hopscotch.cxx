#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int maps[111][111],jum[111][111],n,w;
int dp(int x,int y)
{
    if(jum[x][y]>=0)
        return jum[x][y];
    int i,mc=0;
    for(i=max(1,x-w);i<=min(n,x+w);i++)
    {
        if(i==x)continue;
        if(maps[i][y]>maps[x][y])
            mc=max(mc,dp(i,y)+maps[i][y]);
    }
    for(i=max(1,y-w);i<=min(n,y+w);i++)
    {
        if(i==y)continue;
        if(maps[x][i]>maps[x][y])
            mc=max(mc,dp(x,i)+maps[x][i]);
    }
    return jum[x][y]=mc;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int T,i,j,k;
	scanf("%d",&T);
	while(T--)
    {
        memset(jum,-1,sizeof jum);
        scanf("%d %d",&n,&w);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                scanf("%d",&maps[i][j]);
            }
        }
        printf("%d\n",dp(1,1)+maps[1][1]);
        if(T)
            printf("\n");
    }
}
