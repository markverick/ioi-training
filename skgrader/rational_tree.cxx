#include<bits/stdc++.h>
using namespace std;
stack<unsigned long long> st;
unsigned long long fx(unsigned long long x,unsigned long long y)
{
    if(x==1&&y==1)
    {
        return 1;
    }
    if(x>y)
        return fx(x-y,y)*2+1;
    else
        return fx(x,y-x)*2;
}
int main()
{
    unsigned long long T,i,j,k,ch,n,x,y,a;
    scanf("%llu",&T);
    while(T--)
    {
        scanf("%llu",&ch);
        if(ch==1)
        {
            scanf("%llu",&n);
            while(n>0)
            {
                st.emplace(n%2);
                n/=2;
            }
            st.pop();
            x=1;y=1;
            while(!st.empty())
            {
                a=st.top();
                st.pop();
                if(a==1)
                    x=(x+y);
                else
                    y=(x+y);
            }
            printf("%llu/%llu\n",x,y);
        }
        else
        {
            scanf("%llu %llu",&x,&y);
            printf("%llu\n",fx(x,y));
        }
    }
}
