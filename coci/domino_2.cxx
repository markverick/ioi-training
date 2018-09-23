#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;

vector<tuple<int,int,vector<int> > > v[10];
int n,m,a[1135][5];
int dp(int idx,int qt,int pat)
{
	if(qt<0)return -MI;
	if(idx==n)
	{
		if(qt)return -MI;
		if(pat==1)
			return 0;
		return -MI;
	}
	int mc=-MI,jump,cost;
	vector<int> vec;
	for(i=0;i<v[pat].size();i++)
	{
		tie(jump,cost,vec)=v[i];
		mc=max(mc,dp())
	}
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	v[1].EB(0,0,vector<int> {2,3,4});
	v[1].EB(0,0,vector<int> {5,7});
	v[1].EB(2,3,vector<int> {1});
	v[2].EB(0,0,vector<int> {6,7});
	v[2].EB(1,1,vector<int> {1});
	v[2].EB(1,2,vector<int> {5});
	v[3].EB(0,0,vector<int> {5,7});
	v[3].EB(1,0,vector<int> {1});
	v[4].EB(0,0,vector<int> {5,6});
	v[4].EB(1,1,vector<int> {1});
	v[4].EB(1,2,vector<int> {7});
	v[5].EB(1,0,vector<int> {1});
	v[5].EB(1,1,vector<int> {2});
	v[6].EB(1,0,vector<int> {1});
	v[6].EB(1,1,vector<int> {3});
	v[7].EB(1,0,vector<int> {1});
	v[7].EB(1,1,vector<int> {4});
	int i,j,k;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=3;j++)
			scanf("%d",&a[i][j]);
	}
	printf("%d",dp(0,m,1));
}