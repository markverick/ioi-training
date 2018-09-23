#include<bits/stdc++.h>
#define MI 1000000000
#define S 4500
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
vector<int> mat[4555][4555];
vector<int> *it;
pair<int,int> p[100135];
int dx[5]={1,0,1,1};
int dy[5]={0,1,1,-1};
int pa[100135];
int dist(pair<int,int> a,pair<int,int> b)
{
	return (a.X-b.X)*(a.X-b.X)+(a.Y-b.Y)*(a.Y-b.Y);
}
vector<tuple<int,int,int> > e;
int Find(int x)
{
	if(x==pa[x])return x;
	return pa[x]=Find(pa[x]);
}
void Union(int x,int y)
{
	x=Find(x);y=Find(y);
	pa[x]=y;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int a,b,c,n,i,j,k,I,l,blk=sqrt(10000000);
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		pa[i]=i;
		scanf("%lld %lld",&p[i].X,&p[i].Y);
		p[i].X+=10000005;p[i].Y+=10000005;
		mat[p[i].X/blk+1][p[i].Y/blk+1].emplace_back(i);
	}
	for(i=0;i<=S;i++)
	{
		for(j=0;j<=S;j++)
		{
			for(l=0;l<mat[i][j].size();l++)
				for(k=l+1;k<mat[i][j].size();k++)
					e.emplace_back(dist(p[mat[i][j][k]],p[mat[i][j][l]]),mat[i][j][k],mat[i][j][l]);
			for(k=0;k<4;k++)
			{
				for(l=0;l<mat[i][j].size();l++)
				{
					for(I=0;I<mat[i+dx[k]][j+dy[k]].size();I++)
					{
						e.emplace_back(dist(p[mat[i][j][l]],p[mat[i+dx[k]][j+dy[k]][I]]),mat[i][j][l],mat[i+dx[k]][j+dy[k]][I]);
					}
				}
			}
		}
	}
	sort(e.begin(),e.end());
	int sm=0;
	for(i=0;i<e.size();i++)
	{
		tie(a,b,c)=e[i];
		printf("%lld %lld %lld\n",a,b,c);
		if(Find(b)!=Find(c))
		{
			Union(b,c);
			sm+=a;
		}
		printf("%lld\n",sm);
	}
	printf("%lld",sm);
}