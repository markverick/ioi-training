#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[200135],qs[500135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,h,i,j,k,mn=MI,cot=0;
	scanf("%d %d",&n,&h);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(i%2)
		{
			qs[1]++;
			qs[a[i]+1]--;
		}
		else
		{
			qs[h-a[i]+1]++;
			qs[h+1]--;
		}
	}
	for(i=1;i<=h;i++)
	{
		qs[i]+=qs[i-1];
		mn=min(mn,qs[i]);
	}
	for(i=1;i<=h;i++)
	{
		if(qs[i]==mn)
			cot++;
	}
	printf("%d %d",mn,cot);
}