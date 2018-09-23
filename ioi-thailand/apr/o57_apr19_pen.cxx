#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
vector<int> v;
map<int,int> mp;
int seg[1200135],lazy[1200135],jum[100135],adj[100135],x,y,val;
tuple<int,int,int,int> t[100135];
void shift(int id,int fs,int ls)
{
	if(!lazy[id])return;
	if(fs==ls)	seg[fs]=lazy[id];
	else
	{
		lazy[id*2]=lazy[id];
		lazy[id*2+1]=lazy[id];
	}
	lazy[id]=0;
}
void update(int id,int fs,int ls)
{
	int md=(fs+ls)/2;
	shift(id,fs,ls);
	if(ls<x||fs>y)
		return;
	if(fs>=x&&ls<=y)
	{
		lazy[id]=val;
		shift(id,fs,ls);
		return;
	}
	update(id*2,fs,md);
	update(id*2+1,md+1,ls);
}
int Find(int id,int fs,int ls)
{
	int md=(fs+ls)/2;
	shift(id,fs,ls);
	if(fs==ls)
		return seg[fs];
	if(x<=md)
		return Find(id*2,fs,md);
	else
		return Find(id*2+1,md+1,ls);
}
int dfs(int idx)
{
	if(jum[idx])return jum[idx];
	if(idx==0)
		return 0;
	return jum[idx]=dfs(adj[idx])+1;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,a,b,c,d;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		v.emplace_back(a+1);
		v.emplace_back(b-1);
		v.emplace_back(b);
		t[i]=MT(c,a,b,i);
	}
	sort(v.begin(),v.end());
	v.resize(unique(v.begin(),v.end())-v.begin());
	for(i=0;i<v.size();i++)
		mp[v[i]]=i;
	sort(&t[1],&t[n+1]);
	for(i=1;i<=n;i++)
	{
		tie(c,a,b,d)=t[i];
		x=mp[b];
		adj[d]=Find(1,0,v.size());
		val=d;x=mp[a+1];y=mp[b-1];
		update(1,0,v.size());
	}
	for(i=1;i<=n;i++)
	{
		printf("%d\n",dfs(i));
	}
}