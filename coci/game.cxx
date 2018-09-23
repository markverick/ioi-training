#include<bits/stdc++.h>
using namespace std;
char s[100135];
set<int> st[30];
set<int> ::iterator it;
int main()
{
	int i,j,k,n;
	string v,u;
	scanf("%d",&n);
    scanf("%s",s+1);
    for(i=1;i<=n;i++)
    {
        st[s[i]-'a'].insert(-i);
    }
    for(i=n;i>=1;i--)
    {
        if(s[i])
        {
            st[s[i]-'a'].erase(-i);
            u.push_back(s[i]);
            s[i]=0;
            for(j=0;j<26;j++)
            {
                if(!st[j].empty())
                {
                    it=st[j].begin();
                    v.push_back(s[-*it]);
                    s[-*it]=0;
                    st[j].erase(it);
                    break;
                }
            }
        }
    }
    if(v<u)
        printf("DA\n");
    else
        printf("NE\n");
    for(i=0;i<v.size();i++)
        printf("%c",v[i]);

}
