#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int seg[2097252];
int x,y,val;
void update(int id,int fs,int ls)
{
	int md=(fs+ls)/2;
	if(fs==ls)
	{
		seg[id]=val;
		return;
	}
	update(id*2,fs,md);
	update(id*2+1,md+1,ls);
	seg[id]=max(seg[id*2],seg[id*2+1]);
}
int qr(int id,int fs,int ls)
{
	int md=(fs+ls)/2;
	if(ls<x||fs>y)
		return 0;
	if(fs>=x&&ls<=y)
		return seg[id];
	return max(qr(id*2,fs,md),qr(id*2+1,md+1,ls));
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,n,m,fs,md,ls,mn,mc,pos,h;
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d %d",&pos,&h);
		fs=pos;ls=n;mc=pos;
		x=pos;
		while(fs<=ls)
		{
			md=(fs+ls)/2;
			y=md;
			if(h>=qr(1,1,n))
			{
				mc=max(mc,md);
				fs=md+1;
			}
			else
				ls=md-1;
		}
		fs=1;ls=pos;mn=pos;
		y=pos;
		while(fs<=ls)
		{
			md=(fs+ls)/2;
			x=md;
			if(h>=qr(1,1,n))
			{
				mn=min(mn,md);
				ls=md-1;
			}
			else
				fs=md+1;
		}
		x=pos;val=h;
		update(1,1,n);
		printf("%d\n",mc-mn+1);
	}
	
}