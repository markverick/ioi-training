#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int hsh[100135];
vector<int> prm;
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k;
	for(i=2;i<=100000;i++)
	{
		if(hsh[i])continue;
		prm.emplace_back(i);
		for(j=i;j<=100000;j+=i)
			hsh[j]=1;
	}
	for(i=1;i<=n;i++)
	{
		k=i;
		for(j=0;j<prm.size();j++)
		{
			if(prm[j]*prm[j]>k)
				break;
			if(k%prm[j]==0)
				v.emplace_back(prm[j]);
			while(k%prm[j]==0)
			{
				k/=prm[j];
			}
		}
		sort(v.begin(),v.end());
		if(k>=2) v.emplace_back(k);
		tot[i]=i;
		for(j=0;j<v.size();j++)
		{
			tot[i]/=v[j];
			tot[i]
		}
	}
	scanf("%d",&n);
}