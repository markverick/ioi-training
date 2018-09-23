#include<bits/stdc++.h>
using namespace std;

char str[200];
int main()
{
    int t;
    int i,j,k,ti;
    int len;
    gets(str);
    sscanf(str,"%d",&t);

    for(ti=1;ti<=t;ti++)
    {
        deque<char> st;
        gets(str);
        len=strlen(str);
        for(i=0;i<len;i++)
        {
           if(str[i]=='(')
           {
               st.push_back('(');
           }
           else if(str[i]==')')
           {
               if(st.empty())
               {
                   st.push_back('F');
                   break;
               }
               if(st.back()=='(')
               {
                   st.pop_back();
               }
               else if(st.back()=='[')
               {
                   st.pop_back();
               }
           }
           else if(str[i]==':')
           {
               if(str[i+1]=='(')
               {
                   st.push_front('[');
               }
               else if(str[i+1]==')')
               {
                   if(st.back()=='(')
                   {
                       st.pop_back();
                   }
               }
               i++;
           }
        }

        while(!st.empty())
        {
            if(st.front()=='[')
                st.pop_front();
            else
                break;
        }
        if(st.empty())
        {
            printf("WIN\n");
        }
        else
        {
            printf("FAIL\n");
        }
        memset(str,0,sizeof str);
        st.clear();
    }
}
