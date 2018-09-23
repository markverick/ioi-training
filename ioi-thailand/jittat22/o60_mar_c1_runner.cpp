#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int c[2005],m[2005];
vector<int> v[135];
pair<int,int> p[2005];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,q,a,i,j,k,sm=0,L,R,y,fs,md,ls,mc,mn;
	scanf("%d %d",&n,&q);
	for(i=1;i<=n;i++)
	{
		scanf("%d %d",&a,&m[i]);
		v[m[i]].emplace_back(a);
	}
	for(i=0;i<=100;i++)
		sort(v[i].begin(),v[i].end());
	while(q--)
	{
		scanf("%d %d %d",&y,&L,&R);
		sm=0;
		for(i=0;i<=100;i++)
		{
			sm+=upper_bound(v[i].begin(),v[i].end(),(double)R-(double)y/i)
			-lower_bound(v[i].begin(),v[i].end(),(double)L-(double)y/i);
		}
		printf("%d\n",sm);
	}
}