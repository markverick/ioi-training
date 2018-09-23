#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;

pair<int,int> mn[1000135],mc[1000135];
int qs[1135][1135],a[1135][1135],hsh[1000135],ha[1000135];
pair<int,int> MAX(pair<int,int> a,pair<int,int> b)
{
	return MP(max(a.X,b.X),max(a.Y,b.Y));
}
pair<int,int> MIN(pair<int,int> a,pair<int,int> b)
{
	return MP(min(a.X,b.X),min(a.Y,b.Y));
}
int main()
{
	freopen("art.out","w",stdout);
	freopen("art.in","r",stdin);
	int n,i,j,k,sm=0,all=0;
	scanf("%d",&n);
	for(i=0;i<=n*n;i++)
		mn[i]=MP(n+1,n+1),mc[i]=MP(0,0);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j])all++;
			mc[a[i][j]]=MAX(mc[a[i][j]],MP(i,j));
			mn[a[i][j]]=MIN(mn[a[i][j]],MP(i,j));
			ha[a[i][j]]++;
		}
	}
	for(i=1;i<=n*n;i++)
	{	
		if(mn[i].X==n+1)continue;
		qs[mn[i].X][mn[i].Y]++;
		qs[mn[i].X][mc[i].Y+1]--;
		qs[mc[i].X+1][mn[i].Y]--;
		qs[mc[i].X+1][mc[i].Y+1]++;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			qs[i][j]+=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1];
			// printf("%d ",qs[i][j]);
			if(qs[i][j]>1)
				hsh[a[i][j]]++;
		}
		// printf("\n");
	}
	for(i=1;i<=n*n;i++)
	{
		if(hsh[i]==0)
			sm++;
	}
	all=0;
	for(i=1;i<=n;i++)
	{
		if(ha[i])all++;
	}
	printf("%d\n",sm-(all==1));
}