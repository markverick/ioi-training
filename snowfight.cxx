#include<bits/stdc++.h>
#define MI 1ll000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
long long n,bit[22];
map<pair<long long,long long>,pair<long long,long long> > jum;
char mat[22][22];
vector<long long> adj[22];
pair<long long,long long> Pow(long long b,long long p)
{
	if(jum.find(MP(b,p))!=jum.end())return jum[MP(b,p)];
	pair<long long,long long> half,almost,full;
	long long out=0,i,j,sm=0;
	if(p==1ll)
	{
		for(i=0;i<n;i++)
		{
			if((1ll<<i)&b)
			{
				sm+=adj[i].size();
				out^=bit[i];
			}
			else
				sm+=adj[i].size()*2;
		}
		return jum[MP(b,p)]=MP(out,sm);
	}
	half=Pow(b,p/2);
	almost=Pow(half.X,p/2);
	almost.Y+=half.Y;
	if(p%2==0) return jum[MP(b,p)]=almost;
	full=Pow(almost.X,1);
	full.Y+=almost.Y;
	return jum[MP(b,p)]=full;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	long long i,j,k,t,sub=0;
	scanf("%lld %lld",&n,&t);
	for(i=0;i<n;i++)
	{
		scanf("%s",mat[i]);
		for(j=0;j<n;j++)
		{
			if(mat[i][j]=='1')
				adj[i].emplace_back(j),bit[i]|=(1ll<<j);
		}
	}
	for(i=1ll;i<n;i++)
		sub+=adj[i].size()*2;
	printf("%lld\n",Pow(1ll,t).Y-sub);
}