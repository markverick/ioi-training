#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int n,m,final,M,I;
vector<int> v[7],u[7];
inline void gen(int idx,int val)
{
	if(idx==n/2)
	{
		hsh[val]++;
		return;
	}
	for(int j=1;j<=26;j++)
	{
		gen(idx+1,((val*33ll)^j)%M);
	}
}
inline int rev(int idx,int val)
{
	if(idx==(n+1)/2)
	{
		return hsh[val];
	}
	int i,sm=0;
	for(i=1;i<=26;i++)
	{
		sm+=rev(idx+1,(((long long)(val^i))*I)%M);
	}
	return sm;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,sm=0;
	scanf("%d %d %d",&n,&final,&m);
	M=(1<<m);
	for(i=0;i<M;i++)
	{
		if((i*33)%M==1)
		{
			I=i;break;
		}
	}
	v[0].emplace_back(0);
	for(i=0;i<n/2;i++)
	{
		for(j=0;j<v[i].size();j++)
		{
			for(k=1;k<=26;k++)
				v[i+1].emplace_back(((v[i][j]*33ll)^k)%M);
		}
	}
	u[0].emplace_back(final);
	for(i=0;i<(n+1)/2;i++)
	{
		for(j=0;j<u[i].size();j++)
		{
			for(k=1;k<=26;k++)
				u[i+1].emplace_back( ((((long long)u[i][j]^i))*I)%M );
		}
	}
	for(i=0;i<M;i++)
		sm+=u[n/2]*v[(n+1)/2];
	printf("%d",sm;
}