#include<bits/stdc++.h>
using namespace std;
class ParenthesesDiv2Medium
{
    public:
    vector<int> correct(string str)
    {
        vector<int> a;
        int len,i,mc=0;
        stack<char> st;
        len=str.size();
        for(i=0;i<len/2;i++)
        {
            if(str[i]==')')
                a.emplace_back(i);
        }
        for(i=len/2;i<len;i++)
        {
            if(str[i]=='(')
                a.emplace_back(i);
        }
        return a;
    }
};

