#include<bits/stdc++.h>
using namespace std;
char s[50];
int mul[50];
int main()
{
	int T,t,i,j,k,d,n,m,sm,cot;
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		memset(mul,0,sizeof mul);
		scanf("%d %s",&d,&s);
		n=strlen(s);
		m=1;sm=0;cot=0;
		for(i=0;i<n;i++)
		{
			if(s[i]=='C')m*=2;
			else
			{
				sm+=m;
				mul[i]=m;
			}
		}
		while(sm>d)
		{
			for(i=n-1;i>=1;i--)
			{
				if(s[i]=='S'&&s[i-1]=='C')
				{
					sm-=mul[i]/2;
					mul[i-1]=mul[i]/2;
					swap(s[i],s[i-1]);
					cot++;
					break;
				}
			}
			if(i==0)
			{
				cot=-1;
				break;
			}
		}
		if(cot>=0)
			printf("Case #%d: %d\n",t,cot);
		else
			printf("Case #%d: IMPOSSIBLE\n",t);

	}
}