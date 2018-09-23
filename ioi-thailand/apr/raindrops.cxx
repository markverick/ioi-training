#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int t,x,y,r,c,toAdd,L,R;
long long sm=0;
vector<vector<int> > seg,lazy;
inline void rd( int &n ) 
{
	n=0;
	int ch=getchar_unlocked();int sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}

	while(  ch >= '0' && ch <= '9' )
	        n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
	n=n*sign;
} 
inline void shift(int t,int id,int fs,int ls)
{
	if(!lazy[t][id])return;
	seg[t][id]+=lazy[t][id]*(ls-fs+1);
	if(fs!=ls)
	{
		lazy[t][id*2]+=lazy[t][id];
		lazy[t][id*2+1]+=lazy[t][id];
	}
	lazy[t][id]=0;
}
void add(int t,int l,int r,int id,int fs,int ls)
{
	int md=(fs+ls)/2;
	shift(t,id,fs,ls);
	if(ls<x||fs>y)return;
	if(fs>=x&&ls<=y)
	{
		lazy[t][id]++;
		shift(t,id,fs,ls);
		return;
	}
	add(t,l,r,id*2,fs,md);
	add(t,l,r,id*2+1,md+1,ls);
	seg[t][id]=seg[t][id*2]+seg[t][id*2+1];
	// if(l!=r)seg[t][id]=seg[t*2][id]+seg[t*2+1][id];
}
void ADD(int id,int fs,int ls)
{
	int md=(fs+ls)/2;
	if(fs==ls)
	{
		add(id,fs,ls,1,0,c);
		return;
	}
	if(toAdd<=md) ADD(id*2,fs,md);
	else ADD(id*2+1,md+1,ls);
	add(id,fs,ls,1,0,c);
}
void sum(int t,int l,int r,int id,int fs,int ls)
{
	int md=(fs+ls)/2;
	shift(t,id,fs,ls);
	if(ls<x||fs>y)return;
	if(fs>=x&&ls<=y)
	{
		sm+=seg[t][id];
		return;
	}
	sum(t,l,r,id*2,fs,md);
	sum(t,l,r,id*2+1,md+1,ls);
}
void SUM(int id,int fs,int ls)
{
	int md=(fs+ls)/2;
	if(ls<L||fs>R) return;
	if(fs>=L&&ls<=R){sum(id,fs,ls,1,0,c);return;}
	SUM(id*2,fs,md);
	SUM(id*2+1,md+1,ls);
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,q,i,j,k,Q,ch,ax,ay,bx,by;
	rd(n);rd(q);rd(r);rd(c);
	seg.resize((r+1)*4+5);
	lazy.resize((r+1)*4+5);
	k=1;
	while(k<=(c+1)*2)k*=2;
	for(i=0;i<seg.size();i++)
		seg[i].resize(k+5),lazy[i].resize(k+5);
	Q=n+q;
	while(Q--)
	{
		rd(ch);
		if(ch==1)
		{
			// scanf("%d %d",&toAdd,&y);
			rd(toAdd);rd(y);
			x=0;
			ADD(1,0,r);
		}
		else
		{
			// scanf("%d %d %d %d",&L,&x,&R,&y);
			rd(L);rd(x);rd(R);rd(y);sm=0;x++;
			SUM(1,0,r);
			printf("%lld\n",sm);
		}
	}
}