#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

stack<pair<long long,long long> > st;
// height,idx
long long h[100005];
int main()
{
    long long n,mc=0,i,tmp;
    while(scanf("%lld",&n)!=EOF)
    {
        while(!st.empty())st.pop();
        mc=0;
        if(n==0)
            return 0;
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&h[i]);
        }
        for(i=1;i<=n;i++)
        {
            if(st.empty()||st.top().X<=h[i])
                st.emplace(h[i],i);
            else
            {
                while((!st.empty())&&st.top().X>=h[i])
                {
                    mc=max(mc,(i-st.top().Y)*st.top().X );
                    tmp=st.top().Y;
                    st.pop();
                }
                st.emplace(h[i],tmp);
            }
        }
        while(!st.empty())
        {
            mc=max(mc,st.top().X*(n+1-st.top().Y));
            st.pop();
        }
        printf("%lld\n",mc);
    }
}
