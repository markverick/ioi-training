#include<bits/stdc++.h>
using namespace std;
list<string> ls;
list<string> ::iterator it;
int main()
{
    int n,i,j,k;
    scanf("%d",&n);
    it=ls.begin();
    char ch[3];
    string in;
    for(i=1;i<=n;i++)
    {
        scanf("%s",ch);
        switch (ch[0])
        {
        case 'l':
            if(it!=ls.begin())
                it--;
            break;
        case 'r':
            if(it!=ls.end())
                it++;
            break;
        case 'i':
            cin >> in;
            ls.insert(it,in);
            break;
        case 'b':
            if(ls.empty()||it==ls.begin())
            {
                continue;
            }
            it--;
            it=ls.erase(it);
            break;
        case 'd':
            if(ls.empty()||it==ls.end())
                continue;
            it=ls.erase(it);
            break;
        }
    }
    for(it=ls.begin();it!=ls.end();it++)
    {
        cout << *it << " ";
    }
}
