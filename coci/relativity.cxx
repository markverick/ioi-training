#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
#define MI 1000000000
#define M 10007
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int seg[262244][22];//262144
int n,c,a[100135],b[100135],x;
inline void build(int id,int fs,int ls)
{
	int md=(fs+ls)/2,i,j;
	if(fs==ls)
	{
		seg[id][0]=b[fs];
		seg[id][1]=a[fs];
		return;
	}
	build(id*2,fs,md);
	build(id*2+1,md+1,ls);
	for(i=0;i<=c;i++)
	{
		for(j=0;j<=c;j++)
		{
			seg[id][min(c,i+j)]+=seg[id*2][i]*seg[id*2+1][j];
			seg[id][min(c,i+j)]%=M;
		}
	}
}
inline void update(int id,int fs,int ls)
{
	int md=(fs+ls)/2,i,j;
	if(fs==ls)
	{
		seg[id][0]=b[fs];
		seg[id][1]=a[fs];
		return;
	}
	if(x<=md)
		update(id*2,fs,md);
	else
		update(id*2+1,md+1,ls);
	for(i=0;i<=c;i++)
		seg[id][i]=0;
	for(i=0;i<=c;i++)
	{
		for(j=0;j<=c;j++)
		{
			seg[id][min(c,i+j)]+=seg[id*2][i]*seg[id*2+1][j];
			seg[id][min(c,i+j)]%=M;
		}
	}
}
int main()
{
	// freopen("out.txt","w",stdout);
	// freopen("in.txt","r",stdin);
	int i,j,k,Q;
	scanf("%d %d",&n,&c);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]),a[i]%=M;
	for(i=1;i<=n;i++)
		scanf("%d",&b[i]),b[i]%=M;
	build(1,1,n);
	scanf("%d",&Q);
	while(Q--)
	{
		scanf("%d",&x);
		scanf("%d %d",&a[x],&b[x]);a[x]%=M;b[x]%=M;
		update(1,1,n);
		printf("%d\n",seg[1][c]);
	}
}