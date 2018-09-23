#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
map<int,int> hsh;
int a[100135];
vector<int> out[100135];
pair<int,int> p[100135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,m,i,j=1,k,cot=0,mn=MI;
	scanf("%d %d",&m,&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);\
		if(hsh[a[i]/m]==0)cot++;
		hsh[a[i]/m]++;
		p[i]=MP(a[i]%m,a[i]);
	}
	sort(&p[1],&p[n+1]);
	// for(i=1;i<=n;i++)
	// {
	// 	printf("%d %d\n",p[i].X,p[i].Y);;
	// }
	for(i=0;i<m;i++)
	{
		k=j;
		while(j<=n&&p[j].X<=i)
		{
			hsh[p[j].Y/m]--;
			if(hsh[p[j].Y/m]==0)
				cot--;
			if(hsh[p[j].Y/m-1]==0)
				cot++;
			hsh[p[j].Y/m-1]++;
			j++;
		}
		out[cot].emplace_back(i),k++;
		// printf("!%d %d\n",cot,j);
		mn=min(mn,cot);
	}
	printf("%d\n",mn);
	for(i=0;i<out[mn].size();i++)
	{
		printf("%d ",out[mn][i]+1);
	}
}