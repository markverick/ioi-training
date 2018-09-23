#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int w[100135],pa[100135],n;
class mx
{
public:
	pair<int,int> h,l;
	mx()
	{
		h={-MI,-MI};
		l={-MI,-MI};
	}
	void insert(int w,int id)
	{
		if(w>h.X)
		{
			swap(h,l);
			h=MP(w,id);
		}
		else if(w<l.X)
			l=MP(w,id);
	}
	void clear()
	{
		h={-MI,-MI},l={-MI,-MI};
	}
}m1[100135],m2[100135];
vector<int> adj[100135];
void dfs(int idx,int p)
{
	int i;
	for(i=0;i<adj[idx].size();i++)
	{
		if(adj[idx][i]==p)continue;
		pa[adj[idx][i]]=idx;
		dfs(adj[idx][i],idx);
		m1[idx].insert(w[adj[idx][i]],adj[idx][i]);
		m2[idx].insert(m1[adj[idx][i]].h.X,adj[idx][i]);
	}
}
int main()
{
	// freopen("out.txt","w",stdout);
	// freopen("in_sh.txt","r",stdin);
	int i,j,k,l,T,a,b;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",&w[i]),pa[i]=i,adj[i].clear(),m1[i].clear(),m2[i].clear();
		for(i=1;i<n;i++)
		{
			scanf("%d %d",&a,&b);
			adj[a].emplace_back(b);
			adj[b].emplace_back(a);
		}
		dfs(1,0);
		// for(i=1;i<=n;i++)
		// {
		// 	printf("Node %d\n",i);
		// 	printf("Hop 1 - Highest: (%d,%d), SecondHi: (%d,%d) \n",m1[i].h.X,m1[i].h.Y,m1[i].l.X,m1[i].l.Y);
		// 	printf("Hop 2 - Highest: (%d,%d), SecondHi: (%d,%d) \n",m2[i].h.X,m2[i].h.Y,m2[i].l.X,m2[i].l.Y);
		// }
		// return 0;
		int mc=-1;
		for(i=1;i<=n;i++)
		{
			j=i;k=0;
			l=i;
			while(j!=1)
			{
				j=pa[j];
				k++;
				if(k==3)
				{
					if(m1[j].h.Y==l)
						mc=max(mc,w[i]+m1[j].l.X);
					else
						mc=max(mc,w[i]+m1[j].h.X);
				}
				else if(k==2)
				{
					if(m2[j].h.Y==l)
						mc=max(mc,w[i]+m2[j].l.X);
					else
					{
						mc=max(mc,w[i]+m2[j].h.X);
					}
				}
				if(k==4)
				{
					mc=max(mc,w[i]+w[j]);
					break;
				}
				// printf("%d %d %d %d %d !%d\n",mc,i,j,l,k,m2[2].h.Y);
				l=j;
			}
		}
		printf("%d\n",mc);
	}
}