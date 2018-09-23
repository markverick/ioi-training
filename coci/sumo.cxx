#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[300135],b[300135],ste[100135];
vector<int> adj[300135];
int dfs(int idx)
{
	int i,mn=1;
	for(i=0;i<adj[idx].size();i++)
	{
		if(ste[adj[idx][i]]==-1)
		{
			ste[adj[idx][i]]=1-ste[idx];
			mn=min(mn,dfs(adj[idx][i]));
		}
		else if(ste[adj[idx][i]]==ste[idx])
		{
			return 0;
		}
	}
	return mn;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,m,i,j,k,fs=0,md,ls,mc=0,fk;
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d %d",&a[i],&b[i]);
	}
	fs=0;ls=m;
	while(fs<=ls)
	{
		memset(ste,-1,sizeof ste);
		md=(fs+ls)/2;
		for(i=1;i<=n;i++)
			adj[i].clear();
		for(i=1;i<=md;i++)
		{
			adj[a[i]].emplace_back(b[i]);
			adj[b[i]].emplace_back(a[i]);
		}
		fk=0;
		for(i=1;i<=n;i++)
		{
			if(ste[i]>=0)continue;
			ste[i]=0;
			if(!dfs(i))
			{
				fk=1;
				break;
			}
		}
		if(fk==0)
		{
			mc=max(mc,md);
			fs=md+1;
		}
		else
		{
			ls=md-1;
		}
	}
	printf("%d",mc+1);
}