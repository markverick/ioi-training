#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int seg[400135],x,y,val;
pair<int,int> stp[400135];
pair<int,int> operator +(pair<int,int> a,pair<int,int> b)
{
	return MP(a.X+b.X,a.Y+b.Y);
}
void update(int id,int fs,int ls)
{
	int md=(fs+ls)/2;
	if(fs==ls)
	{
		seg[id]+=val;
		if(seg[id]==0)
			stp[id]={0,0};
		else if(seg[id]>0)
			stp[id]={1,0};
		else
			stp[id]={0,1};
		return;
	}
	if(x<=md)
		update(id*2,fs,md);
	else
		update(id*2+1,md+1,ls);
	seg[id]=seg[id*2]+seg[id*2+1];
	stp[id]=stp[id*2]+stp[id*2+1];
}
int sum(int id,int fs,int ls)
{
	int md=(fs+ls)/2;
	if(ls<x||fs>y)
		return 0;
	if(fs>=x&&ls<=y)
		return seg[id];
	return sum(id*2,fs,md)+sum(id*2+1,md+1,ls);
}
pair<int,int> step(int id,int fs,int ls)
{
	int md=(fs+ls)/2;
	if(ls<x||fs>y)
		return MP(0,0);
	if(fs>=x&&ls<=y)
		return stp[id];
	return step(id*2,fs,md)+step(id*2+1,md+1,ls);
}
int main()
{
	freopen("out.txt","w",stdout);//bug
	//freopen("in.txt","r",stdin);
	int n,m,i,j,k,ch,a,b;
	pair<int,int> p;
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d",&ch);
		scanf("%d %d",&a,&b);
		if(ch==1)
		{
			x=a;val=1;
			update(1,1,n);
			x=b+1;val=-1;
			update(1,1,n);
		}
		else if(ch==2)
		{
			x=1;y=a;
			printf("%d ",sum(1,1,n));
			x=1;y=b;
			printf("%d\n",sum(1,1,n));
		}
		else
		{
			x=1;y=a;
			printf("%d ",sum(1,1,n));
			x=1;y=b;
			printf("%d ",sum(1,1,n));
			x=a;y=b;
			p=step(1,1,n);
			printf("%d %d\n",p.X,p.Y);
		}
	}
}