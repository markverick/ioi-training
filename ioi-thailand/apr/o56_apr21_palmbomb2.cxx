#include<bits/stdc++.h>
#define MI 1000000000
#define MX 100005
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
vector<pair<int,int> > add[150135],del[150135];
int sz[50135],hsh[50135],cnai[150135],st[150135],bd[50135],Max[600135],x,y,val;
vector<int> qr[150135];
void upd(int id,int fs,int ls)
{
	int md=(fs+ls)/2;
	if(fs==ls)
	{
		Max[id]+=val;
		return;
	}
	if(x<=md)
		upd(id*2,fs,md);
	else
		upd(id*2+1,md+1,ls);
	Max[id]=max(Max[id*2],Max[id*2+1]);
}
int Find(int id,int fs,int ls)
{
	int md=(fs+ls)/2;
	if(ls<x||fs>y)
		return 0;
	if(fs>=x&&ls<=y)
		return Max[id];
	return max(Find(id*2,fs,md),Find(id*2+1,md+1,ls));
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,n,Q,a,b,ch,fs,md,ls,mc;
	scanf("%d %d",&n,&Q);
	for(i=1;i<=n;i++)
	{
		scanf("%d %d",&a,&b);
		sz[i]=a;
		cnai[i]=i;
		st[i]=b;
		bd[i]=n+Q;
	}
	for(i=n+1;i<=n+Q;i++)
	{
		scanf("%d",&ch);
		if(ch==1)
		{
			scanf("%d %d",&a,&b);
			cnai[i]=a;
			st[i]=b;
		}
		else
		{
			scanf("%d",&a);
			qr[a].emplace_back(i);
		}
	}
	for(i=n+Q;i>=1;i--)
	{
		if(cnai[i]==0)continue;
		// printf("%d\n",cnai[i]);
		add[st[i]].emplace_back(i,bd[cnai[i]]);
		if(st[i]+sz[cnai[i]]+1<=MX)
			del[st[i]+sz[cnai[i]]+1].emplace_back(i,bd[cnai[i]]);
		bd[cnai[i]]=i-1;
	}
	for(i=0;i<=100000;i++)
	{
		for(j=0;j<add[i].size();j++)
		{
			x=add[i][j].X;
			val=add[i][j].Y;
			upd(1,1,n+Q);
		}
		for(j=0;j<del[i].size();j++)
		{
			x=del[i][j].X;
			val=-del[i][j].Y;
			upd(1,1,n+Q);
		}
		for(j=0;j<qr[i].size();j++)
		{
			fs=1;ls=qr[i][j];mc=0;
			while(fs<=ls)
			{
				md=(fs+ls)/2;
				// printf("%d <-%d-> %d\n",fs,md,ls);
				x=md;y=qr[i][j];
				if(Find(1,1,n+Q)>=qr[i][j])
				{
					mc=max(mc,md);
					fs=md+1;
				}
				else
					ls=md-1;
			}
			hsh[cnai[mc]]++;
		}
	}
	for(i=1;i<=n;i++)
		printf("%d\n",hsh[i]);
}