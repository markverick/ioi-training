#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
queue<pair<int,int> > q[13];
bitset<5005> maps[5005];
int dx[6]={1,-1,0,0};
int dy[6]={0,0,1,-1};
int sum[13];
int r,c,n;
int main()
{
    int i,j,k,a,b,x,y,sz;
    scanf("%d %d %d",&r,&c,&n);

    for(i=0;i<=r+1;i++)
        for(j=0;j<=c+1;j++)
            maps[i][j]=1;
    for(i=1;i<=r;i++)
        for(j=1;j<=c;j++)
            maps[i][j]=0;
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&a,&b);
        q[i].emplace(a,b);
        maps[a][b]=1;
    }
    int cot=n;
    while(true)
    {
        for(i=1;i<=n;i++)
        {
            sz=q[i].size();
            //printf("%d\n",cot);
            for(k=1;k<=sz;k++)
            {
                x=q[i].front().X;
                y=q[i].front().Y;
                q[i].pop();
                for(j=0;j<4;j++)
                {
                    if(maps[x+dx[j]][y+dy[j]]==0)
                    {
                        cot++;
                        sum[i]++;
                        maps[x+dx[j]][y+dy[j]]=1;
                        q[i].emplace(x+dx[j],y+dy[j]);
                    }
                }
            }
           // if(cot>=r*c)
             //   break;
        }
        if(cot>=r*c)
            break;
    }
    for(i=1;i<=n;i++)
        printf("%d\n",sum[i]+1);
}
