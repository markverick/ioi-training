#include<bits/stdc++.h>
using namespace std;
char s[135];
int len;
int hsh[10];
map<vector<int>,int> mp;
int dp(vector<int> v,int sum)
{
    if(mp.find(v)!=mp.end())
        return mp[v];
    if(sum==31)
    {
        return 0;
    }
    int mn=1,i;
    for(i=0;i<6;i++)
    {
        if(v[i]<4)
        {
            v[i]++;
            if(sum+i+1<=31)
            mn=min(mn,dp(v,sum+i+1));
            v[i]--;
        }
    }
    return mp[v]=1-mn;
}
int main()
{
    int i,sum=0;
    vector<int> v;
    while(gets(s))
    {
        v.clear();
        sum=0;
        memset(hsh,0,sizeof hsh);
        len=strlen(s);
        for(i=0;i<len;i++)
        {
            sum+=s[i]-'0';
            hsh[s[i]-'0']++;
        }
        for(i=1;i<=6;i++)
        {
            v.emplace_back(hsh[i]);
        }
        printf("%s ",s);
        if(len%2==0)
        {
            if(dp(v,sum))
                printf("A\n");
            else
                printf("B\n");
        }
        else
        {
            if(dp(v,sum))
                printf("B\n");
            else
                printf("A\n");
        }
    }
}
