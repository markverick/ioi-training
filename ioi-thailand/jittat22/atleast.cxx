#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
vector<int> seg[262244],qs[262244];
int baw,x,y,a[100135];
double sum;
void build(int id,int fs,int ls)
{
	int md=(fs+ls)/2,i;
	if(fs==ls)
	{
		seg[id].emplace_back(a[fs]);
		qs[id]=seg[id];
		return;
	}
	build(id*2,fs,md);
	build(id*2+1,md+1,ls);
	for(i=0;i<seg[id*2].size();i++)
		seg[id].emplace_back(seg[id*2][i]);
	for(i=0;i<seg[id*2+1].size();i++)
		seg[id].emplace_back(seg[id*2+1][i]);
	sort(seg[id].begin(),seg[id].end());
	qs[id]=seg[id];
	for(i=1;i<qs[id].size();i++)
		qs[id][i]+=qs[id][i-1];
}
pair<double,int> Find(int id,int fs,int ls)
{
	int md=(fs+ls)/2,i;
	double j;
	// printf("%d %d %d\n",id,fs,ls);
	if(ls<x||fs>y)
	{
		return MP(0,0);
	}
	if(fs>=x&&ls<=y)
	{
		i=upper_bound(seg[id].begin(),seg[id].end(),baw)-seg[id].begin();
		if(i==0)
			return MP((qs[id][qs[id].size()-1])/(ls-fs+1),ls-fs+1);
		if((int)seg[id].size()-i==0)
			return MP(0,0);
		j=(double)(qs[id][qs[id].size()-1]+(i>=1?(-qs[id][i-1]):0))/((int)seg[id].size()-i);
			return MP(j,seg[id].size()-i);
	}
	pair<double,int> l,r;
	l=Find(id*2,fs,md);
	r=Find(id*2+1,md+1,ls);
	return MP((l.X*l.Y+r.X*r.Y)/(l.Y+r.Y),l.Y+r.Y);
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,m,i,j,k,out,fs,md,ls,mn;
	pair<double,int> p;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	build(1,1,n);
	while(m--)
	{
		scanf("%d %d %lf",&x,&y,&sum);
		fs=-1000005;ls=1000005;mn=1000005;out=-1;
		while(fs<=ls)
		{
			md=(fs+ls)/2;
			printf("%d %d %d\n",fs,md,ls);
			baw=md;
			p=Find(1,1,n);
			// printf("%lf %lf\n",p.X,sum);
			if(p.Y==0||p.X>=sum)
			{
				if(mn>md)
				{
					mn=md,out=y-x+1-p.Y;
					printf("WHA\n");
				}
				ls=md-1;
			}
			else
				fs=md+1;
		}
		printf("%d\n",out);
	}
}