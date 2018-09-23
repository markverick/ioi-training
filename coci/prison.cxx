#include<bits/stdc++.h>
#define MI 1000000000ll
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
pair<long long,long long> p[100135];
map<long long,long long> mp;
vector<pair<long long,long long> > adj[200135];
vector<long long> v;
priority_queue<pair<long long,long long> > pq;
long long d[200135];
long long Source(long long x)
{
	long long fs=1,md,ls=MI,mc=1,len,mul,dif;
	while(fs<=ls)
	{
		md=(fs+ls)/2;
		if(md*md<x)
		{
			mc=max(mc,md);
			fs=md+1;
		}
		else
			ls=md-1;
	}
	if(mc%2==0)mc--;
	len=(mc+2)*(mc+2)-mc*mc;
	mul=(x-mc*mc-1)/(len/4);
	dif=mc*mc-(mc-2)*(mc-2)+mul*2+1;
	if(x==mc*mc+1)return x-1;
	// printf("!%d\n",mul);
	return x-dif;

}
int main()
{
	// freopen("out.txt","w",stdout);
	// freopen("in.txt","r",stdin);
	long long n,i,j,k,m,u,w;
	scanf("%lld %lld",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%lld",&p[i].Y);
		p[i].X=Source(p[i].Y);
		// printf("%lld\n",p[i].X);
		v.emplace_back(p[i].X);
		v.emplace_back(p[i].Y);
	}
	v.emplace_back(n);
	v.emplace_back(1);
	// sort(&p[1],&p[m+1]);
	sort(v.begin(),v.end());
	v.resize(unique(v.begin(),v.end())-v.begin());
	for(i=0;i<v.size();i++)
		mp[v[i]]=i;
	for(i=1;i<v.size();i++)
	{
		adj[i-1].emplace_back(i,v[i]-v[i-1]);
		adj[i].emplace_back(i-1,v[i]-v[i-1]);
	}
	for(i=1;i<=m;i++)
	{
		adj[mp[p[i].X]].emplace_back(mp[p[i].Y],1);
		adj[mp[p[i].Y]].emplace_back(mp[p[i].X],1);
	}
	for(i=0;i<=200100;i++)
		d[i]=MI*MI;
	d[0]=0;
	pq.emplace(0,0);
	while(!pq.empty())
	{
		tie(w,u)=pq.top();
		pq.pop();
		w=-w;
		// printf("%lld %lld\n",u,w);
		for(i=0;i<adj[u].size();i++)
		{
			if(w+adj[u][i].Y<d[adj[u][i].X])
			{
				d[adj[u][i].X]=w+adj[u][i].Y;
				pq.emplace(-d[adj[u][i].X],adj[u][i].X);
			}
		}
	}
	printf("%lld\n",d[mp[n]]);
}