#include<bits/stdc++.h>
using namespace std;
class ParenthesesDiv2Easy
{
    public:
    int getDepth(string str)
    {
        int len,i,mc=0;
        stack<char> st;
        len=str.size();
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
        return mc;
    }
};

