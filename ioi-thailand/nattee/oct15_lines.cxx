#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
pair<double,double> v[100135];
pair<double,int> c[100135];
int ar[100135],ft[100135],n;
void add(int idx,int val)
{
	while(idx<=n)
	{
		ft[idx]+=val;
		idx+=idx&-idx;
	}
}
int sum(int idx)
{
	int sm=0;
	while(idx>0)
	{
		sm+=ft[idx];
		idx-=idx&-idx;
	}
	return sm;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,L,R;
	double a,b;
	scanf("%d %d %d",&n,&L,&R);
	for(i=1;i<=n;i++)
	{
		scanf("%lf %lf",&a,&b);
		v[i]=MP(a*L+b,a*R+b);
		// printf("%f %f\n",v[i].X,v[i].Y);
	}
	sort(&v[1],&v[n+1]);
	for(i=1;i<=n;i++)
		c[i]=MP(v[i].Y,i);
	sort(&c[1],&c[n+1]);
	j=1;
	for(i=1;i<=n;i++)
		ar[c[i].Y]=i;
	// for(i=1;i<=n;i++)
	// 	printf("%d",ar[i]);
	long long sm=0;
	for(i=1;i<=n;i++)
	{
		sm+=i-sum(ar[i])-1;
		add(ar[i],1);
		// printf("%lld\n",sm);
	}
	printf("%lld",sm);
}