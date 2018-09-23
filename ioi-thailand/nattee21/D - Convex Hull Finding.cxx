#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
#define S2 st[st.size()-1]
#define S1 st[st.size()-2]
#define S3 v[i].Y
using namespace std;
int x[531],y[531];
vector<pair<pair<double,int>,int> > v;
vector<int> st;
int lr(int a1,int b1,int a2,int b2)
{
	if(a1*b2-a2*b1>0)
		return 1;
	return 0;
}
int main()
{
	// freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int T,i,j,k,sta,mn,n,mc;
	scanf("%d",&T);
	printf("%d\n",T);
	while(T--)
	{
		st.clear();
		v.clear();
		scanf("%d",&n);
		mn=MI;mc=MI;
		for(i=1;i<=n;i++)
		{
			scanf("%d %d",&x[i],&y[i]);
			if(i==n)break;
			mn=min(mn,y[i]);
		}
		n--;
		for(i=1;i<=n;i++)
		{
			if(y[i]!=mn)continue;
			if(mc>x[i])mc=x[i],sta=i;
		}
		if(T)
			scanf("%*d");
		for(i=1;i<=n;i++)
		{
			if(i==sta)continue;
			v.emplace_back(MP(atan2(y[i]-y[sta],x[i]-x[sta]),x[i]),i);
		}
		sort(v.begin(),v.end());
		st.emplace_back(sta);
		st.emplace_back(v[0].Y);
		for(i=1;i<v.size();i++)
		{
			while(st.size()>=2&&!lr(x[S2]-x[S1],y[S2]-y[S1],x[S3]-x[S1],y[S3]-y[S1]))
			{
				st.pop_back();
			}
			st.emplace_back(v[i].Y);
		}
		printf("%d\n",st.size()+1);
		for(i=0;i<st.size();i++)
		{
			printf("%d %d\n",x[st[i]],y[st[i]]);
		}
		printf("%d %d\n",x[sta],y[sta]);
		if(T)
			printf("-1\n");
	}
}