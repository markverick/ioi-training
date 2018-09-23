#include<bits/stdc++.h>
// #pragma GCC optimize ("O3")
#define MI 1000000000
#define M 1000000007
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char sa[50135],sb[50135];
int a[50135],b[50135],n;
pair<int,int> jum[50135][4][4];
inline pair<int,int> dp(int idx,int aa,int bb)
{
	if(jum[idx][aa][bb].X>=0)
		return jum[idx][aa][bb];
	int i,j,A,B,sum=0,prod=0;
	pair<int,int> p;
	if(idx==n+1)
	{
		return {1,0};
	}
	for(i=0;i<=9;i++)
	{
		for(j=0;j<=9;j++)
		{
			if(aa==3)
			{
				if(i>b[idx])break;
				if(i<a[idx])
				{
					i=a[idx]-1;break;
				}
				if(i==a[idx]&&i==b[idx])A=3;
				else if(i==a[idx])A=1;
				else if(i==b[idx])A=2;
				else A=0;
			}
			else if(aa==1)
			{
				if(i<a[idx])
				{
					i=a[idx]-1;break;
				}
				if(i==a[idx])A=1;
				else A=0;
			}
			else if(aa==2)
			{
				if(i>b[idx])break;
				if(i==b[idx])A=2;
				else A=0;
			}
			else
				A=0;
			if(bb==3)
			{
				if(j>b[idx])break;
				if(j<a[idx])
				{
					j=a[idx]-1;
					continue;
				}
				if(j==a[idx]&&j==b[idx])B=3;
				else if(j==a[idx])B=1;
				else if(j==b[idx])B=2;
				else B=0;
			}
			else if(bb==1)
			{
				if(j<a[idx]){j=a[idx]-1;continue;};
				if(j==a[idx])B=1;
				else B=0;
			}
			else if(bb==2)
			{
				if(j>b[idx])break;
				if(j==b[idx])B=2;
				else B=0;
			}
			else
				B=0;
			p=dp(idx+1,A,B);
			sum+=p.X;
			sum%=M;
			prod+=((long long)p.Y+(long long)p.X*abs(i-j))%M;
			prod%=M;
		}
	}
	// printf("%d %d\n",sum,prod);
	return jum[idx][aa][bb]=MP(sum,prod);
}
int main()
{
	//freopen("out.txt","w",stdout);
	freopen("inn.txt","r",stdin);
	int i,j,k,la,lb;
	memset(jum,-1,sizeof jum);
	scanf("%s %s",sa+1,sb+1);
	la=strlen(sa+1);
	lb=strlen(sb+1);
	printf("%d %d\n",la,lb);
	n=max(lb,la);
	for(i=1;i<=la;i++)
		a[i+n-la]=sa[i]-'0';
	for(i=1;i<=lb;i++)
		b[i+n-lb]=sb[i]-'0';
	printf("!");
	printf("%d\n",dp(1,3,3).Y);
}
