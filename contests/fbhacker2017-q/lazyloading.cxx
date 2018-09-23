#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
deque<int> dq;
int a[135];
int main()
{
	freopen("out2.txt","w",stdout);
	freopen("in2.txt","r",stdin);
	int t,n,i,j,k,T,cot=0,sm=0;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		dq.clear();
		cot=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(&a[1],&a[n+1]);
		for(i=1;i<=n;i++)
			dq.emplace_front(a[i]);
		while(!dq.empty())
		{
			sm=dq.front();
			j=sm;
			dq.pop_front();
			while(!dq.empty()&&sm<50)
			{
				sm+=j;
				dq.pop_back();
			}
			if(sm>=50)
				cot++;
		}
		printf("Case #%d: %d\n",t,cot);
	}
}