#include<bits/stdc++.h>
//coci2009-5 p4
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int n,m,a[135],L[109][109][109],R[109][109][109];
int jum[109][109][7];
int dp(int fs,int ls,int ext)
{
	ext=min(ext,m);
	if(jum[fs][ls][ext]>=0)return jum[fs][ls][ext];
	if(fs>ls)return 0;
	if(R[fs][ls][fs]==ls-fs+1)
	{
		return max(0,m-(ls-fs+1+ext));
	}
	int i,j,mn=MI;
	for(i=fs;i<=ls;i++)
	{
		if(i==fs||a[i]!=a[i-1])
		{
			for(j=i;j<=ls;j++)
			{
				if(j==ls||a[j]!=a[j+1]) //i<->j
				{
					if(i==fs&&j==ls)continue;
					else if(i==fs)mn=min(mn,dp(i,j,0)+dp(j+1,ls,ext));
					else if(j==ls)mn=min(mn,dp(fs,i-1,0)+dp(i,j,ext));
					else if(a[j+1]==a[i-1])
					{
						if(j+R[fs][ls][j+1]==ls)
						{
							mn=min(mn,dp(fs,i-1,R[fs][ls][j+1]+ext)+dp(i,j,0));
						}
						else
							mn=min(mn,dp(fs,i-1,R[fs][ls][j+1])+dp(j+1,ls,ext)+dp(i,j,0));
					}
					else
						mn=min(mn,dp(fs,i-1,0)+dp(j+1,ls,ext)+dp(i,j,0));

				}
			}
			
		}
	}
	// printf("%d %d %d = %d\n",fs,ls,ext,mn);
	return jum[fs][ls][ext]=mn;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	memset(jum,-1,sizeof jum);
	int i,j,k;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=1;i<=n;i++)
	{
		L[i][i][i]=1;
		R[i][i][i]=1;
		for(j=i+1;j<=n;j++)
		{
			L[i][j][i]=1;
			for(k=i+1;k<=j;k++)
			{
				if(a[k]!=a[k-1])
					L[i][j][k]=0;
				else
					L[i][j][k]=L[i][j][k-1]+1;
			}
			R[i][j][j]=1;
			for(k=j-1;k>=i;k--)
			{
				if(a[k]!=a[k+1])
					R[i][j][k]=0;
				else
					R[i][j][k]=R[i][j][k+1]+1;
			}
		}
	}
	printf("%d\n",dp(1,n,0));
}