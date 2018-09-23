#include<bits/stdc++.h>
using namespace std;
int a[100135],b[100135];
int main()
{
	int T,t,i,j,k,d,n,m,sm,cot,A,B;
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			if(i%2==0)
				scanf("%d",&a[i/2]);
			else
				scanf("%d",&b[i/2]);
		}
		A=(n+1)/2;
		B=n/2;
		sort(&a[0],&a[A]);
		sort(&b[0],&b[B]);
		// for(i=0;i<A;i++)
		// {
		// 	printf("%d ",a[i]);
		// }
		// printf("\n ");
		// for(i=0;i<B;i++)
		// {
		// 	printf("%d ",b[i]);
		// }
		// printf("\n");
		cot=-1;
		for(i=0;i<B;i++)
		{
			if(b[i]<a[i])
			{
				cot=i*2;
				break;
			}
			if(i+1<A&&a[i+1]<b[i])
			{
				cot=(i)*2+1;
				break;
			}
		}
		if(cot>=0)
			printf("Case #%d: %d\n",t,cot);
		else
			printf("Case #%d: OK\n",t);

	}
}