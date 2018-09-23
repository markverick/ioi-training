#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int adj[500135],hsh[500135],dead[500135];
queue<int> q;
int dfs(int idx)
{
	if(dead[adj[idx]])
		return 1;
	dead[idx]=1;
	return dfs(adj[idx])+1;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,mob,cot=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&adj[i]);
		hsh[adj[i]]++;
	}
	for(i=1;i<=n;i++)
	{
		if(hsh[i]==0)
			q.emplace(i);
	}
	while(!q.empty())
	{
		mob=q.front();q.pop();
		cot++;
		if(!dead[adj[mob]])
		{
			hsh[adj[adj[mob]]]--;
			if(hsh[adj[adj[mob]]]==0)
			{
				q.emplace(adj[adj[mob]]);
			}
			dead[adj[mob]]=1;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(!dead[i])
		{
			cot+=dfs(i)/2;
		}
	}
	printf("%d",cot);
}