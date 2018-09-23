#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int seg[400135],x,y,val;
void update(int id,int fs,int ls)
{
	int md=(fs+ls)/2;
	if(fs==ls)
	{
		seg[id]=max(val,seg[id]);
		return;
	}
	if(x<=md)	update(id*2,fs,md);
	else		update(id*2+1,md+1,ls);
	seg[id]=max(seg[id*2],seg[id*2+1]);
}
int Max(int id,int fs,int ls)
{
	int md=(fs+ls)/2;
	if(ls<x||fs>y)
		return -MI;
	if(fs>=x&&ls<=y)
		return seg[id];
	return max(Max(id*2,fs,md),Max(id*2+1,md+1,ls));
}
vector<int> v;
unordered_map<int,int> mp;
tuple<int,int,int> p[100135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,cot=0,a,b,c;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		a++;b++;c++;
		v.emplace_back(b);
		p[i]=MT(a,b,c);
	}
	sort(v.begin(),v.end());
	v.resize(unique(v.begin(),v.end())-v.begin());
	for(i=0;i<v.size();i++)
		mp[v[i]]=i;
	sort(&p[1],&p[n+1]);
	for(i=n;i>=1;i--)
	{
		tie(a,b,c)=p[i];
		x=mp[b];y=v.size()-1;
		if(c<=Max(1,0,v.size()-1))cot++;
		x=mp[b];val=c;
		update(1,0,v.size()-1);
	}
	printf("%d",cot);
}