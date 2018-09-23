#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[100315];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k;
	vector<int> v;
	vector<int> ::iterator it;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a[i]+=a[i-1];
	}
	for(i=1;i<=n;i++)
	{
		if(a[i]<0||a[i]>a[n])continue; //start from a[1], end at a[n]
		it=lower_bound(v.begin(),v.end(),a[i]);
		if(it==v.end())v.emplace_back(a[i]);
		else *it=a[i];
	}
	printf("%d",v.size());
}