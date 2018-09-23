#include<bits/stdc++.h>
#define MI (1ll<<62ll)
using namespace std;
long long n,L,x,a[135],tma[135],all=0,jum[135][135],sm=0,fk=0;
vector<pair<long long,long long> > s[135];
// vector<long long> v;
long long dp(long long idx,long long qt)
{
	if(jum[idx][qt]>=0)return jum[idx][qt];
	long long sm=1,i;
	for(i=0;i<s[idx].size();i++)
	{
		if(s[idx][i].X>a[idx])
			sm+=dp(s[idx][i].Y,qt);
		else if(qt)
			sm+=dp(s[idx][i].Y,qt-1);
		sm=min(sm,MI);
	}
	return jum[idx][qt]=sm;
}
void find(long long idx,long long qt)
{
	long long i,j;
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
		else continue;
		if(sm+j<all)
			sm+=j;
		else
			break;
	}
	tma[idx]=s[idx][i].Y;
	if(s[idx][i].X>a[idx])
		find(s[idx][i].Y,qt);
	else if(qt)
		find(s[idx][i].Y,qt-1);
}
int main()
{
	long long i,j,k;
	scanf("%lld %lld %lld",&n,&L,&x);
	a[0]=-1;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<=n;j++)
			s[i].emplace_back(a[j],j);
		sort(s[i].begin(),s[i].end());
	}
	memset(jum,-1,sizeof jum);
	dp(0,L);
	for(i=x;i<=x;i++)
	{
		memset(tma,0,sizeof tma);
		all=i+2;sm=0;fk=0;
		j=dp(0,L);
		if(i>j)
		{
			printf("-1\n");
			return 0;
		}
		find(0,L);
		k=0;
		while(tma[k])
		{
			printf("%lld ",a[tma[k]]);
			k=tma[k];
		}
		printf("\n");
	}
}