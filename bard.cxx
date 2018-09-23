#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int hsh[55],jum[135][55],a[55],b[135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	
	int i,j,k,n,m;
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d",&a[i]);
		memset(hsh,0,sizeof hsh);
		for(j=1;j<=a[i];j++)
			scanf("%d",&b[j]);
		sort(&b[1],&b[a[i]+1]);
		if(b[1]==1)
		{
			for(j=1;j<=a[i];j++)
			{
				jum[b[j]][i]=1;
			}
		}
		else
		{
			for(j=1;j<=a[i];j++)
			{
				for(k=1;k<i;k++)
				{
					if(jum[b[j]][k]==1)
						hsh[k]=1;
				}
			}
			for(j=1;j<i;j++)
			{
				if(hsh[j])
				{
					for(k=1;k<=a[i];k++)
					{
						jum[b[k]][j]=1;
					}
				}
			}
		}
		// printf("!%d!\n",i);
		// for(j=1;j<=n;j++)
		// {
		// 	for(k=1;k<=i;k++)
		// 	{
		// 		printf("%d ",jum[j][k]);
		// 	}
		// 	printf("\n");
		// }
	}
	memset(hsh,0,sizeof hsh);
	for(i=1;i<=m;i++)
	{
		if(jum[1][i])
		{
			// printf("!%d\n",i);
			hsh[i]=1;
		}
	}
	int fk;
	for(i=1;i<=n;i++)
	{
		fk=0;
		for(j=1;j<=m;j++)
		{
			if(!hsh[j])continue;
			if(jum[i][j]==0)
				fk=1;
		}
		if(fk==0)
			printf("%d\n",i);
	}
}