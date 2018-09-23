#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int maps[2135][2135],mat[2135][2135],dx[6]={1,-1,0,0},dy[6]={0,0,1,-1};
vector<int> v[6];
queue<tuple<int,int,int> > q;
int main()
{
	//freopen("out.txt","w",stdout);
	// freopen("in.txt","r",stdin);
	int i,j,k,n,m,a,b,x,y,w;
	long long A=0,B=0;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d %d",&a,&b);
		maps[a+1005][b+1005]=1;
	}
	mat[1005][1005]=m+1;
	q.emplace(1005,1005,m+1);
	while(!q.empty())
	{
		tie(x,y,w)=q.front();
		q.pop();
		if(w<=1)
			continue;
		for(i=0;i<4;i++) //1-1005, 1005-2009
		{
			if(x+dx[i]<0||x+dx[i]>2010||y+dy[i]<0||y+dy[i]>2010||maps[x+dx[i]][y+dy[i]]==1)continue;
			if(mat[x+dx[i]][y+dy[i]]>0)continue;
			mat[x+dx[i]][y+dy[i]]=w-1;
			q.emplace(x+dx[i],y+dy[i],w-1);
		}
	}
	for(i=1;i<=2009;i++)
	{
		for(j=1;j<=2009;j++)
		{
			if(mat[i][j]>0)
			{
				if(mat[i][j]%2)A++;
				else B++;
			}
		}
	}
	// printf("%lld %lld\n",A,B);
	for(j=1;j<=2009;j++)
		v[0].emplace_back(mat[1][j]);
	for(i=1;i<=2009;i++)
		v[1].emplace_back(mat[i][2009]);
	for(j=2009;j>=1;j--)
		v[2].emplace_back(mat[2009][j]);
	for(i=2009;i>=1;i--)
		v[3].emplace_back(mat[i][1]);
	for(i=0;i<4;i++)
	{
		for(j=0;j<v[i].size();j++)
		{
			k=v[i][j]-1;
			if(k<=0)continue;
			A+=k/2;B+=k/2;
			if(k%2)
				A++;
		}
	}
	// printf("%lld %lld\n",A,B);
	long long tmp,kk;
	for(i=0;i<4;i++)
	{
		tmp=0;kk=0;
		for(j=v[i][0]-2;j>0;j-=2)
			kk+=j;
		for(j=v[i][0]-2;j>0;j--)
			tmp+=j;
		A+=kk;
		B+=tmp-kk;
	}
	if(m%2)swap(A,B);
	printf("%lld %lld\n",A,B);
}