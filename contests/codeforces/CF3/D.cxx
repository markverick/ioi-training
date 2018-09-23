#include<bits/stdc++.h>
#define X first
#define Y second
#define MOD 1000000007
#define MAX 1000000000000000005
using namespace std;
pair<long long,long long> a[300005];
vector<pair<long long,int> > v;
int hsh[300005];
pair<long long,int> fw[300005];
void add(int x,long long val)
{	
	while(x<300005)
	{
		fw[x].X+=val;
		if(fw[x].X>MAX) fw[x].X=MAX;
		fw[x].Y++;
		x+=x&-x;
	}

}
int sum(int x,long long yo)
{
	int ss=0;
	while(x>0)
	{
		yo-=fw[x].X;
		if(yo<0) break;
		ss+=fw[x].Y;
		x-=x&-x;
	}
	return yo<0 ? -1 : ss;

}
int main()
{
	int n,i,l,r,kb,res,mn,mid;
	long long x,y;
	scanf("%d",&n);
	scanf("%I64d%I64d",&x,&y);
	n--;
	mn=n;
	for(i=0;i<n;i++) scanf("%I64d%I64d",&a[i].X,&a[i].Y);
	sort(a,a+n);
	for(i=0;i<n;i++) v.emplace_back(a[i].Y-a[i].X+1,i);
	sort(v.begin(),v.end());
	for(i=0;i<v.size();i++) hsh[v[i].Y]=i+1;
	for(i=n-1;i>=0;i--)
	{
		if(a[i].X<=x)
		{
			l=1;
			r=n;
			res=0;
			while(l<=r)
			{
				mid=(l+r)/2;
				kb=sum(mid,x-a[i].X);
				if(kb!=-1)
				{
					res=kb;
					l=mid+1;
				}
				else r=mid-1;
			}
			mn=min(mn,n-1-i-res);
		}
		add(hsh[i],a[i].Y-a[i].X+1);

	}
	printf("%d\n",mn+1);
}