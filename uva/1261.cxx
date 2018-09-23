#include<bits/stdc++.h>
using namespace std;
string str;
unordered_map<string,int> jum;
int dp(string s)
{
    if(jum.find(s)!=jum.end())
        return jum[s];
    if(s.size()==0)
    {
        return 1;
    }
    else if(s.size()==1)
    {
        return 0;
    }
    string a,b;
    //cout << s << "\n";
    int mc=0,i,j,len=s.size(),fst,lst;
    for(i=1;i<len;i++)
    {
        if(s[i]==s[i-1])
        {
            fst=i-1;lst=len;
            for(j=i;j<len;j++)
            {
                if(s[j]!=s[j-1])
                {
                    //fu=1;
                    lst=j;
                    break;
                }
            }
            b=a;
            for(j=lst;j<len;j++)
            {
                b.push_back(s[j]);
            }
            mc=max(mc,dp(b));
        }
        a.push_back(s[i-1]);
    }
    return jum[s]=mc;
}
int main()
{
    int T,n,i,j,k,len,fst,lst,fu=0,fk=0;
    scanf("%d",&T);
    while(T--)
    {
        cin >> str;
        printf("%d\n",dp(str));
    }
}
