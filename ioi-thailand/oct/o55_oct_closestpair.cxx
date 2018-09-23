#include<bits/stdc++.h>
using namespace std;
#define MI 100000000000000000ll
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
pair<long long,long long> p[100135];
vector<pair<long long,long long> > srt[400135];
inline long long pot(long long x,long long y)
{return x*x+y*y;}
inline long long sq(long long x)
{return x*x;}
long long dp(long long fs,long long ls,long long id)
{
	if(fs==ls)
	{
		srt[id].emplace_back(p[fs].Y,fs);
		return MI;
	}
	// if(fs+1==ls)
	// {
	// 	if(p[fs].Y<=p[ls].Y)
	// 		srt[id].emplace_back(p[fs].Y,fs);
	// 	else
	// 		srt[id].emplace_back(p[ls].Y,ls);
	// 	return pot(p[fs].X-p[ls].X,p[fs].Y-p[ls].Y);
	// }
	long long md=(fs+ls)/2,Min,x=0,y=0,mn,i,j;
	// printf("%lld %lld %lld\n",fs,md,ls);
	mn=min(dp(fs,md,id*2),dp(md+1,ls,id*2+1));
	Min=mn;
	pair<long long,long long> pl,pr;
	vector<long long> L,R;
	for(i=0;i<srt[id*2].size();i++)
	{
		pl=p[srt[id*2][i].Y];
		if(sq(p[md].X-pl.X)<=mn)
			L.emplace_back(srt[id*2][i].Y);
	}
	for(i=0;i<L.size();i++)
	{
		pl=p[L[i]];
		while(y<srt[id*2+1].size()&&srt[id*2+1][y].Y-p[L[i]].Y<=sqrt(mn))
			y++;
		y--;
		while(x<srt[id*2+1].size()&&p[L[i]].Y-srt[id*2+1][x].Y>=sqrt(mn))
			x++;
		if(x>y)continue;
		for(j=x;j<=y;j++)
		{
			pr=p[srt[id*2+1][j].Y];
			Min=min(Min,pot(pr.X-pl.X,pr.Y-pl.Y));
		}
	}
	j=0;
	for(i=0;i<srt[id*2].size();i++)
	{
		while(j<srt[id*2+1].size()&&srt[id*2+1][j]<srt[id*2][i])
			srt[id].emplace_back(srt[id*2+1][j++]);
		srt[id].emplace_back(srt[id*2][i]);
	}
	while(j<srt[id*2+1].size())
		srt[id].emplace_back(srt[id*2+1][j++]);
	return Min;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	long long n,i,j,k;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld %lld",&p[i].X,&p[i].Y);
	}
	sort(&p[1],&p[n+1]);
	printf("%lld\n",dp(1,n,1));
}