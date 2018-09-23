#include<bits/stdc++.h>
using namespace std;
//LONG LONG
char s[55][55];
vector<long long> v;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	long long T,t,i,j,k,n,m,p;
	scanf("%lld",&T);
	for(t=1;t<=T;t++)
	{
		v.clear();
		scanf("%lld %lld %lld",&n,&m,&p);
		p--;
		for(i=0;i<n;i++)
		{
			scanf("%s",s[i]);
		}
		i=p%n;
		while(m--)
		{
			v.emplace_back(i);
			i=(i+1)%n;
		}
		sort(v.begin(),v.end());
		printf("Case #%lld: ",t);
		for(i=0;i<v.size();i++)
			printf("%s ",s[v[i]]);
		printf("\n");
	}
}