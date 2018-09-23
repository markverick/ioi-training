#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int n,m;
double w,a[100135],fs,md,ls,idx,mn=MI,tmp;
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k=100,fk;
	scanf("%lf",&w);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lf",&a[i]);
	}
	fs=0;ls=MI;
	while(k--)
	{
		md=(fs+ls)/2;fk=0;
		idx=a[1]+md;fk=0;
		// printf("%f <- %f -> %f\n",fs,md,ls);
		// system("pause");
		for(i=2;i<=n;i++)
		{
			// printf("%f - %f<=%f = %f\n",(a[i]-md),idx+md,w,(a[i]-md)-idx+md);
			if(a[i]-idx<=md+w)
			{
				idx=min(idx+w,a[i]+md);
			}
			else
			{
				// printf("%f ---> %f\n",idx,a[i]);
				fk=1;
				break;
			}
		}
		if(fk==0)
		{
			mn=min(mn,md);
			ls=md;
		}
		else
		{
			fs=md;
		}
	}
	printf("%f\n",mn);
}