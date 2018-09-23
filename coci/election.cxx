#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[135],b[135],hsh[135],n,m,v,sum;
void Find(int T)
{
	int x,i;
	double mc=-1;
	memset(hsh,0,sizeof hsh);
	while(T--)
	{
		mc=-1;
		for(i=1;i<=n;i++)
		{
			if(a[i]*20<v)continue;
			if(mc+0.00000001<(double)a[i]/(hsh[i]+1))
			{
				mc=(double)a[i]/(hsh[i]+1);
				x=i;
			}
		}
		hsh[x]++;
	}
	// for(i=1;i<=n;i++)
	// {
	// 	printf("%d ",hsh[i]);
	// }
	// printf("\n");
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,mn,x,T,fs,md,ls,sm;
	scanf("%d %d %d",&v,&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=a[i];
		sum+=a[i];
	}
	for(i=1;i<=n;i++)
	{
		a[i]+=v-sum;
		Find(m);
		printf("%d ",hsh[i]);
		a[i]-=v-sum;
	}
	printf("\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			a[j]=b[j];
		T=v-sum;fs=0;ls=v;sm=0;mn=MI;
		while(fs<=ls)
		{
			md=(fs+ls)/2;sm=0;
			for(j=1;j<=n;j++)
			{
				if(i==j)continue;
				sm+=max(0,md-a[i]);
			}
			if(T<=sm)
			{
				mn=min(mn,sm);
				ls=md-1;
			}
			else
			{
				fs=md+1;
			}
		}
		sm=0;
		for(j=1;j<=n;j++)
		{
			if(i==j)continue;
			sm+=max(0,mn-a[j]);
			a[j]=max(a[j],mn);
		}
		T=sm-T;
		for(j=1;T&&j<=n;j++)
		{
			if(i==j)continue;
			a[j]++;
			T--;
		}
		Find(m);
		printf("%d ",hsh[i]);

	}
}