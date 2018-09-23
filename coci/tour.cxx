#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[1135];
vector<int> out[12];
void dfs(int fs,int ls,int lv)
{
	int md=(fs+ls)/2;
	out[lv].emplace_back(a[md]);
	if(fs==ls)return;
	dfs(fs,md-1,lv+1);
	dfs(md+1,ls,lv+1);
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,m;
	scanf("%d",&n);
	m=(1<<n)-1;
	for(i=1;i<=m;i++)
		scanf("%d",&a[i]);
	dfs(1,m,1);
	for(i=1;i<=n;i++)
	{
		for(j=0;j<out[i].size();j++)
			printf("%d ",out[i][j]);
		printf("\n");
	}
}