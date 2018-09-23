#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[5005],hsh[400135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,cot=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		for(j=1;j<i;j++)
		{
			if(hsh[200000+a[i]-a[j]]==1)
			{
				cot++;
				break;
			}
		}
		for(j=1;j<=i;j++)
		{
			hsh[200000+a[i]+a[j]]=1;
		}
	}
	printf("%d",cot);
}