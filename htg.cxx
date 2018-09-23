#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
using namespace std;

int n;
int a[120000];
int main()
{
    while(scanf("%d",&n)&&n!=0)
    {
        long long mc=0;
        stack<pair<int,int> >st;
        int i,j,k,now,ome;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(st.empty())
                st.emplace(a[i],i);
            else if(a[i]>=st.top().X)
            {
                st.emplace(a[i],i);
            }
            else
            {
                now=0;
                while(!st.empty()&&a[i]<=st.top().X)
                {
                    mc=max(mc,st.top().X*(long long)(i-st.top().Y));
                    now=st.top().Y;
                    st.pop();
                }
                if(now)st.emplace(a[i],now);
                else st.emplace(a[i],i);
            }
        }
        while(!st.empty())
        {
            mc=max(mc,st.top().X*(long long)(i-st.top().Y));
            st.pop();
        }
        printf("%lld\n",mc);
    }
}
