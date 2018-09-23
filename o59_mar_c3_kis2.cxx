#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int n,L,x,a[135],tma[135],all=0,jum[135][135],sm=0,fk=0;
vector<pair<int,int> > s[135];
// vector<int> v;
int dp(int idx,int qt)
{
	if(jum[idx][qt]>=0)return jum[idx][qt];
	int sm=1,i;
	// for(i=0;i<v.size();i++)
	// 	printf("%d ",v[i]);
	// printf("\n");
	// printf("\t%d %d %d\n",idx,qt,bd);
	for(i=0;i<s[idx].size();i++)
	{
		// v.emplace_back(s[idx][i].X);
		if(s[idx][i].X>a[idx])
			sm+=dp(s[idx][i].Y,qt);
		else if(qt)
			sm+=dp(s[idx][i].Y,qt-1);
		// v.pop_back();
	}
	return jum[idx][qt]=sm;
}
void find(int idx,int qt)
{
	// printf("\t%d %d %d/%d\n",idx,qt,sm,all);
	int i,j;
	sm++;
	if(sm==all)
		return;
	if(s[idx].empty())return;
	for(i=0;i<s[idx].size();i++)
	{
		if(s[idx][i].X>a[idx])
			j=dp(s[idx][i].Y,qt);
		else if(qt)
			j=dp(s[idx][i].Y,qt-1);
		// printf(">%d ",j);
		if(sm+j<all)
			sm+=j;
		else
			break;
	}
	// printf("\n");
	// if(sm==all)
	// 	return;
	// if(sm==all)
	// 	return;
	tma[idx]=s[idx][i].Y;
	 // printf("tma[%d]=%d;\n",idx,s[idx][i].Y);
	if(s[idx][i].X>a[idx])
		find(s[idx][i].Y,qt);
	else if(qt)
		find(s[idx][i].Y,qt-1);
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k;
	scanf("%d %d %d",&n,&L,&x);
	a[0]=-1;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<=n;j++)
			s[i].emplace_back(a[j],j);
		sort(s[i].begin(),s[i].end());
	}
	memset(jum,-1,sizeof jum);
	memset(tma,0,sizeof tma);
	dp(0,L);
	// for(i=0;i<=n;i++)
	// 	printf("%d ",dp(i,L));
	// printf("\n");
	all=x+2;sm=0;fk=0;
	j=dp(0,L);
	if(x>j)
	{
		printf("-1\n");
		return 0;
	}
	find(0,L);
	k=0;
	// for(j=0;j<=n;j++)
	// 	printf("%d ",tma[j]);
	// printf("\n");
	while(tma[k])
	{
		printf("%d ",a[tma[k]]);
		k=tma[k];
	}
	printf("\n");
}