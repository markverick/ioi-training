#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
long long a[2135][210],qs[2135][210],d[2135][210];
vector<pair<long long,long long> > adj[4135];
priority_queue<pair<long long,long long> > pq;
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	long long n,i,j,k,r,c,w,u;
    scanf("%lld %lld",&r,&c);
    for(i=1;i<=r;i++)
        for(j=1;j<=c;j++)
            scanf("%lld",&a[i][j]),qs[i][j]=qs[i][j-1]+a[i][j];
    for(i=1;i<=r;i++)
    {
        adj[i].emplace_back(r+i,qs[i][c]-qs[i][1]);
        adj[r+i].emplace_back(i,qs[i][c-1]-qs[i][0]);
        if(i!=1)
        {
            adj[i].emplace_back(i-1,a[i-1][1]);            adj[r+i].emplace_back(r+i-1,a[i-1][c]);
        }
        if(i!=r)
        {
            adj[i].emplace_back(i+1,a[i+1][1]);            adj[r+i].emplace_back(r+i+1,a[i+1][c]);
        }
    }
    for(i=1;i<=r*2;i++)
    {
        for(j=1;j<=r*2;j++)
            d[i][j]=MI;
        d[i][i]=0;
        pq.emplace(0,i);
        while(!pq.empty())
        {
            tie(w,u)=pq.top();w=-w;
            pq.pop();
            for(j=0;j<adj[u].size();j++)
            {
                if(d[i][adj[u][j].X]>w+adj[u][j].Y)
                {
                    d[i][adj[u][j].X]=w+adj[u][j].Y;
                    pq.emplace(-d[i][adj[u][j].X],adj[u][j].X);
                }
            }
        }
    }
    long long x,y,ux=a[1][1],uy=d[1][r+1]+a[1][1],vx,vy,R=1,Q,lf,ri;
    scanf("%lld",&Q);
    while(Q--)
    {
        scanf("%lld %lld",&x,&y);
        lf=min(ux+d[R][x],uy+d[r+R][x]);
        ri=min(ux+d[R][r+x],uy+d[r+R][r+x]);
        if(!Q)
        {
            printf("%lld",min(lf+qs[x][y]-qs[x][1],ri+qs[x][c-1]-qs[x][y-1]));
            break;
        }
        ux=min(lf+qs[x][y]-qs[x][1]+qs[x][y-1]-qs[x][0],ri+qs[x][c-1]-qs[x][0]);
        uy=min(lf+qs[x][c]-qs[x][1],ri+qs[x][c-1]-qs[x][y-1]+qs[x][c]-qs[x][y]);
//        printf("!%lld %lld -> %lld %lld\n",lf,ri,ux,uy);
        R=x;
    }
}
