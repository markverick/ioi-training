#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int pos[500],cost[30][30],len,dp[205][205][30],mat[30][30];
vector<pair<int,int> > lis[30];
char a[30][3];
char s[30][30][20],ss[222];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,I,J,Q,fk=0;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			return 0;
		if(fk==1)
			printf("\n");
		fk=1;
		memset(pos,0,sizeof pos);
		memset(cost,0,sizeof cost);
		memset(ss,0,sizeof ss);
		memset(s,0,sizeof s);
		memset(a,0,sizeof a);
		for(i=0;i<n;i++)
			scanf("%s",a[i]),pos[a[i][0]]=i,lis[i].clear();
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%d-%s",&cost[i][j],s[i][j]);
				mat[i][j]=pos[s[i][j][0]];
				// printf("%d-%s\n",cost[i][j],s[i][j]);
			}
		}
		pair<int,int> mn={MI,MI},p;
		scanf("%d",&Q);
		while(Q--)
		{
			mn={MI,MI};
			scanf("%s",ss+1);
			len=strlen(ss+1);
			for(i=0;i<=len;i++)
				for(j=0;j<=len;j++)
					for(k=0;k<n;k++)
						dp[i][j][k]=MI;
			for(i=1;i<=len;i++)
				dp[1][i][pos[ss[i]]]=0;
			for(i=2;i<=len;i++)
			{
				for(j=1;j<=len-i+1;j++)
				{
					for(k=1;k<i;k++)
					{
						for(I=0;I<n;I++)
						{
							for(J=0;J<n;J++)
							{
								dp[i][j][mat[I][J]]=min(dp[i][j][mat[I][J]],dp[k][j][I]+dp[i-k][j+k][J]+cost[I][J]);
							}
						}
					}
				}
			}
			for(i=0;i<n;i++)
			{
				if(mn.X>dp[len][1][i])
				{
					mn=MP(dp[len][1][i],a[i][0]);
				}
			}
			printf("%d-%c\n",mn.X,mn.Y);
		}
	}
}