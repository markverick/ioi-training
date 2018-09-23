#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int w[200135],ste[200135];
vector<int> v,adj[200135];
int dfs(int idx,int p)
{
	// printf("%d %d\n",idx,p);
	ste[idx]=1;
	int i,j;
	for(i=0;i<adj[idx].size();i++)
	{
		if(adj[idx][i]==p)continue;
		if(ste[adj[idx][i]])
		{
			v.emplace_back(idx);
			return adj[idx][i];
		}
		j=dfs(adj[idx][i],idx);
		if(j)
		{
			v.emplace_back(idx);
			if(j==idx)return 0;
			return j;
		}
	}
	return 0;
}
int dp(int idx,int p,int used)
{
	int i,mc=0,smy=0,smn=0;
	vector<int> yup,nope;
	for(i=0;i<adj[idx].size();i++)
	{
		if(adj[idx][i]==p)continue;
		yup.emplace_back(dp(adj[idx][i],idx,1));
		nope.emplace_back(dp(adj[idx][i],idx,0));
	}
	sort(yup.begin(),yup.end());
	sort(nope.begin(),nope.end());
	for(i=yup.end()-1;i>=yup.end()-3+used;i--)
		smy+=yup[i];
	for(i=nope.end()-1;i>=nope.end()-3+used;i--)
		smy+=yup[i];
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,a,b;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&w[i]);
	for(i=1;i<=n;i++)
		scanf("%d %d",&a,&b),a++,b++,adj[a].emplace_back(b),adj[b].emplace_back(a);
	dfs(1,0);
	for(i=0;i<v.size();i++)
		printf("%d ",v[i]-1);
}