#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int hsh[2000135],a[2000135],ct[2000135];
vector<int> prm;
vector<pair<int,int> > lst;
void dfs(int idx,int prod)
{
	if(idx==lst.size())
	{
		ct[prod]++;
		return;
	}
	int i;
	for(i=0;i<=lst[idx].Y;i++)
	{
		dfs(idx+1,prod);
		prod*=lst[idx].X;
	}
}
int main()
{
	//freopen("out.txt","w",stdout);
	// freopen("in.txt","r",stdin);
	int i,j,k,n;
	vector<int> v;
	for(i=2;i<=2000000;i++)
	{
		if(hsh[i])continue;
		prm.emplace_back(i);
		for(j=i;j<=2000000;j+=i)
			hsh[j]=1;
	}
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		k=a[i];
		v.clear();lst.clear();
		for(j=0;j<prm.size();j++)
		{
			if(prm[j]*prm[j]>k)
				break;
			while(k%prm[j]==0)
			{
				v.emplace_back(prm[j]);
				k/=prm[j];
			}
		}
		if(k>1)
			v.emplace_back(k);
		sort(v.begin(),v.end());
		k=1;
		for(j=1;j<v.size();j++)
		{
			if(v[j]==v[j-1])
				k++;
			else
			{
				lst.emplace_back(v[j-1],k);
				k=1;
			}
		}
		if(!v.empty())
			lst.emplace_back(v[v.size()-1],k);
		dfs(0,1);
	}
	long long mc=0;
	for(i=1;i<=2000000;i++)
	{
		if(ct[i]>1)
			mc=max(mc,(long long)ct[i]*i);
	}
	printf("%lld",mc);
}