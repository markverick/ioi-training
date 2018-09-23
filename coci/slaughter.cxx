#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[1135],b[1135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,n,fk=0,mul=0;
	double x,mn=107,mc=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d %d",&a[i],&b[i]);
		mul+=b[i];
	}
	for(i=1;i<n;i++)
	{
		if(b[i+1]-b[i]==0)
		{
			if(a[i]-a[i+1]>=0)
				continue;
			else
			{
				fk=1;
				break;
			}
		}
		else
		{
			x=(double)(a[i]-a[i+1])/(b[i+1]-b[i]);
			if(b[i+1]-b[i]>=0)
				mn=min(mn,x);
			else
				mc=max(mc,x);
			// if(b[i+1]-b[i]>=0)
			// 	printf("Min ");
			// else
			// 	printf("Max ");
			// printf("%f\n",x);
		}
	}
	// printf("%f %f\n",mn,mc);
	if(fk==0&&mc<=mn)
		printf("%f",(mn+mc)*mul/2);
	else
		printf("-1");
}