#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
vector<long long> fib;
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	long long i,j,k,n,x;
	scanf("%lld",&n);
	fib.emplace_back(1);
	fib.emplace_back(1);
	while(135)
	{
	    x=fib[fib.size()-1]+fib[fib.size()-2];
//	    printf("%lld\n",x);
	    if(x>n)
            break;
        fib.emplace_back(x);
	}
//	printf("%d %lld\n",fib.size(),fib[fib.size()-1]);
    x=-1;
    for(i=fib.size()-1;i>=0;i--)
    {
        if(n>=fib[i])
        {
            x=fib[i];
            n-=fib[i];
        }
    }
    printf("%lld",x);
}
