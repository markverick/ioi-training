#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int hi[1000135];
int x,y,val;

int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,n,m,fs,md,ls,mn,mc,pos,h;
	scanf("%d %d",&n,&m);
	for(j=1;j<=m;j++)
	{
		scanf("%d %d",&pos,&h);
		pos++;
		hi[pos]=h;
		for(i=pos;i>=1;i--)
		{
			if(hi[i]>h)
				break;
		}
		mn=i+1;
		if(mn==1)
			mn=-MI;
		for(i=pos;i<=n;i++)
		{
			if(hi[i]>h)break;
		}
		mc=i-1;
		if(mc==n)
			mc=MI;
		printf("%d\n",min(n,min(pos-mn,mc-pos)));

	}
	
}