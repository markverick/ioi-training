#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int dx[6]={1,-1,0,0,0},dy[6]={0,0,1,-1,0},g[135][135],t,d[105][105];
char maps[135][135];
priority_queue<tuple<int,int,int> > pq;
queue<pair<int,int> > q;
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,r,c,T,sx,sy,a,b,C,x,y,w;
	scanf("%d",&T);
	while(T--)
    {
        scanf("%d %d %d %d %d %d",&r,&c,&n,&t,&sx,&sy);
        sx++;sy++;
        memset(maps,0,sizeof maps);
        memset(d,-1,sizeof d);
        for(i=1;i<=r;i++)
            for(j=1;j<=c;j++)
                g[i][j]=MI;
        for(i=1;i<=n;i++)
        {
            scanf("%d %d %d",&a,&b,&C);
            b++;C++;
            g[b][C]=a;
            pq.emplace(-a,b,C);
        }
        for(i=1;i<=r;i++)
        {
            scanf("%s",maps[i]+1);
        }
        while(!pq.empty())
        {
            tie(w,x,y)=pq.top();w=-w;pq.pop();
//            printf("%d %d %d\n",w,x,y);
            for(i=0;i<4;i++)
            {
                if(maps[x+dx[i]][y+dy[i]]!='.')continue;
                if(w+1<g[x+dx[i]][y+dy[i]])
                {
                    g[x+dx[i]][y+dy[i]]=w+1;
                    pq.emplace(-w-1,x+dx[i],y+dy[i]);
                }
            }
        }
//        for(i=1;i<=r;i++)
//        {
//            for(j=1;j<=c;j++)
//            {
//                printf("%3d ",g[i][j]);
//            }
//            printf("\n");
//        }
        q.emplace(sx,sy);
        d[sx][sy]=0;
        while(!q.empty())
        {
            tie(x,y)=q.front();q.pop();
            w=d[x][y];
            if(w>=g[x][y])
                continue;
            for(i=0;i<4;i++)
            {
                if(maps[x+dx[i]][y+dy[i]]!='.')continue;
                if(d[x+dx[i]][y+dy[i]]>=0)continue;
                if(w+1<g[x+dx[i]][y+dy[i]])
                {
                    d[x+dx[i]][y+dy[i]]=w+1;
                    q.emplace(x+dx[i],y+dy[i]);
                }
            }
        }
        int fk=0;
//        printf("%d %d\n",g[1][3],t);
        for(i=1;i<=r;i++)
        {
            for(j=1;j<=c;j++)
            {
//                printf("%3d ",d[i][j]);
                if(g[i][j]>t&&d[i][j]>=0)
                {
                    fk=1;
                    break;
                }
            }
            if(fk)break;
//            printf("\n");
        }
        if(fk)
            printf("YES\n");
        else
            printf("NO\n");
    }
}
