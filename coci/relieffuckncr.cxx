#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int ncr[10135][10135],a[10135];
inline int snb(int obj,int side)
{
	if(obj-side<0)return 0;
	return ncr[obj-side+side-1][side-1];
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,prod=1;
	for(i=0;i<=10000;i++)
		ncr[i][0]=1;
	for(i=1;i<=10000;i++)
	{
		for(j=1;j<=i;j++)
		{
			ncr[i][j]=ncr[i-1][j]+ncr[i-1][j-1];
		}
	}
	printf("%d\n",ncr[2][2]);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(i==1||i==n)a[i]=0;
		if(a[i]>=0)
		{
			if(i>1)
			{
				printf("%d %d = %d\n",i-j+2,abs(a[i]-a[j])+1,snb(i-j+2,abs(a[i]-a[j])+1));
				prod*=snb(i-j+2,abs(a[i]-a[j])+1);
			}
			j=i;
		}
	}
	printf("%d\n",prod);
}