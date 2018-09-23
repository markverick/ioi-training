#include<bits/stdc++.h>
#define MI 1000000000
#define S 4500
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
vector<long long> mat[4555][4555],strip[4555];
vector<long long> *it;
pair<long long,long long> p[100135];
long long dx[5]={1,0,1,1};
long long dy[5]={0,1,1,-1};
long long pa[100135];
long long dist(pair<long long,long long> a,pair<long long,long long> b)
{
	return (a.X-b.X)*(a.X-b.X)+(a.Y-b.Y)*(a.Y-b.Y);
}
vector<tuple<long long,long long,long long> > e;
long long Find(long long x)
{
	if(x==pa[x])return x;
	return pa[x]=Find(pa[x]);
}
void Union(long long x,long long y)
{
	x=Find(x);y=Find(y);
	pa[x]=y;
}
void push(long long a,long long b)
{
	e.emplace_back(dist(p[a],p[b]),a,b);
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	long long a,b,c,n,i,j,k,I,J,l,blk=sqrt(20000000);
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		pa[i]=i;
		scanf("%lld %lld",&p[i].X,&p[i].Y);
		p[i].X+=10000005;p[i].Y+=10000005;
		mat[p[i].X/blk+1][p[i].Y/blk+1].emplace_back(i);
		strip[p[i].X/blk+1].emplace_back(i);
	}
	for(i=1;i<=S;i++)
	{
		for(j=1;j<=S;j++)
		{
			for(k)
			for(k=0;k<mat[i][j].size();k++)
			{
				for(l=0;l<mat)
			}
		}
	}
	sort(e.begin(),e.end());
	long long sm=0;
	for(i=0;i<e.size();i++)
	{
		tie(a,b,c)=e[i];
		// printf("%lld %lld %lld\n",a,b,c);
		if(Find(b)!=Find(c))
		{
			Union(b,c);
			sm+=a;
		}
	}
	printf("%lld",sm);
}