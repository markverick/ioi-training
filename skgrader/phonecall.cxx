#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
long long x,y,n;
pair<long long,long long> p[100135],seg[400135];
void build(long long id,long long fs,long long ls)
{
	long long md=(fs+ls)/2;
	if(fs==ls)
	{
		seg[id]=MP(p[fs].Y,fs);
		return;
	}
	build(id*2,fs,md);
	build(id*2+1,md+1,ls);
	seg[id]=seg[id*2].X<seg[id*2+1].X?seg[id*2]:seg[id*2+1];
}
pair<long long,long long> Min(long long id,long long fs,long long ls)
{
	long long md=(fs+ls)/2;
	pair<long long,long long> L,R;
	if(ls<x||fs>y)
		return MP(MI,0);
	if(fs>=x&&ls<=y)
		return seg[id];
	L=Min(id*2,fs,md);
	R=Min(id*2+1,md+1,ls);
	return L.X<R.X?L:R;
}
long long div(long long fs,long long ls,long long base)
{
	if(fs>ls)return 0;
	if(fs==ls)return p[fs].Y-base;
	pair<long long,long long> mn;
	long long sm=0;
	x=fs;y=ls;
	mn=Min(1,1,n);
	sm=mn.X-base;
	sm+=div(fs,mn.Y-1,mn.X);
	sm+=div(mn.Y+1,ls,mn.X);
	return sm;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	long long i,j,k,m;
	scanf("%lld %lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld %lld",&p[i].X,&p[i].Y);
	}
	sort(&p[1],&p[n+1]);
	build(1,1,n);
	printf("%lld\n",div(1,n,0));
}