#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int n,L,x,a[135],tma[135];
vector<pair<int,int> > s[135];
int dp(int idx,int qt,int bd)
{
	int sm=1,i;
	// printf("%d %d %d\n",idx,qt,bd);
	for(i=0;i<s[idx].size();i++)
	{
		if(bd-sm<0)
			break;
		tma[idx]=s[idx][i].Y;
		if(s[idx][i].X>a[idx])
			sm+=dp(s[idx][i].Y,qt,bd-sm);
		else if(qt)
			sm+=dp(s[idx][i].Y,qt-1,bd-sm);
	}
	return sm;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k;
	scanf("%d %d %d",&n,&L,&x);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
			s[i].emplace_back(a[j],j);
		sort(s[i].begin(),s[i].end());
	}
	for(i=1;i<=x+1;i++)
	{
		memset(tma,0,sizeof tma);
		a[0]=-1;
		dp(0,L,i);
		k=0;
		while(tma[k])
		{
			printf("%d ",a[tma[k]]);
			k=tma[k];
		}
		printf("\n");
	}
}