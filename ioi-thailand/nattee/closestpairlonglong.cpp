#include<bits/stdc++.h>
using namespace std;
#define MI 1000000000000000000ll
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
pair<long long,long long> p[100135];
long long dp(long long fs,long long ls)
{
	if(fs==ls)
		return MI;
	if(fs+1==ls)
		return (p[ls].X-p[fs].X)*(p[ls].X-p[fs].X)+(p[ls].Y-p[fs].Y)*(p[ls].Y-p[fs].Y);
	long long md=(fs+ls)/2,mn,i,j,up,dw,Min;
	// printf("%lld <- %lld -> %lld\n",fs,md,ls);
	vector<pair<long long,long long> > L,R;
	pair<long long,long long> il,ir;
	mn=min(dp(fs,md),dp(md+1,ls));
	Min=mn;
	for(i=fs;i<=md;i++)
	{
		if((p[md].X-p[i].X)*(p[md].X-p[i].X)<mn)
			L.emplace_back(p[i].Y,i);
	}
	for(i=md+1;i<=ls;i++)
	{
		if((p[i].X-p[md].X)*(p[i].X-p[md].X)<mn)
			R.emplace_back(p[i].Y,i);
	}
	sort(L.begin(),L.end());
	sort(R.begin(),R.end());
	for(i=0;i<L.size();i++)
	{
		il=p[L[i].Y];
		up=distance(R.begin(),lower_bound(R.begin(),R.end(),MP(L[i].X-md*2,0ll)));
		dw=distance(R.begin(),upper_bound(R.begin(),R.end(),MP(L[i].X+md*2,MI)))-1;
		for(j=up;j<=dw;j++)
		{
			ir=p[R[j].Y];
			Min=min(Min,(il.X-ir.X)*(il.X-ir.X)+(il.Y-ir.Y)*(il.Y-ir.Y));
		}
	}
	return Min;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	long long n,i,j,k;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld %lld",&p[i].X,&p[i].Y);
	}
	sort(&p[1],&p[n+1]);
	printf("%lld\n",dp(1,n));
}