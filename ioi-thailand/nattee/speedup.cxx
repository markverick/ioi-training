#include<bits/stdc++.h>
#define MI 1000000000000000000ll
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
long long n,m,L,Q,s[14],d[14][80135],jum[14][10],fk=0;
vector<pair<long long,long long> > adj[80135];
priority_queue<pair<long long,long long> > pq;
long long dp(long long idx,long long num)
{
	if(jum[idx][num]>=0)return jum[idx][num];
	long long p=(1<<num);
	if(num==Q)
	{
		return d[idx][n]/p;
	}
	long long mn=d[idx][n]/p;
	for(long long i=1;i<=L;i++)
	{
		if(i==idx)continue;
		mn=min(mn,dp(i,num+1)+d[idx][s[i]]/p);
	}
	return jum[idx][num]=mn;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	long long i,j,k,a,b,c,w,u;
	memset(jum,-1,sizeof jum);
	scanf("%lld %lld %lld %lld",&n,&m,&L,&Q);
	for(i=1;i<=m;i++)
		scanf("%lld %lld %lld",&a,&b,&c),adj[a].emplace_back(b,c);
	for(i=1;i<=L;i++)
	{
		scanf("%lld",&s[i]);
		if(s[i]==1)
			fk=1;
	}
	s[0]=1;s[L+1]=n;
	for(i=0;i<=L+1;i++)
	{
		for(j=0;j<=80005;j++)
			d[i][j]=MI;
		d[i][s[i]]=0;
	}
	for(i=0;i<=L;i++)
	{
		pq.emplace(0,s[i]);
		while(!pq.empty())
		{
			tie(w,u)=pq.top();
			w=-w;pq.pop();
			for(j=0;j<adj[u].size();j++)
			{
				if(w+adj[u][j].Y<d[i][adj[u][j].X])
				{
					d[i][adj[u][j].X]=w+adj[u][j].Y;
					pq.emplace(-d[i][adj[u][j].X],adj[u][j].X);
				}
			}
		}
		// for(j=1;j<=n;j++)
		// 	prlong longf("%lld ",d[i][j]);
		// prlong longf("\n");
	}
	long long mn=d[0][n];
	if(Q==0||L==0)
	{
		printf("%lld",mn);
		return 0;
	}
	for(i=1;i<=L;i++)
	{
		mn=min(mn,dp(i,1)+d[0][s[i]]);
	}
	printf("%lld",mn);	
}