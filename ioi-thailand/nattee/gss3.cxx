#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[50135],x,y,val;
int seg[200135],Max[200135],L[200135],R[200135];
void build(int id,int fs,int ls)
{
	int md=(fs+ls)/2;
	if(fs==ls)
	{
		seg[id]=Max[id]=L[id]=R[id]=a[fs];
		return;
	}
	build(id*2,fs,md);
	build(id*2+1,md+1,ls);
	seg[id]=seg[id*2]+seg[id*2+1];
	Max[id]=max(Max[id*2],Max[id*2+1]);
	Max[id]=max(Max[id],R[id*2]+L[id*2+1]);
	L[id]=max(L[id*2],seg[id*2]+L[id*2+1]);
	R[id]=max(R[id*2+1],seg[id*2+1]+R[id*2]);
	// Max[id]=max(Max[id],L[id*2]);
	// Max[id]=max(Max[id],R[id*2+1]);
}
void upd(int id,int fs,int ls)
{
	int md=(fs+ls)/2;
	if(fs==ls)
	{
		seg[id]=Max[id]=L[id]=R[id]=val;
		return;
	}
	if(x<=md)
		upd(id*2,fs,md);
	else
		upd(id*2+1,md+1,ls);
	seg[id]=seg[id*2]+seg[id*2+1];
	Max[id]=max(Max[id*2],Max[id*2+1]);
	Max[id]=max(Max[id],R[id*2]+L[id*2+1]);
	L[id]=max(L[id*2],seg[id*2]+L[id*2+1]);
	R[id]=max(R[id*2+1],seg[id*2+1]+R[id*2]);
	// Max[id]=max(Max[id],L[id*2]);
	// Max[id]=max(Max[id],R[id*2+1]);
}
tuple<int,int,int,int> Find(int id,int fs,int ls)
{
	int md=(fs+ls)/2;
	if(ls<x||fs>y)
		return MT(-MI,-MI,-MI,0);
	if(fs>=x&&ls<=y)
		return MT(Max[id],L[id],R[id],seg[id]);
	int ma,La,Ra,mb,Lb,Rb,sa,sb,mc,Lc,Rc,sc;
	tie(ma,La,Ra,sa)=Find(id*2,fs,md);
	tie(mb,Lb,Rb,sb)=Find(id*2+1,md+1,ls);
	Lc=max(sa+Lb,La);
	Rc=max(sb+Ra,Rb);
	sc=sa+sb;
	mc=max(ma,mb);
	mc=max(mc,Ra+Lb);
	mc=max(mc,max(La,Rb));
	return MT(mc,Lc,Rc,sc);
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,Q,i,j,k,ch;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	build(1,1,n);
	scanf("%d",&Q);
	while(Q--)
	{
		scanf("%d",&ch);
		if(ch==0)
		{
			scanf("%d %d",&x,&val);
			upd(1,1,n);
		}
		else
		{
			scanf("%d %d",&x,&y);
			printf("%d\n",get<0>(Find(1,1,n)));
		}
	}
}