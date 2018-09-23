#include<bits/stdc++.h>
using namespace std;
long long a[100135],dp[100135],lst[100135],qs[100135];
char s[100135];
stack<long long> st;
inline long long op(char x,char y)
{
    if(x=='('&&y==')')
        return 1;
    else if(x=='<'&&y=='>')
        return 1;
    else if(x=='{'&&y=='}')
        return 1;
    else if(x=='['&&y==']')
        return 1;
    return 0;
}
inline long long close(char x)
{
    if(x==')'||x==']'||x=='>'||x=='}')
        return 1;
    return 0;
}
int main()
{
    long long i,j,k,n,T,mc;
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld",&n);
        scanf("%s",s+1);
        for(i=0;i<=n+1;i++)
        {
            lst[i]=0;dp[i]=0;
        }
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
            qs[i]=qs[i-1]+a[i];
        }
        while(!st.empty())
            st.pop();
        for(i=1;i<=n;i++)
        {
            if(!st.empty())
            {
                if(op(s[st.top()],s[i]))
                {
                    lst[i]=st.top();
                    st.pop();
                    dp[i]=max(qs[i]-qs[lst[i]-1],dp[lst[i]-1]+qs[i]-qs[lst[i]-1]);

                }
                else
                {

                    st.emplace(i);
                }
            }
            else
            {
                st.emplace(i);
            }
        }
        mc=0;
        for(i=1;i<=n;i++)
        {
            mc=max(mc,dp[i]);
        }
        printf("%lld\n",mc);
    }

}
