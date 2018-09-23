#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
pair<int,int> a[100135],b[100135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,N;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d %d %d %d",&a.X,a.Y,&b.X,&b.Y);
	}
	for(i=1;i<=n;i++)
	{
		if(a[i].X<0&&b[i].X<0&&a[i].Y<0&&b[i].Y<0)
			a[i].X=-a[i].X,a[i].Y=-a[i].Y,b[i].X=-b[i].X,b[i].Y=-b[i].Y
		else if(a[i].X<0&&b[i].X)
	}
}