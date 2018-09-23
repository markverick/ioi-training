#include<bits/stdc++.h>
using namespace std;
char str[1135];
vector<stack<char> > st;
stack<char> emp;
int main()
{
    int n,i,j,k,idx,fu=0,len,T=0;
    while(scanf("%s",str)!=EOF)
    {
        T++;
        if(str[0]>='a'&&str[0]<='z')
            return 0;
        len=strlen(str);
        st.clear();
        st.emplace_back(emp);
        for(i=0;i<len;i++)
        {
            fu=0;
            for(j=0;j<st.size();j++)
            {
                if(st[j].empty()||str[i]<=st[j].top())
                {
                    st[j].emplace(str[i]);
                    fu=1;
                    break;
                }
            }
            if(fu==0)
            {
                st.emplace_back(emp);
                st[st.size()-1].emplace(str[i]);
            }
        }
        printf("Case %d: %d\n",T,st.size());
    }
}
