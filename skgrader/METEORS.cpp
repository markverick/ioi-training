#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MI 1000000000
#define EB emplace_back
using namespace std;
int n,m,fs[300135],ls[300135],l[300135],r[300135],out[300135],w[300135],target[300135],ownr[300135],x,y,val;
vector<int> v[300135],chd[300135];
long long seg[1200135],sm;
inline void update(int id,int fs,int ls)
{
	int md=(fs+ls)/2;
	if(fs==ls)
	{
		seg[id]+=val;
		return;
	}
	if(x<=md) update(id*2,fs,md);
	else update(id*2+1,md+1,ls);
	seg[id]=seg[id*2]+seg[id*2+1];
}
inline void sum(int idx,int fs,int ls)
{
	int md=(fs+ls)/2;
	if(ls<x||fs>y) return;
	if(fs>=x&&ls<=y)
	{
		sm+=seg[idx];
		return;
	}
	sum(idx*2,fs,md);
	sum(idx*2+1,md+1,ls);
}
void add(int l,int r,int w)
{
	x=l;val=w;
	update(1,1,m+1);
	x=r+1;val=-w;
	update(1,1,m+1);
}
int main()
{
	int i,j,k,kk,q,md,kb;
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;i++)
		scanf("%d",&ownr[i]),chd[ownr[i]].emplace_back(i);
	for(i=1;i<=n;i++)
		scanf("%d",&target[i]),out[i]=MI;
	scanf("%d",&q);
	for(i=1;i<=q;i++)
	{
		scanf("%d %d %d",&l[i],&r[i],&w[i]);
	}
	for(i=1;i<=n;i++)
		fs[i]=1,ls[i]=q;
	while(i)
	{
		i=0;
		for(j=0;j<=1200100;j++) seg[j]=0;
		for(j=1;j<=n;j++)
		{
			md=(fs[j]+ls[j])/2;
			if(fs[j]>ls[j])
				continue;
			i=1;
			v[md].emplace_back(j);
		}
		for(j=1;j<=q;j++)
		{
			if(l[j]<=r[j])
				add(l[j],r[j],w[j]);
			else
			{
				add(l[j],m,w[j]);
				add(1,r[j],w[j]);
			}
			x=1;
			// for(y=1;y<=m+1;y++)
			// {
			// 	printf("%d ",sum(1,1,m+1));
			// }
			// printf("\n");
			while(v[j].size())
			{
				sm=0;x=1;
				kb=v[j].back();
				for(kk=0;kk<chd[kb].size();kk++)
				{
					y=chd[kb][kk];
					sum(1,1,m+1);
					if(sm>=(long long)target[kb]) break;
				}
				// printf("%d <- %d -> %d : %d < %d [%d]\n",fs[kb],j,ls[kb],sm,target[kb],kb);
				if(sm>=(long long)target[kb])
					ls[kb]=j-1,out[kb]=min(out[kb],j);
				else
					fs[kb]=j+1;
				v[j].pop_back();
			}
		}
		// for(j=1;j<=n;j++)
		// {
		// 	printf("%d %d\n",fs[j],ls[j]);
		// }
		// printf("\n");
	}
	for(i=1;i<=n;i++)
	{
		if(out[i]>=MI)
			printf("NIE\n");
		else
			printf("%d\n",out[i]);
	}
}