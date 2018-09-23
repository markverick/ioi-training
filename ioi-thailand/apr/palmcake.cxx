#include<bits/stdc++.h>
#define p1 p[gs[v[v.size()-2]].Y]
#define p2 p[gs[v[v.size()-1]].Y]
#define p3 p[gs[i].Y]
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
pair<int,int> p[100135];
pair<double,int> gs[100135];
vector<int> v;
double pi;
bool cmp(pair<int,int> a,pair<int,int> b)
{
	if(a.Y!=b.Y)return a.Y<=b.Y;
	return a.X<=b.X;
}
pair<int,int> operator -(pair<int,int> a,pair<int,int> b)
{
	return MP(a.X-b.X,a.Y-b.Y);
}
bool isLeft(pair<int,int> a,pair<int,int> b)
{
	return a.X*b.Y-a.Y*b.X>0;
}
double ang(pair<int,int> a)
{
	double b=atan2(a.Y,a.X);
	if(b<0)b+=pi;
	return b;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,mc=0;
	pi=acos(-1.0);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d %d",&p[i].X,&p[i].Y);
	}
	sort(&p[1],&p[n+1],cmp);
	for(i=2;i<=n;i++)
	{
		gs[i]=MP(ang(p[i]-p[1]),i);
	}
	sort(&gs[2],&gs[n+1]);
	gs[n+1]=MP(0,1);
	gs[n+2]=gs[2];
	gs[1]=MP(0,1);
	v.emplace_back(1);
	v.emplace_back(2);
	for(i=3;i<=n;i++)
	{
		while(v.size()>=2&&!isLeft(p2-p1,p3-p2))
			v.pop_back();
		mc=max(mc,i-v[v.size()-2]+1);
		// printf("[%d] (%d,%d) -- (%d,%d)\n",i-v[v.size()-2],p1.X,p1.Y,p3.X,p3.Y);
		v.emplace_back(i);
	}
	printf("%d\n",mc);
}