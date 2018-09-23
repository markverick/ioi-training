#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int mat[333][333],po[13][333][333],out[333][333],tmp[333][333];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,l,n,m,a,b,c,d,fk;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			mat[i][j]=-MI,out[i][j]=-MI;
		mat[i][i]=0;out[i][i]=0;
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d %d %d %d",&a,&b,&c,&d);
		mat[a][b]=d-c;
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			po[0][i][j]=mat[i][j];
	for(i=1;(1<<i)<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			for(k=1;k<=n;k++)
			{
				po[i][j][k]=po[i-1][j][k];
				for(l=1;l<=n;l++)
				{
					po[i][j][k]=max(po[i][j][k],po[i-1][j][l]+po[i-1][l][k]);
				}
			}

		}
	}
	fk=i-1;
	// for(i=0;(1<<i)<=n;i++)
	// {
	// 	printf("\t2^%d\n",i);
	// 	for(j=1;j<=n;j++)
	// 	{
	// 		for(k=1;k<=n;k++)
	// 		{
	// 			if(po[i][j][k]<=-MI/10)
	// 				printf("  . ");
	// 			else
 // 					printf("%3d ",po[i][j][k]);
	// 		}
	// 		printf("\n");
	// 	}
	// 	printf("\n");
	// }
	// printf("!%d\n",fk);
	int ret=0;
	for(i=fk;i>=0;i--)
	{
		// out x po[i]
		fk=0;
		for(j=1;j<=n;j++)
		{
			for(k=1;k<=n;k++)
			{
				tmp[j][k]=out[j][k];
				if(out[j][k]+po[i][k][j]>0)
				{
					fk=1;break;
				}
			}
		}
		if(fk==1)
		{
			if(i==0)break;
			continue;
		}
		ret+=(1<<i);
		// printf("[%d] %d\n",i,ret);
		for(j=1;j<=n;j++)
		{
			for(k=1;k<=n;k++)
			{
				for(l=1;l<=n;l++)
				{
					out[j][k]=max(out[j][k],tmp[j][l]+po[i][l][k]);
				}
				out[j][k]=max(out[j][k],po[i][j][k]);
			}
		}
		if(i==0)break;
	}
	int mc=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			mc=max(mc,out[i][j]+po[0][j][i]);
		}
	}
	printf("%d %d\n",ret+1,mc);
}