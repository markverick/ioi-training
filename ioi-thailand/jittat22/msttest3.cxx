#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int dist(pair<int,int> a,pair<int,int> b)
{
	return (a.X-b.X)*(a.X-b.X)+(a.Y-b.Y)*(a.Y-b.Y);
}
pair<int,int> p[100135];
edge<tuple<int,int,int> > e;
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d %d",&p[i].X,&p[i].Y);
	for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
			e.emplace_back(dist(p[i],p[j]),i,j);
	sort(e.begin(),e.end());
	int sm=0;
	for(i=0;i<e.size();i++)
	{
		tie(a,b,c)=e[i];
		printf("%lld %lld %lld\n",a,b,c);
		if(Find(b)!=Find(c))
		{
			Union(b,c);
			sm+=a;
		}
		printf("%lld\n",sm);
	}

}