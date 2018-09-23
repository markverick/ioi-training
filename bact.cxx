#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[33][33],qs[999][33][33],hsh[999],row[33][33][33],col[33][33][33];
inline int qrow(int ch,int r,int c1,int c2)
{
	return qs[ch][r][c2]-qs[ch][r][c1-1]-qs[ch][r-1][c2]+qs[ch][r-1][c1-1];
}
inline qcol(int ch,int r1,int r2,int c)
{
	return qs[ch][r2][c]-qs[ch][r1-1][c]-qs[ch][r2][c-1]+qs[ch][r1-1][c-1];
}
int dp(int xa,int ya,int xb,int yb)
{
	int mc=0;
	if(xa==xb&&ya==yb)
		return 0;
	if(xa!=xb)
	{
		mc=max(mc,dp(xa+1,ya,xb,yb)+row[xa][ya][yb]?1:0);
		mc=max(mc,dp(xa,ya,xb-1,yb)+row[xb][ya][yb]?1:0);
	}
	if(ya!=yb)
	{
		mc=max(mc,dp(xa,ya+1,xb,yb)+col[ya][xa][xb]?1:0);
		mc=max(mc,dp(xa,ya,xb,yb-1)+col[yb][xa][xb]?1:0);
	}
	return mc;

}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,l,I,r,c,m,fk;
	scanf("%d %d %d",&r,&c,&m);
	for(i=1;i<=r;i++)
	{
		for(j=1;j<=c;j++)
		{
			scanf("%d",&a[i][j]);
			hsh[a[i][j]]++;
			for(k=1;k<=m;k++)
			{
				qs[k][i][j]=qs[k][i-1][j]+qs[k][i][j-1]-qs[k][i-1][j-1];
			}
			qs[a[i][j]][i][j]++;
		}
	}
	for(k=1;k<=r;k++)
	{
		for(i=1;i<=c;i++)
		{
			for(j=i;j<=c;j++)
			{
				fk=0;
				for(l=1;l<=m;l++)
				{
					I=qrow(l,k,i,j);
					if(I&&I!=hsh[l])
					{
						fk=1;
						break;
					}
				}
				if(fk==0)
					row[k][i][j]=1;
			}
		}
	}
	for(k=1;k<=c;k++)
	{
		for(i=1;i<=r;i++)
		{
			for(j=i;j<=r;j++)
			{
				fk=0;
				for(l=1;l<=m;l++)
				{
					I=qcol(l,i,j,k);
					if(I&&I!=hsh[l])
					{
						fk=1;
						break;
					}
				}
				if(fk==0)
					col[k][i][j]=1;
			}
		}
	}
	// for(k=1;k<=c;k++)
	// {
	// 	for(i=1;i<=r;i++)
	// 	{
	// 		for(j=i;j<=r;j++)
	// 			printf("[%d][%d - %d] -> %d\n",k,i,j,col[k][i][j]);
	// 	}
	// }
	printf("%d",dp(1,1,r,c));
}