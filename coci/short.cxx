#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,i,j,k;
	scanf("%d %d",&n,&m);
	if((double)m*m<n)
		printf("-1");
	else
	{
		i=1;
		while(i<=n)
		{
			for(j=min(n,i+m-1);j>=i;j--)
				printf("%d ",j);
			i=i+m;
		}
	}
}