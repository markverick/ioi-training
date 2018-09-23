#include<bits/stdc++.h>
using namespace std;
int a[135],b[135],tma[135],R=0,C,D;
char mps[100135][135];
vector<char> v[135];
int main()
{
	int i,j,k,T,t,n;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		memset(mps,0,sizeof mps);
		memset(b,0,sizeof b);
		memset(tma,0,sizeof tma);
		R=0;C=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			v[i].clear();
			scanf("%d",&a[i]);
		}
		if(a[1]==0||a[n]==0)
		{
			printf("Case #%d: IMPOSSIBLE\n",t);
			continue;
		}
		R=1;
		for(i=0;i<a[1];i++)
		{
			for(j=2;j<=a[1]-i;j++)
				mps[R][j]='/';
			R++;
				
		}
		for(i=0;i<a[n];i++)
		{
			for(j=n-1;j>n-a[n]+i;j--)
				mps[R][j]='\\';
			R++;
		}
		C=a[1]+1;
		for(k=2;k<n;k++)
		{
			if(a[k]!=0)
			{
				// printf("%d\n",C);
				b[C]=a[k];
				tma[C]=k;
				for(i=0;i<a[k];i++)
				{
					for(j=C+1;j<C+a[k]-i;j++)
					{
						mps[R][j]='/';
					}
					R++;
				}
				for(i=C;i>k;i--)
				{
					mps[R][i]='/';
					R++;
				}
				C+=a[k];
			}
		}
		D=n-a[n];
		for(k=n-a[n];k>=a[1];k--)
		{
			if(tma[k]==0)continue;
			// printf("%d %d\n",tma[k],k);
			for(i=k;i<tma[k];i++)
			{
				mps[R][i]='\\';
				R++;
			}				

		}
		int prev=0,chk=0;
		for(j=1;j<=n;j++)
		{
			prev=0;
			for(i=1;i<=R;i++)
			{
				if(mps[i][j]!=0)
				v[j].emplace_back(mps[i][j]);
			}
		}
		for(i=1;i<=R;i++)
		{
			for(j=1;j<=n;j++)
			{
				printf("%c",mps[i][j]==0?'.':mps[i][j]);
			}
			printf("\n");
		}
		memset(mps,0,sizeof mps);
		for(j=1;j<=n;j++)
		{
			chk=max(chk,(int)v[j].size());
			for(i=0;i<v[j].size();i++)
			{
				mps[i+1][j]=v[j][i];
			}
		}
		printf("Case #%d: %d\n",t,chk+1);
		for(i=1;i<=chk+1;i++)
		{
			for(j=1;j<=n;j++)
			{
				printf("%c",mps[i][j]==0?'.':mps[i][j]);
			}
			printf("\n");
		}
	}
}