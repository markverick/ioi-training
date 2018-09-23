#include<bits/stdc++.h>
using namespace std;

int a[200135],seg[200135],x,y;
void build(int id,int fs,int ls)
{
	int md=(fs+ls)/2;
	if(fs==ls)
	{
		seg[id]=a[fs];
		return;
	}
	build(id*2,fs,md);
	build(id*2+1,md+1,ls);
	seg[id]=max(seg[id*2],seg[id*2+1]);
}
int query(int id,int fs,int ls)
{
	int md=(fs+ls)/2;
	if(ls<x||fs>y)
		return -20000;
	if(fs>=x&&ls<=y)
		return seg[id];
	return max(query(id*2,fs,md),query(id*2+1,md+1,ls));
}
int main()
{
	int i,j,k,n,m;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	build(1,1,n);
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d %d",&x,&y);
		printf("%d\n",query(1,1,n));
	}
}