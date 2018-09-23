#include<bits/stdc++.h>
#define PB push_back
using namespace std;
vector<int> adj[42000];
int a,b,c,n,m;
int cX[42000];
int cY[42000];
int cZ[42000];
int dp(int x,int y,char isRide)
{
    int i,j,k;
    int mn=999999999;
    printf("%d %d %d\n",x,y,isRide);
    //system("pause");
    if(x==n&&y==n)
    {
        return 0;
    }
    else if(x==n)
    {
        for(i=0;i<adj[y].size();i++)
        {
            if(cY[adj[y][i]]==1)
                continue;
                cY[adj[y][i]]==1;
                //printf("=%d\n",adj[y][i]);
                mn=min(mn,dp(x,adj[y][i],isRide)+b);
                cY[adj[y][i]]==0;
            //mn=min(mn,dp(x,adj[y][i],isRide));
        }
        return mn;
    }
    else if(y==n)
    {
        for(i=0;i<adj[x].size();i++)
        {
            if(cX[adj[x][i]]==1)
                continue;
                cX[adj[x][i]]==1;
                //printf("=%d\n",adj[x][i]);
                mn=min(mn,dp(adj[x][i],y,isRide)+a);
                cX[adj[x][i]]==0;
        }
        return mn;
    }
    if(!isRide)
    for(i=0;i<adj[x].size();i++)
    {
        for(j=0;j<adj[y].size();j++)
        {
            if(cX[adj[x][i]]==0&&cY[adj[y][j]]==0){
                cX[adj[x][i]]=1;cY[adj[y][j]]=1;
                mn=min(mn, dp(adj[x][i],adj[y][j],0)+a+b );
                cX[adj[x][i]]=0;cY[adj[y][j]]=0;
            }
            else if(cX[adj[x][i]]==1&&cY[adj[y][j]]==0){
                cY[adj[y][j]]=1;
                mn=min(mn, dp(x,adj[y][j],0)+b );
                cY[adj[y][j]]=0;
            }
            else if(cY[adj[y][j]]==1&&cX[adj[x][i]]==0){
                cX[adj[x][i]]=1;
                mn=min(mn, dp(adj[x][i],y,0)+a );
                cX[adj[x][i]]=0;
            }
            if(adj[x][i]==adj[y][j])
            {
                cZ[adj[x][i]]=1;
                mn=min(mn,dp(adj[x][i],adj[y][j],1)+c);
                cZ[adj[x][i]]=0;
            }

        }
    }
    else
    {
        for(i=0;i<adj[x].size();i++)
        {
            if(cZ[adj[x][i]]==0){
                cZ[adj[x][i]]=1;
                mn=min(mn,dp(adj[x][i],adj[x][i],1)+c);
                cZ[adj[x][i]]=0;
            }
        }
    }
    if(mn==21)
    {
        printf("==%d %d %d",x,y,isRide);
        system("pause");
    }
    return mn;
}
int main()
{
    scanf("%d %d %d %d %d",&a,&b,&c,&n,&m);
    int i,j,k;
    for(i=1;i<=m;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        adj[a].PB(b);
        adj[b].PB(a);

    }
    cX[1]=1;
    cY[2]=1;
    printf("%d",dp(1,2,0));
}
