#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
static int n;
static int x[10010];
static int y[10010];
int point_init()
{
  scanf("%d",&n);
  for(int i=0; i<n; i++)
    scanf("%d %d",&x[i],&y[i]);
  return n;
}

int query(int i, int j)
{
  return ((x[i] > x[j] ? x[i] - x[j] : x[j] - x[i]) +
          (y[i] > y[j] ? y[i] - y[j] : y[j] - y[i]));
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k;
	n=point_init();
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			query(i,j)
		}
	}
}