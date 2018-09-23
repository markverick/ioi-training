#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int se[1000135],a[135],hsh[100135];
vector<int> p,v[100135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,l,target,sm=0,prod=1;
	for(i=2;i<=1000000;i++)
	{
		if(se[i])continue;
		p.emplace_back(i);
		for(j=i;j<=1000000;j+=i)
			se[j]=1;
	}
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		k=a[i];
		for(j=0;j<p.size();j++)
		{
			l=0;
			while(k%p[j]==0)
			{
				l++;
				k/=p[j];
			}
			if(l)v[j].emplace_back(l);
			hsh[j]+=l;
		}
	}
	for(i=0;i<p.size();i++)
	{
		target=hsh[i]/n;
		for(j=0;j<target;j++)
			prod*=p[i];
		sort(v[i].begin(),v[i].end());
		for(j=0;j<v[i].size();j++)
		{
			if(v[i][j]>=target)break;
			sm+=target-v[i][j];
		}
		for(j=v[i].size();j<n;j++)
			sm+=target;
	}
	printf("%d %d",prod,sm);
}