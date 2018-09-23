#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int p[8],dd[35][35][35][35],dist[8][8],d[8][35][35],isSea[35][35],dx[6]={1,-1,0,0},dy[6]={0,0,1,-1},r,c,mps[35][35],grp[35][35],G=0;
vector<pair<int,int> > mb[6];
void sea(int x,int y)
{
	int i;
	isSea[x][y]=1;
	for(i=0;i<4;i++)
	{
		if(mps[x+dx[i]][y+dy[i]]==-1||isSea[x+dx[i]][y+dy[i]])continue;
		if(mps[x+dx[i]][y+dy[i]]) isSea[x+dx[i]][y+dy[i]]=2;
		else
			sea(x+dx[i],y+dy[i]);
	}
}
void dfs(int x,int y)
{
	mb[G].emplace_back(x,y);
	grp[x][y]=G;
	for(int i=0;i<4;i++)
	{
		if(mps[x+dx[i]][y+dy[i]]!=0||isSea[x+dx[i]][y+dy[i]]||grp[x+dx[i]][y+dy[i]])continue;
		dfs(x+dx[i],y+dy[i]);
	}
}
int Find(int x)
{
	if(p[x]==x) return x;
	return p[x]=Find(p[x]);
}
void Union(int x,int y)
{
	x=Find(x);y=Find(y);
	p[x]=y;
}
vector<tuple<int,int,int> > e;
priority_queue<tuple<int,int,int> > pq;
int res[8];

int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,l,I,J,x,y,w,mn=MI,sm;
	scanf("%d %d",&r,&c);
	for(i=1;i<=r;i++)
		for(j=1;j<=c;j++)
			scanf("%d",&mps[i+1][j+1]);
	r+=2;c+=2;
	for(i=0;i<=4;i++)
		for(j=0;j<=r+1;j++)
			for(k=0;k<c+1;k++)
				d[i][j][k]=MI;
	for(i=1;i<=r;i++)
		for(j=1;j<=c;j++)
			for(k=1;k<=r;k++)
				for(l=1;l<=c;l++)
					dd[i][j][k][l]=MI;
	for(i=0;i<=r+1;i++)
		mps[i][0]=-1,mps[i][c+1]=-1;
	for(i=0;i<=c+1;i++)
		mps[0][i]=-1,mps[r+1][i]=-1;
	sea(1,1);
	// for(i=1;i<=r;i++)
	// {
	// 	for(j=1;j<=c;j++)
	// 		printf("%d ",isSea[i][j]);
	// 	printf("\n");
	// }
	for(i=1;i<=r;i++)
	{
		for(j=1;j<=c;j++)
		{
			if(isSea[i][j]||mps[i][j]||grp[i][j])continue;
			G++;
			dfs(i,j);
		}
	}
	if(G<=1)
	{
		printf("0\n");
		return 0;
	}
	// for(i=1;i<=r;i++)
	// {
	// 	for(j=1;j<=c;j++)
	// 		printf("%d ",grp[i][j]);
	// 	printf("\n");
	// }
	for(i=1;i<=G;i++)
	{
		for(j=0;j<mb[i].size();j++)
			pq.emplace(0,mb[i][j].X,mb[i][j].Y),d[i][mb[i][j].X][mb[i][j].Y]=0;
		while(!pq.empty())
		{
			tie(w,x,y)=pq.top();w=-w;pq.pop();
			for(k=0;k<4;k++)
			{
				if(!isSea[x+dx[k]][y+dy[k]]&&w+mps[x+dx[k]][y+dy[k]]<d[i][x+dx[k]][y+dy[k]])
				{
					d[i][x+dx[k]][y+dy[k]]=w+mps[x+dx[k]][y+dy[k]];
					pq.emplace(-d[i][x+dx[k]][y+dy[k]],x+dx[k],y+dy[k]);
				}
			}
		}
		for(j=1;j<=G;j++)
			dist[i][j]=MI;
		for(j=1;j<=G;j++)
			for(k=0;k<mb[j].size();k++)
				dist[i][j]=min(dist[i][j],d[i][mb[j][k].X][mb[j][k].Y]);
	}
	// for(i=1;i<=G;i++)
	// {
	// 	for(j=1;j<=G;j++)
	// 		printf("%d ",dist[i][j]);
	// 	printf("\n");
	// }
	for(i=1;i<=r;i++)
	{
		for(j=1;j<=c;j++)
		{
			if(isSea[i][j])continue;
			dd[i][j][i][j]=mps[i][j];
			pq.emplace(-mps[i][j],i,j);
			while(!pq.empty())
			{
				tie(w,x,y)=pq.top();w=-w;pq.pop();
				for(k=0;k<4;k++)
				{
					if(!isSea[x+dx[k]][y+dy[k]]&&w+mps[x+dx[k]][y+dy[k]]<dd[i][j][x+dx[k]][y+dy[k]])
					{
						dd[i][j][x+dx[k]][y+dy[k]]=w+mps[x+dx[k]][y+dy[k]];
						pq.emplace(-dd[i][j][x+dx[k]][y+dy[k]],x+dx[k],y+dy[k]);
					}
				}
			}
		}
	}
	for(i=1;i<=r;i++)
	{
		for(j=1;j<=c;j++)
		{
			if(isSea[i][j])continue;
			for(k=1;k<=r;k++)
			{
				for(l=1;l<=c;l++)
				{
					if(isSea[k][l])continue;
					e.clear();
					for(I=1;I<=G;I++)
						e.emplace_back(d[I][i][j]-mps[i][j],I,G+1),e.emplace_back(d[I][k][l]-mps[k][l],I,G+2);
					e.emplace_back(dd[i][j][k][l]-mps[i][j]-mps[k][l],G+1,G+2);
					for(I=1;I<=G;I++)
						for(J=I+1;J<=G;J++)
							e.emplace_back(dist[I][J],I,J);
					sort(e.begin(),e.end());
					sm=0;
					for(I=0;I<=G+2;I++)
						p[I]=I;
					for(I=0;I<e.size();I++)
					{
						tie(w,x,y)=e[I];
						if(Find(x)!=Find(y))
							sm+=w,Union(x,y);
					}
					mn=min(mn,sm+mps[i][j]+mps[k][l]);
				}
			}
		}
	}
	printf("%d",mn);
}