#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
tuple<int,int,int,int> p[1135];
// start end weight
int st[1135],ed[1135],w[1135],id[1135];
pair<int,int> dp[1135];
// MAX TEEMA
int main()
{
    int n,i,j,k,a,b,c,d;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        p[i]=tie(a,b,c,i);
    }
    sort(&p[1],&p[n+1]);
    for(i=1;i<=n;i++)
    {
        tie(a,b,c,d)=p[i];
        w[i]=c;st[i]=a;ed[i]=b;id[i]=d;
    }
    for(i=0;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            if(st[j]>=ed[i])
            {
                if(dp[i].X+w[j]>=dp[j].X) //><=
                {
                    dp[j].Y=id[i];
                    dp[j].X=dp[i].X+w[j];
                }
            }
        }
    }
    stack<int> st;
    int mc=0,init=0;
    for(i=n;i>=0;i--)
    {
        if(dp[i].X>=mc)
        {
            init=i;
            mc=dp[i].X;
        }
    }
    printf("%d\n",mc);
    st.emplace(init);
    while(dp[init].Y!=0)
    {
        init=dp[init].Y;
        st.emplace(init);
    }
    printf("%d\n",st.size());
    while(!st.empty())
    {
        printf("%d ",st.top());
        st.pop();
    }
}
