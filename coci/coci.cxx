#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
bool cmp(pair<pair<int,int>,int> a,pair<pair<int,int> ,int> b)
{
	return a.X>b.X;
}
pair<pair<int,int> ,int> p[500135];
int MC[500135],ft[1135],MN[500135];
vector<int> vx[700],vy[700],va[700],vb[700];
void add(int x,int val)
{
	x+=2;
	while(x<=700)
	{
		ft[x]+=val;
		x+=x&-x;
	}
}
int sum(int x)
{
	x+=2;
	int sm=0;
	while(x>0)
	{
		sm+=ft[x];
		x-=x&-x;
	}
	return sm;
}
stack<int> st;
int main()
{
	// freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d %d",&p[i].X.X,&p[i].X.Y);
		p[i].Y=i;
	}
	sort(&p[1],&p[n+1]);
	p[n+1].X.X=-1;
	for(i=n;i>=1;i--)
	{
		// printf("%d %d\n",p[i].X.X,p[i+1].X.X);
		if(p[i].X.X!=p[i+1].X.X)
		{
			while(!st.empty())
			{
				add(st.top(),1);
				st.pop();
			}
		}
		MC[p[i].Y]=sum(677)-sum(p[i].X.Y)+1;
		// printf("!%d %d\n",sum(p[i].X.Y),st.size());
		st.emplace(p[i].X.Y);
	}
	p[0].X.X=-1;
	while(!st.empty())st.pop();
	memset(ft,0,sizeof ft);
	for(i=1;i<=n;i++)
	{
		// printf("%d %d\n",p[i].X.X,p[i+1].X.X);
		if(p[i].X.Y==650)
			va[p[i].X.X].emplace_back(p[i].Y);
		if(p[i].X.Y==0)
			vx[p[i].X.X].emplace_back(p[i].Y);
		if(p[i].X.X==650)
			vb[p[i].X.Y].emplace_back(p[i].Y);
		if(p[i].X.X==0)
			vy[p[i].X.Y].emplace_back(p[i].Y);
		if(p[i].X.X!=p[i-1].X.X)
		{
			// printf("[%d]\n",st.size());
			while(!st.empty())
			{
				add(st.top(),1);
				st.pop();
			}
		}
		MN[p[i].Y]=sum(p[i].X.Y-1);
		st.emplace(p[i].X.Y);
	}
	for(i=0;i<=650;i++)
	{
		for(j=0;j<va[i].size();j++)
			MN[va[i][j]]+=vx[i].size();
		for(j=0;j<vb[i].size();j++)
			MN[vb[i][j]]+=vy[i].size();
	}
	for(i=1;i<=n;i++)
		printf("%d %d\n",MC[i],n-MN[i]);
}