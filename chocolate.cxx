#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[135],out[135];
vector<int> v,vec;
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		out[i]=MI;
		scanf("%d",&a[i]);
		j=1;
		while(j<=a[i])
		{
			k=0;
			while(a[i]/(j+(1<<k))==a[i]/j)
			{
				j+=(1<<k);
				k++;
			}
			for(k=k;k>=0;k--)
			{
				if(a[i]/(j+(1<<k))==a[i]/j)
					j+=(1<<k);
			}
			v.emplace_back(a[i]/j);
			v.emplace_back(a[i]/j+1);
			// printf("%d ",a[i]/j);
			j++;
		}
		// printf("\n");
		v.emplace_back(a[i]+1);
	}
	v.emplace_back(1);
	sort(v.begin(),v.end());
	v.resize(unique(v.begin(),v.end())-v.begin());
	for(i=0;i<v.size();i++)
	{
		vec.clear();
		for(j=1;j<=n;j++)
		{
			vec.emplace_back(a[j]/v[i]);
		}
		sort(vec.begin(),vec.end());
		k=1;
		for(j=1;j<vec.size();j++)
		{
			if(vec[j]==vec[j-1])
				k++;
			else
			{
				out[k]=min(out[k],v[i]);
				k=1;
			}
		}
		out[k]=min(out[k],v[i]);
	}
	for(i=1;i<=n;i++)
	{
		if(out[i]<MI)
			printf("%d\n",out[i]);
		else
			printf("-1\n");
	}
}