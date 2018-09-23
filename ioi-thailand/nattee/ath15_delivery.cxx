#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int c[100135],w[100135],hsh[100135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,m,T,i,j,k,fs=0,md,ls=MI,mn=MI,cot,sum;
	scanf("%d",&T);
	while(T--)
	{
		mn=MI;fs=0;ls=MI;
		scanf("%d %d",&n,&m);
		for(i=1;i<=n;i++)
			scanf("%d %d",&w[i],&c[i]),fs=max(fs,w[i]);
		while(fs<=ls)
		{
			md=(fs+ls)/2;
			// printf("%d <- %d -> %d\n",fs,md,ls);
			j=1;cot=1;sum=0;
			memset(hsh,0,sizeof hsh);
			for(i=1;i<=n;i++)
			{
				if(sum+w[i]>md||hsh[c[i]])
				{
					for(k=j;k<i;k++)
						hsh[c[k]]--;
					j=i;
					cot++;
					sum=0;
				}
				hsh[c[i]]++;
				sum+=w[i];
			}
			if(cot<=m)
			{
				mn=min(mn,md);
				ls=md-1;
			}
			else
				fs=md+1;
		}
		if(mn>=MI)
			printf("-1\n");
		else
			printf("%d\n",mn);
	}
}