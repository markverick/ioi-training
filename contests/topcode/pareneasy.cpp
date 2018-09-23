#include<bits/stdc++.h>
using namespace std;
char str[55];
int main()
{
    int len,i,j,k,mc=0;
    stack<char> st;
    scanf("%s",str);
    len=strlen(str);
    for(i=0;i<len;i++)
    {
        if(!st.empty()&&st.top()=='('&&str[i]==')')
        {
            st.pop();
        }
        else
        {
            st.emplace(str[i]);
        }
        mc=max(mc,(int)st.size());
    }
    printf("%d",mc);
}
