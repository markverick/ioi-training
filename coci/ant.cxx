#include<bits/stdc++.h>
#define MI 2000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
vector<tuple<int,int,int> > adj[1135];
int req[1135];
inline double sq(double x)
{
	return x*x;
}
int dfs(int idx,double water,int p)
{
	int i,a,b,x,t,mc=0,fk=0;
	for(i=0;i<adj[idx].size();i++)
	{
		tie(b,x,t)=adj[idx][i];
		if(b==p)continue;
		fk=1;
		if(t&&water*x/100>1)
			mc=max(mc,dfs(b,sq(water*x/100),idx));
		else
			mc=max(mc,dfs(b,water*x/100,idx));
	}
	if(fk==0)
	{
		return water<req[idx];
	}
	return mc;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k=100,a,b,x,t;
	double fs,md,ls,mn=MI;
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		scanf("%d %d %d %d",&a,&b,&x,&t);
		adj[a].emplace_back(b,x,t);
		adj[b].emplace_back(a,x,t);
	}
	for(i=1;i<=n;i++)
		scanf("%d",&req[i]);
	fs=0;ls=MI;
	while(k--)
	{
		md=(fs+ls)/2;
		// printf("%f %f %f\n",fs,md,ls);
		if(dfs(1,md,0))
			fs=md;
		else
		{
			ls=md;
			mn=min(mn,md);
		}
	}
	printf("%f",mn);
}