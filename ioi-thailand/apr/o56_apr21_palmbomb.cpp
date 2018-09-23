#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
pair<int,int> a[50005];
vector<int> vec[100005];
vector<pair<int,int> > gogo[200005];
int nw[50005],hsh[200005];
int res,pos,val,tob[200005],xx,yy;
int seg[800005];
void add(int l,int r,int idx)
{
	if(l==r)
	{
		seg[idx]=val;
		return;
	}
	int mid=(l+r)/2;
	if(pos<=mid) add(l,mid,idx*2);
	else add(mid+1,r,idx*2+1);
	seg[idx]=max(seg[idx*2],seg[idx*2+1]);
}
void sum(int l,int r,int idx)
{
	if(xx<=l&&r<=yy) 
	{
		res=max(res,seg[idx]);
		return;
	}
	if(xx>r||yy<l) return;
	int mid=(l+r)/2;
	sum(l,mid,idx*2);
	sum(mid+1,r,idx*2+1);
}
int main()
{
	int n,q,i,j,y,x,op,sz,l,r,mid,ans;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].Y,&a[i].X);
		a[i].Y+=a[i].X;
		nw[i]=i;
		hsh[i]=i;
	}
	for(i=1;i<=q;i++)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d%d",&x,&y);
			hsh[n+i]=x;
			gogo[a[x].X].emplace_back(nw[x],n+i-1);
			gogo[a[x].Y+1].emplace_back(nw[x],0);
			a[x].Y-=a[x].X-y;
			a[x].X=y;
			nw[x]=n+i;
		}
		else
		{
			scanf("%d",&x);
			vec[x].push_back(n+i);
		}
	}
	for(i=1;i<=n;i++)
	{
		gogo[a[i].X].emplace_back(nw[i],n+q+1);
		gogo[a[i].Y+1].emplace_back(nw[i],0);
	}
	sz=n+q;
	for(i=0;i<=100000;i++)
	{
		for(j=0;j<gogo[i].size();j++)
		{
			pos=gogo[i][j].X;
			val=gogo[i][j].Y;
			add(1,sz,1);
		}
		for(j=0;j<vec[i].size();j++)
		{
			l=1;
			r=vec[i][j]-1;
			while(l<=r)
			{
				mid=(l+r)/2;
				xx=mid;
				yy=vec[i][j];
				res=0;
				sum(1,sz,1);
				if(res>=vec[i][j])
				{
					tob[vec[i][j]]=mid;
					l=mid+1;
				}
				else r=mid-1;
			}
		}
	}
	for(i=1;i<=n;i++) nw[i]=0;
	for(i=1;i<=q;i++)
		if(hsh[tob[n+i]]!=0)
			nw[hsh[tob[n+i]]]++;
	for(i=1;i<=n;i++) printf("%d\n",nw[i]);

}