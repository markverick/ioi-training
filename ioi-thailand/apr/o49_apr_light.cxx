#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int seg[400135],lazy[400135],x,y,a[100135],pos[100135];
vector<int> v;
map<int,int> mp;
void build(int id,int fs,int ls)
{
	int md=(fs+ls)/2;
	if(fs==ls)
	{
		seg[id]=pos[ls+1]-pos[fs];
		return;
	}
	build(id*2,fs,md);
	build(id*2+1,md+1,ls);
	seg[id]=seg[id*2]+seg[id*2+1];
}
void shift(int id,int fs,int ls)
{
	if(!lazy[id])return;
	seg[id]=pos[ls+1]-pos[fs]-seg[id];
	if(fs!=ls)
	{
		lazy[id*2]^=1;
		lazy[id*2+1]^=1;
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
		lazy[id]^=1;
		shift(id,fs,ls);
		return;
	}
	update(id*2,fs,md);
	update(id*2+1,md+1,ls);
	seg[id]=seg[id*2]+seg[id*2+1];
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,m,i,j,k;
	scanf("%d %d",&n,&m);
	v.emplace_back(0);
	for(i=1;i<=m;i++)
	{
		scanf("%d",&a[i]);
		v.emplace_back(a[i]);
	}
	v.emplace_back(n);
	sort(v.begin(),v.end());
	v.resize(unique(v.begin(),v.end())-v.begin());
	for(i=0;i<v.size();i++)
		mp[v[i]]=i,pos[i]=v[i];
	y=v.size()-2;
	build(1,0,v.size()-2);
		// printf("%d\n",seg[1]);
	for(i=1;i<=m;i++)
	{
		x=mp[a[i]];
		update(1,0,v.size()-2);
		printf("%d\n",seg[1]);
	}
}