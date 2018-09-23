#include<bits/stdc++.h>
using namespace std;
int a[135],b[135],tma[135],L[135],R[135],C,D;
char mps[100135][135];
vector<char> v[135];
int main()
{
	int i,j,k,T,t,n,mc=0,sm;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		memset(mps,0,sizeof mps);
		memset(b,0,sizeof b);
		memset(tma,0,sizeof tma);
		memset(L,0,sizeof L);
		memset(R,0,sizeof R);
		memset(L,0,sizeof L);
		C=0;
		mc=0;
		sm=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			v[i].clear();
			scanf("%d",&a[i]);
			sm+=a[i];
		}
		if(sm!=n||a[1]==0||a[n]==0)
		{
			printf("Case #%d: IMPOSSIBLE\n",t);
			continue;
		}
		C=1;
		for(i=1;i<=n;i++)
		{
			if(a[i]>0)
				L[i]=C,R[i]=C+a[i]-1,C=R[i]+1;
		}
		for(i=1;i<=n;i++)
		{
			if(L[i]==0)continue;
			// printf("%d %d %d\n",L[i],i,R[i]);
			for(j=i-1;j>=L[i];j--)
			{
				for(k=1;k<=i-L[i]-(i-j-1);k++)
					mps[k][j]='\\',mc=max(mc,k);
			}
			for(j=i+1;j<=R[i];j++)
			{
				for(k=1;k<=R[i]-i-(j-i-1);k++)
				mps[k][j]='/',mc=max(mc,k);
			}
			if(i<L[i])
			{
				for(j=L[i]-1,k=R[i]-L[i]+2;j>i;k++,j--)
					mps[k][j]='/',mc=max(mc,k);
			}
			if(i>R[i])
			{
				for(j=R[i]+1,k=R[i]-L[i]+2;j<i;k++,j++)
					mps[k][j]='\\',mc=max(mc,k);
			}
		}
		printf("Case #%d: %d\n",t,mc+1);
		for(i=1;i<=mc+1;i++)
		{
			for(j=1;j<=n;j++)
				printf("%c",mps[i][j]==0?'.':mps[i][j]);
			printf("\n");
		}

	}
}