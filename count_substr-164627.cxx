#include<bits/stdc++.h>
using namespace std;
string in;
vector<bool> cons;
queue<int> q;
int main()
{
	int T,i,j,k,n,len,cot;
	scanf("%d",&T);
	while(T--)
	{
	    cin >> in;
		scanf("%d",&n);
		len=in.size();
		cot=0;
		for(i=0;i<len;i++)
		{
			switch(in[i])
			{
				case 'a': case 'e': case 'i': case 'o': case 'u':
				cons.push_back(0);break;
				default: cons.push_back(1);break;
			}
		}
		for(i=0;i<n;i++)
		{
			q.emplace(cons[i]);
			if(cons[i]==1)
				 cot++;
		}
		k=0;long long sum=0;
		if(cot==n)
		{
			sum+=(len-i+1);
			k=1;
			//k=i-n+1;
		}

		for(i=n;i<=len;i++)
		{
			if(cot==n)
			{
				sum+=(i-n+1-k)*(len-i+1);
				k=i-n+1;
			}
			if(i==len)break;
			q.push(cons[i]);
			if(cons[i]==1)
			cot++;
			if(q.front()==1)
			cot--;
			q.pop();
		}
		printf("%lld\n",sum);
		while(!q.empty())
		q.pop();
		in.clear();
		cons.clear();
	}
}
