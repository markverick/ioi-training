#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[100135],b[100135],p[100135],fs[100135],ls[100135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,m,i,j,k;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	{
		fs[i]=2;ls[i]=1000000;
		scanf("%d",&p[i]);
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d %d",&a[i],&b[i]);
	}
	while(135)
	{
		v.clear();
		for(i=1;i<=n;i++)v.emplace_back(i);
		for(i=1;i<=m;i++)
		{
			for(i=0;i<v.size();i+=a*b)
			{
				mc=0;
				for(k=i;k<i+a*b;k+=a)
				{
					mc=max(mc,a[v[k]])
				}
				for(k=i;k<i+a*b;k+=a)
				{
					md=(fs[v[k]]+ls[v[k]])/2;
					if(md<mc)
						fk[v[k]]=1;
					else
					{
						
					}
				}
			}
			
		}
	}
}