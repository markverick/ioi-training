#include<bits/stdc++.h>
using namespace std;
map<string,set<int> > mp;
char c[22];
string a[100135],b[100135];
int main()
{
    int i,j,k,n,len;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%s",c);
        len=strlen(c);
        for(j=7;j<len;j++)
        {
            if(c[j]=='/')
            {
                break;
            }
            a[i].push_back(c[j]);
        }
        for(j=j+1;j<len;j++)
        {
            b[i].push_back(c[j]);
        }
        mp[a[i]].insert(b[i]);
    }
}
