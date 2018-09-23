#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
pair<long long,long long> p[100135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	long long i,j,k,n,m;
	scanf("%lld %lld",&n,&m);
	for(i=1;i<=n;i++)
    {
        scanf("%lld %lld",&p[i].X,&p[i].Y);
    }
    sort(&p[1],&p[n+1]);
    stack<long long> st;
    long long sum=0;
    for(i=1;i<=n;i++)
    {
        if(p[i].Y==p[i-1].Y)
            continue;
        if(!st.empty())
        {
            j=st.top();
            while(!st.empty())
            {
                if(p[i].Y<=st.top())
                    st.pop();
                else
                    break;
            }
            sum+=max(0ll,j-p[i].Y);
        }
        st.emplace(p[i].Y);
    }
    if(!st.empty())
        sum+=st.top();
    printf("%lld",sum);
}
