#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[300135],jum[300135][3],w,n,m;
pair<int,int> p[300135],tma[300135][3];
int dp(int idx,int isF)
{
	if(jum[idx][isF]>=0)return jum[idx][isF];
	int idy,lst;
	if(isF==1)
	{
		idy=lower_bound(&a[1],&a[m+1],a[idx]+w)-&a[0];
		lst=a[idx]+w-1;
	}
	else
	{
		idy=idx+1;
		lst=a[idx];
	}
	if(idy>m)return 0;
	// printf("[%d] %d %d\n",isF,a[idy]-lst,w);
	int x=dp(idy,0)+a[idy]-lst,y=dp(idy,1)+w;
	if(x<=y)
	{
		tma[idx][isF]=MP(idy,0);
		return jum[idx][isF]=x;
	}
	else
	{
		tma[idx][isF]=MP(idy,1);
		return jum[idx][isF]=y;
	}
}
pair<int,int> out[300135];
int main()
{
	// freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k;
	memset(jum,-1,sizeof jum);
	scanf("%d %d %d",&n,&w,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d",&a[i]);
		p[i]=MP(a[i],i);
	}
	sort(&a[1],&a[m+1]);
	sort(&p[1],&p[m+1]);
	
	printf("%d\n",w+dp(1,1));
	int idx=1,isF=1,idy,nxF;
	out[p[1].Y]=MP(a[1],a[1]+w-1);
	while(idx>0)
	{
		tie(idy,nxF)=tma[idx][isF];
		if(idy==0)
		{
			for(i=idx+1;i<=m;i++)
				out[p[i].Y]=MP(a[idx],a[idx]+w-1);
			break;
		}
		// printf("%d %d -> %d %d\n",idx,isF,idy,nxF);
		if(isF==1)
		{
			// out[p[idx].Y]=MP(a[idx],a[idx]+w-1);
			for(i=idx+1;i<idy;i++)
			{
				out[p[i].Y]=MP(a[idx],a[idx]+w-1);
			}
		}
		if(nxF==1)
		{
			out[p[idy].Y]=MP(a[idy],a[idy]+w-1);
		}
		else
			out[p[idy].Y]=MP(a[idy]-w+1,a[idy]);
		idx=idy;isF=nxF;
	}
	for(i=1;i<=m;i++)
	{
		if(out[i].X<1)
			out[i].Y+=1-out[i].X,out[i].X+=1-out[i].X;
		if(out[i].Y>n)
			out[i].X-=out[i].Y-n,out[i].Y-=out[i].Y-n;
		printf("%d %d\n",out[i].X,out[i].Y);
	}
}