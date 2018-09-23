#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
vector<tuple<int,int,int> > adj[100135];
int hsh[200135],head,n,m,all;
vector<int> vec;
int euler(int idx,int d,int ec)
{
	// printf("%d %d %d\n",idx,d,ec);
	if(ec==m)
	{
		if(d*2<=all)
			return 1;
		return 0;
	}
	int i,v,w,e;
	for(i=0;i<adj[idx].size();i++)
	{
		tie(v,w,e)=adj[idx][i];
		if(hsh[e])continue;
		hsh[e]=1;
		if(euler(v,d+max(w,0),ec+1))
		{
			if(w>=0)vec.emplace_back(e);
			return 1;
		}
	}
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,a,b,c;
	srand(135);
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		all+=c;
		adj[a].emplace_back(b,-c-1,i);
		adj[b].emplace_back(a,c,i);
	}
	head=(rand()%n)+1;
	while(!euler(head,0,0))
	{
		// printf("!");
		// system("pause");
		memset(hsh,0,sizeof hsh);
		vec.clear();
		head=(rand()%n)+1;
		for(i=1;i<=n;i++)
		{
			for(j=0;j<adj[i].size();j++)
			{
				swap(adj[i][j],adj[i][j+rand()%(adj[i].size()-j)]);
			}
		}
	}
	printf("%d\n",vec.size());
	for(i=0;i<vec.size();i++)
		printf("%d\n",vec[i]);
}