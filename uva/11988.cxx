#include<bits/stdc++.h>
using namespace std;
string str;
int len=0;
list<char> ls;
list<char> ::iterator it;;
int main()
{
    int i,j,k;
    while(cin >> str)
    {
        ls.clear();
        len=str.size();j=0;
        while( j<len&&(str[j]!='['&&str[j]!=']') )
        {
            ls.push_back(str[j]);
            j++;
        }
        it=ls.end();
        for(i=j;i<len;i++)
        {
            if(str[i]=='[')
            {
                it=ls.begin();
            }
            else if(str[i]==']')
            {
                it=ls.end();
            }
            else
            {
                ls.insert(it,str[i]);
                //it++;
            }
        }
        for(it=ls.begin();it!=ls.end();it++)
        {
            printf("%c",*it);
        }
        printf("\n");
    }

}
