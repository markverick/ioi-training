#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
pair<long long,long long> p[300135];
long long c[300135];
multiset<pair<long long,long long> > st;
int main()
{
	tuple<int,int,int> tp;
	printf("!");
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	long long n,m,i,j,k,sm=0;
	scanf("%lld %lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld %lld",&p[i].X,&p[i].Y);
	}
	sort(&p[1],&p[n+1]);
	for(i=1;i<=m;i++)
	{
		scanf("%lld",&c[i]);
	}
	sort(&c[1],&c[m+1]);
	j=1;
	for(i=1;i<=m;i++)
	{
		while(j<=n&&p[j].X<=c[i])
		{
			swap(p[j].X,p[j].Y);
			p[j].X=-p[j].X;
			st.insert(p[j]);
			j++;
		}
		if(!st.empty())
		{
			sm+=-(*st.begin()).X;
			st.erase(st.begin());
		}
	}
	printf("%lld",sm);
}