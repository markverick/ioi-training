#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int n,m,t=1,ste[100135],low[100135],disc[100135],p[100135],out[100135];
vector<int> adj[100135],ad[100135];
void dfs(int idx)
{
	int i;
	ste[idx]=1;
	disc[idx]=low[idx]=t;
	for(i=0;i<adj[idx].size();i++)
	{
		if(p[idx]==adj[idx][i])continue;
		if(ste[adj[idx][i]]==0)
		{
			t++;
			p[adj[idx][i]]=idx;
			ad[idx].emplace_back(adj[idx][i]);
			dfs(adj[idx][i]);
			low[idx]=min(low[idx],low[adj[idx][i]]);
		}
		else if(ste[adj[idx][i]]==1)
		{
			low[idx]=min(low[idx],disc[adj[idx][i]]);
		}
	}
	t++;
	out[idx]=t;
	ste[idx]=2;
}
int isChild(int a,int b)
{
	if(disc[a]>=disc[b]&&disc[a]<=out[b])
		return 1;
	return 0;
}
int nextChild(int a,int b)
{
	int fs=0,md,ls=ad[b].size()-1;
	while(fs<=ls)
	{
		md=(fs+ls)/2;
		if(disc[a]>=disc[ad[b][md]]&&disc[a]<=out[ad[b][md]])
		{
			return ad[b][md];
		}
		else if(disc[a]<disc[ad[b][md]])
			ls=md-1;
		else
			fs=md+1;
	}
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,a,b,c,d,Q,ch,A,B;
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d %d",&a,&b);
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	for(i=1;i<=n;i++)
	{
		if(ste[i]>0)continue;
		dfs(i);
	}
	// for(i=1;i<=n;i++)
	// {
	// 	printf("[%d] %d <--> %d : Lowest = %d\n",i,disc[i],out[i],low[i]);
	// }
	scanf("%d",&Q);
	while(Q--)
	{
		scanf("%d",&ch);
		if(ch==1)
		{
			scanf("%d %d %d %d",&a,&b,&c,&d);
			if(p[c]!=d&&p[d]!=c)
			{
				printf("yes\n");
			}
			else
			{
				if(p[c]==d)swap(c,d);
				// printf("[%d] %d <-> %d, %d & %d\n",low[d],disc[low[d]],out[low[d]],disc[a],disc[b]);
				if((isChild(a,d)^isChild(b,d))==0)
					printf("yes\n");
				else
				{
					if(low[d]>=disc[d]&&low[d]<=out[d])
						printf("no\n");
					else
						printf("yes\n");
				}
			}
		}
		else
		{
			scanf("%d %d %d",&a,&b,&c);
			if(!isChild(a,c)&&!isChild(b,c))
			{
				printf("yes\n");
			}
			else if(isChild(a,c)&&isChild(b,c))
			{
				if(nextChild(a,c)==nextChild(b,c))
					printf("yes\n"); //Same Child
				else
				{
					//Different Child
					A=nextChild(a,c);B=nextChild(b,c);
					if(low[A]>=disc[c]&&low[A]<=out[c]||low[B]>=disc[c]&&low[B]<=out[c])
						printf("no\n"); //from up
					else
						printf("yes\n"); 
				}
			}
			else
			{
				if(isChild(b,c))
					swap(a,b);
				d=nextChild(a,c);
				if(low[d]<disc[c])
					printf("yes\n"); //Can Cross
				else
					printf("no\n"); //Cannot Cross
			}
		}
	}
}