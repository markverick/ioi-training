#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100135];
int p[100135],h[100135],sp[100135][20];
void dfs(int idx,int lv)
{
	h[idx]=lv;
	for(int i=0;i<adj[idx].size();i++)
	{
		dfs(adj[idx][i],lv+1);
	}
}
int main()
{
	int T,t,i,j,k,n,a,b,Q;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		scanf("%d",&n);
		memset(p,0,sizeof p);
		memset(h,0,sizeof h);
		memset(sp,0,sizeof sp);
		for(i=1;i<=n;i++)
		{
			adj[i].clear();
			scanf("%d",&k);
			while(k--)
			{
				scanf("%d",&j);
				adj[i].emplace_back(j);
				p[j]=i;
			}
		}
		for(i=1;i<=n;i++)
		{
			if(!p[i])
				dfs(i,1);
			sp[i][0]=p[i];
		}
		//for(i=1;i<=n;i++)
		//	printf("%d\n",h[i]);
		for(i=1;i<=17;i++)
		{
			for(j=1;j<=n;j++)
				sp[j][i]=sp[sp[j][i-1]][i-1];
		}
		scanf("%d",&Q);
		printf("Case %d:\n",t);
		while(Q--)
		{
			scanf("%d %d",&a,&b);
			if(h[a]<h[b])swap(a,b);
			k=a;
			for(i=17;i>=0;i--)
			{
				if(h[sp[a][i]]>=h[b])
					a=sp[a][i];
			}
			//printf("[%d] = %d, [%d] = %d\n",a,h[a],b,h[b]);
			if(a==b)
			{
				printf("%d\n",a);
				continue;
			}
			for(i=17;i>=0;i--)
			{
				if(sp[a][i]!=sp[b][i])
					a=sp[a][i],b=sp[b][i];
			}
			printf("%d\n",p[a]);
		}
	}
}