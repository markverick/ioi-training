#include<bits/stdc++.h>
#define MI 1000000000
#define EPS 0.000000001
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
typedef pair<double,double> pdd;
pair<int,int> a[135],b[135];
vector<pair<int,int> > op;
double ang(pair<int,int> u,pair<int,int> v)
{
	if(u.X*v.Y-u.Y*v.X>=0)
		return acos((double)(u.X*v.X+u.Y*v.Y)/(hypot(u.X,u.Y)*hypot(v.X,v.Y)));
	else
		return -acos((double)(u.X*v.X+u.Y*v.Y)/(hypot(u.X,u.Y)*hypot(v.X,v.Y)));
}
pdd operator -(pdd a,pdd b)
{
	return MP(a.X-b.X,a.Y-b.Y);
}
pair<int,int> operator -(pair<int,int> a,pair<int,int> b)
{
	return MP(a.X-b.X,a.Y-b.Y);
}
pdd operator +(pdd a,pdd b)
{
	return MP(a.X+b.X,a.Y+b.Y);
}
double operator *(pdd a,pdd b)
{
	return a.X*b.Y-a.Y*b.X;
}
pdd operator *(double a,pdd b)
{
	return MP(b.X*a,b.Y*a);
}
int chk(pdd p,pdd r,pdd q,pdd s,pdd &x)
{
	if(abs(r*s)<=EPS)
		return 0;
	// printf("%f/%f\n",(q-p)*r,r*s);
	double u=((q-p)*r)/(r*s),t=((q-p)*s)/(r*s);
	if(t>=0-EPS&&t<=1+EPS&&u>=0-EPS&&u<=1+EPS)
	{
		// printf("%f %f\n",u,t);
		x=q+(u*s);
		return 1;
	}
	return 0;
}
vector<pdd> v;
int main()
{
	freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,m,i,j,k;
	double sm;
	double pi=acos(-1.0);
	pdd out;
	while(scanf("%d",&n)!=EOF)
	{
		op.clear();
		if(n<3)return 0;
		v.clear();
		for(i=1;i<=n;i++)
			scanf("%d %d",&a[i].X,&a[i].Y);
		a[n+1]=a[1];
		scanf("%d",&m);
		for(i=1;i<=m;i++)
			scanf("%d %d",&b[i].X,&b[i].Y);
		b[m+1]=b[1];
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(chk(a[i],a[i+1]-a[i],b[j],b[j+1]-b[j],out))
				{
					// printf("%d %d -> %d %d x %d %d -> %d %d\n",a[i].X,a[i].Y,(a[i+1]-a[i]).X,(a[i+1]-a[i]).Y,b[j].X,b[j].Y,(b[j+1]-b[j]).X,(b[j+1]-b[j]).Y);
					v.emplace_back(out);
				}
			}
		}
		// for(i=0;i<v.size();i++)
		// {
		// 	for(j=1;j<=n;j++)
		// 		if(abs(v[i].X-a[j].X)==0&&abs(v[i].Y-a[j].Y)==0)
		// 			v[i]=MP(MI,MI);
		// 	for(j=1;j<=m;j++)
		// 		if(abs(v[i].X-b[j].X)==0&&abs(v[i].Y-b[j].Y)==0)
		// 			v[i]=MP(MI,MI);
		// }
		for(i=1;i<=n;i++)
		{
			sm=0;
			for(j=1;j<=m;j++)
			{
				sm+=ang(b[j]-a[i],b[j+1]-a[i]);
			}
			if(abs(sm-pi*2)<=EPS)
				v.emplace_back(a[i]);
		}
		for(i=1;i<=m;i++)
		{
			sm=0;
			for(j=1;j<=n;j++)
			{
				sm+=ang(a[j]-b[i],a[j+1]-b[i]);
			}
			if(abs(sm-pi*2)<=EPS)
				v.emplace_back(b[i]);
		}
		for(i=0;i<v.size();i++)
		{
			op.emplace_back(nearbyint(v[i].X*100),nearbyint(v[i].Y*100));
		}
		sort(op.begin(),op.end());
		op.resize(unique(op.begin(),op.end())-op.begin());
		printf("%d\n",op.size());
		for(i=0;i<op.size();i++)
			printf("%d.%02d %d.%02d\n",op[i].X/100,abs(op[i].X)%100,op[i].Y/100,abs(op[i].Y)%100);
	}
}