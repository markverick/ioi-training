#include<bits/stdc++.h>
#define MI 1000000000
#define MX 100005
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
set<int> seg[100135],ad[400135],rem[400135];
set<int> ::iterator it;
int x,y,val,indx[100135],pos[100135],sz[50135],cnai[100135],hsh[50135];
void shift(int id,int fs,int ls)
{
	while(!ad[id].empty())
	{
		if(fs!=ls)
			ad[id*2].insert(*ad[id].begin()),ad[id*2+1].insert(*ad[id].begin());
		else
			seg[fs].insert(*ad[id].begin());
		ad[id].erase(ad[id].begin());
	}
	while(!rem[id].empty())
	{
		if(fs!=ls)
			rem[id*2].insert(*rem[id].begin()),rem[id*2+1].insert(*rem[id].begin());
		else
			seg[fs].erase(*rem[id].begin());
		rem[id].erase(rem[id].begin());
	}

}
void add(int id,int fs,int ls)
{
	// printf("%d %d %d\n",id,fs,ls);
	int md=(fs+ls)/2;
	shift(id,fs,ls);
	if(ls<x||fs>y)
		return;
	if(fs>=x&&ls<=y)
	{
		ad[id].insert(val);
		shift(id,fs,ls);
		return;
	}
	add(id*2,fs,md);
	add(id*2+1,md+1,ls);
}
void del(int id,int fs,int ls)
{
	int md=(fs+ls)/2;
	shift(id,fs,ls);
	if(ls<x||fs>y)return;
	if(fs>=x&&ls<=y)
	{
		rem[id].insert(val);
		shift(id,fs,ls);
		return;
	}
	del(id*2,fs,md);
	del(id*2+1,md+1,ls);
}
int find(int id,int fs,int ls)
{
	int md=(fs+ls)/2;
	shift(id,fs,ls);
	if(fs==ls)
	{
		if(seg[fs].empty())return 0; 
		it=seg[fs].end();it--;
		return *it;
	}
	if(x<=md)
		return find(id*2,fs,md);
	else
		return find(id*2+1,md+1,ls);
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,q,i,j,k,a,b,ch;
	scanf("%d %d",&n,&q);
	for(i=1;i<=n;i++)
	{
		scanf("%d %d",&sz[i],&x);
		x++;
		val=i;y=x+sz[i];
		y=min(y,MX);
		pos[i]=x;
		indx[x]=i;
		cnai[i]=i;
		add(1,1,MX);
	}
	// x=3;
	// printf("%d\n",find(1,1,MX));
	// return 0;
	for(i=n+1;i<=n+q;i++)
	{
		scanf("%d",&ch);
		if(ch==1)
		{
			scanf("%d %d",&a,&b);
			b++;
			x=pos[a];y=x+sz[a];
			y=min(y,MX);
			val=indx[a];
			del(1,1,MX);
			x=b;y=b+sz[a];
			y=min(y,MX);
			val=indx[a]=i;
			add(1,1,MX);
			cnai[i]=a;
			pos[a]=b;
		}
		else
		{
			scanf("%d",&x);
			x++;
			// printf("HIT %d\n",cnai[find(1,1,MX)]);
			hsh[cnai[find(1,1,MX)]]++;
		}
	}
	for(i=1;i<=n;i++)
	{
		printf("%d\n",hsh[i]);
	}
}