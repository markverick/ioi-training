#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
map<int,int> row,col,hx,hy;
map<int,int> sum;
map<pair<int,int>,int > val;
long long sm=0,n;
void move(int x,int y,int z)
{
	// printf("!%d %d %d\n",x,y,z);
	sm-=n-hy[row[x]];
	sm-=n-hx[col[y]];
	// if(row[x]!=col[y])sm++;
	hx[row[x]]--;
	row[x]^=z;
	hx[row[x]]++;
	hy[col[y]]--;
	col[y]^=z;
	hy[col[y]]++;

	sm+=n-hy[row[x]];
	sm+=n-hx[col[y]];
	// if(row[x]!=col[y])sm--;
	val[MP(x,y)]^=z;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int m,p,i,j,k,a,b,x,y,z,xx,yy;
	scanf("%d %d %d",&n,&m,&p);
	hx[0]=n;hy[0]=n;
	for(i=1;i<=m;i++)
	{
		scanf("%d %d %d",&x,&y,&z);
		move(x,y,z);
		// printf("!!%d\n",val[MP(x,y)]);
	}
	while(p--)
	{
		scanf("%d %d %d %d",&x,&y,&xx,&yy);
		k=val[MP(x,y)];
		move(x,y,k);
		move(xx,yy,k);
		printf("%lld\n",sm);
	}
}