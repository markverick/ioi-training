#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char maps[33][33][33];
int ste[33][33][33];
int dx[6]={1,-1,0,0};
int dy[6]={0,0,1,-1};
tuple<int,int,int> s,t;
queue<tuple<int,int,int> > q;
int main()
{
//	freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int T,L,r,c,i,j,k,out,z,x,y;
    while(scanf("%d %d %d",&L,&r,&c)!=EOF)
    {
        if(L==0&&r==0&&c==0)
            break;
        memset(maps,0,sizeof maps);
        for(k=1;k<=L;k++)
        {
            for(i=1;i<=r;i++)
            {
                scanf("%s",maps[k][i]+1);
                for(j=1;j<=c;j++)
                {
                    if(maps[k][i][j]=='S')
                        s=MT(k,i,j);
                    else if(maps[k][i][j]=='E')
                        t=MT(k,i,j),maps[k][i][j]='.';
                }
            }
        }
        q.emplace(s);
        for(i=0;i<=L+1;i++)
            for(j=0;j<=r+1;j++)
                for(k=0;k<=c+1;k++)
                    ste[i][j][k]=MI;
        tie(z,x,y)=s;
        ste[z][x][y]=0;
        while(!q.empty())
        {
            tie(z,x,y)=q.front();
            q.pop();
            for(i=0;i<4;i++)
            {
                if(maps[z][x+dx[i]][y+dy[i]]=='.'&&ste[z][x+dx[i]][y+dy[i]]>=MI)
                {
                    ste[z][x+dx[i]][y+dy[i]]=ste[z][x][y]+1;
                    q.emplace(z,x+dx[i],y+dy[i]);
                }
            }
            if(maps[z+1][x][y]=='.'&&ste[z+1][x][y]>=MI)
            {
                ste[z+1][x][y]=ste[z][x][y]+1;
                q.emplace(z+1,x,y);
            }
            if(maps[z-1][x][y]=='.'&&ste[z-1][x][y]>=MI)
            {
                ste[z-1][x][y]=ste[z][x][y]+1;
                q.emplace(z-1,x,y);
            }
        }
        tie(z,x,y)=t;
        if(ste[z][x][y]>=MI)
            printf("Trapped!\n");
        else
            printf("Escaped in %d minute(s).\n",ste[z][x][y]);
    }
}
