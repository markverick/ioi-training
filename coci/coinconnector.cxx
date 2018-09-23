#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;

int main()
{
//	freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	stack<long long> st;
	long long T,i,j,k,n,a,sum=0,mc=0;
	scanf("%lld",&T);
	while(T--)
    {
        scanf("%lld",&n);
        while(!st.empty())st.pop();
        sum=0;mc=0;
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&a);
            while(!st.empty()&&sum>=a)
            {
                sum-=st.top();
                st.pop();
            }
            sum+=a;
            st.emplace(a);
//            printf("%d",st.size());
            mc=max(mc,(long long)st.size());
        }
        printf("%lld\n",mc);
    }
}
