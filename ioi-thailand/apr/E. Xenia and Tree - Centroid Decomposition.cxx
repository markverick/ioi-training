#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int sz[100135],ste[100135],n,h[100135],p[20][100135],pc[100135],dc[20][100135],d[100135];
vector<int> adj[100135],adc[100135];
void dep(int idx,int pa,int hi)
{
	h[idx]=hi;
	int i,j;
	for(i=0;i<adj[idx].size();i++)
	{
		if(adj[idx][i]==pa)continue;
		p[0][adj[idx][i]]=idx;
		for(j=1;j<=17;j++)
			p[j][adj[idx][i]]=p[j-1][p[j-1][adj[idx][i]]];
		dep(adj[idx][i],idx,hi+1);
	}
}
void dfs(int idx,int p)
{
	int i;
	sz[idx]=1;
	for(i=0;i<adj[idx].size();i++)
	{
		if(adj[idx][i]==p||ste[adj[idx][i]])continue;
		dfs(adj[idx][i],idx);
		sz[idx]+=sz[adj[idx][i]];
	}
}
int cd(int idx,int p)
{
	int cen=idx,i,fk=1,size;
	ste[p]=1;
	dfs(idx,p);
	size=sz[idx];
	while(fk)
	{
		fk=0;
		for(i=0;i<adj[cen].size();i++)
		{
			if(ste[adj[cen][i]]==0&&sz[adj[cen][i]]<sz[cen]&&sz[adj[cen][i]]>size/2)
			{
				fk=1;cen=adj[cen][i];
				break;
			}
		}
	}
	for(i=0;i<adj[cen].size();i++)
	{
		if(ste[adj[cen][i]])continue;
		adc[cen].emplace_back(cd(adj[cen][i],cen));
	}
	pc[cen]=p;
	return cen;
}
int dist(int x,int y)
{
	if(h[x]<h[y])swap(x,y);
	int sm=0,i;
	for(i=17;i>=0;i--)
	{
		if(h[p[i][x]]>=h[y])
			x=p[i][x],sm+=(1<<i);
	}
	if(x==y)
		return sm;
	for(i=17;i>=0;i--)
	{
		if(p[i][x]!=p[i][y])
			x=p[i][x],y=p[i][y],sm+=(1<<i)*2;
	}
	return sm+2;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int m,i,j,k,a,b,mn,ch;
	scanf("%d %d",&n,&m);
	for(i=1;i<n;i++)
	{
		scanf("%d %d",&a,&b);
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	cd(1,0);
	dep(1,0,1);
	for(i=1;i<=n;i++)
	{
		d[i]=MI;
		k=i;
		dc[0][i]=0;
		for(j=1;j<=17;j++)
		{
			k=pc[k];
			if(!k)break;
			dc[j][i]=dist(i,k);
		}
	}
	// for(i=1;i<=n;i++)
	// {
	// 	// printf("%d\n",h[i]);
	// 	printf("[%d] ",i);
	// 	// k=pc[i];
	// 	// for(j=1;j<=5;j++,k=pc[k])
	// 	// 	printf("To %d use %d | ",k,dc[j][i]);
	// 	for(j=0;j<adc[i].size();j++)
	// 		printf("%d ",adc[i][j]);
	// 	printf("\n");
	// }
	for(i=0;i<=m;i++)
	{
		if(i==0)ch=1,a=1;
		else scanf("%d %d",&ch,&a);
		mn=MI;
		if(ch==1)
		{
			k=pc[a];
			d[a]=0;
			for(j=1;k&&j<=17;j++,k=pc[k])
			{
				d[k]=min(d[k],dc[j][a]);
			}
		}
		else
		{
			k=a;
			for(j=0;k&&j<=17;j++,k=pc[k])
			{
				// printf("!%d %d %d\n",k,d[k],dc[j][a]);
				mn=min(mn,d[k]+dc[j][a]);
			}
			printf("%d\n",mn);
		}
	}
}