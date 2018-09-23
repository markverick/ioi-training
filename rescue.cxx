#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int dx[6]={1,-1,0,0};
int dy[6]={0,0,1,-1};
int sx,sy,sh;
char maps[13][105][105];
int jum[13][105][105];
int xp[13][105][105];
long long dj[10135];
vector<pair<int,int> > val;
// time xp
queue<tuple<int,int,int,int> > q;
// height(l) x y time(t)
int s;
int main()
{
    int T,h,r,c,n,i,j,k,l,x,y,t,a,b,C,D;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d %d %d %d",&h,&r,&c,&n,&s);
        //s/=3;
        memset(jum,0,sizeof jum);
        memset(dj,-1,sizeof dj);
        memset(xp,0,sizeof xp);
        memset(maps,0,sizeof maps);
        val.clear();
        for(k=1;k<=h;k++)
        {
            for(i=1;i<=r;i++)
            {
                scanf("%s",maps[k][i]+1);
                for(j=1;j<=c;j++)
                {
                    if(maps[k][i][j]=='S')
                    {
                        sx=i;sy=j;sh=k;
                    }
                }
            }
        }
        for(i=1;i<=n;i++)
        {
            scanf("%d %d %d %d",&a,&b,&C,&D);
            xp[a][b][C]=D;
        }
        q.emplace(sh,sx,sy,0);
        jum[sh][sx][sy]=1;
        while(!q.empty())
        {
            tie(l,x,y,t)=q.front();
            q.pop();
            if(xp[l][x][y]>0)
            {
                val.emplace_back(t,xp[l][x][y]);
            }
            for(i=0;i<4;i++)
            {
                if(jum[l][x+dx[i]][y+dy[i]]==1)
                    continue;
                jum[l][x+dx[i]][y+dy[i]]=1;
                if(maps[l][x+dx[i]][y+dy[i]]=='.'||maps[l][x+dx[i]][y+dy[i]]=='D'||maps[l][x+dx[i]][y+dy[i]]=='U')
                {
                    q.emplace(l,x+dx[i],y+dy[i],t+1);
                }
            }
            if(maps[l][x][y]=='U')
            {
                if(jum[l+1][x][y]==1)
                    continue;
                jum[l+1][x][y]=1;
                q.emplace(l+1,x,y,t+1);
            }
            if(maps[l][x][y]=='D')
            {
                if(jum[l-1][x][y]==1)
                    continue;
                jum[l-1][x][y]=1;
                q.emplace(l-1,x,y,t+1);
            }
        }
        sort(val.begin(),val.end());
        dj[0]=0;
        for(i=0;i<val.size();i++)
        {
            for(k=s;k>=0;k--)
            {
                if(k+3*val[i].X<=s&&dj[k]>=0)
                    dj[k+3*val[i].X]=max(dj[k+3*val[i].X],dj[k]+val[i].Y);
            }
        }
        long long mc=0;
        for(i=s;i>=0;i--)
        {
            mc=max(mc,dj[i]);
        }
        printf("%lld\n",mc);
        //printf("%d\n",dp(0,0));
        /*for(i=0;i<val.size();i++)
        {
            printf("%d %d\n",val[i].X,val[i].Y);
        }*/
    }
}
