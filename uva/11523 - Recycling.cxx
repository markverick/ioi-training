#include<bits/stdc++.h>
using namespace std;
string s[135];
int a[135],hsh[135],jum[135][135],n;
vector<string> v;
unordered_map<string,int> mp;
int dp(int fst,int lst)
{
    if(jum[fst][lst]>=0)
        return jum[fst][lst];
    if(fst>lst)
        return 0;
    int i,j,k,mn;
    mn=1+dp(fst+1,lst);
    for(i=fst+1;i<=lst;i++)
    {
        if(a[i]==a[fst])
        {
            mn=min(mn,dp(fst+1,i-1)+dp(i,lst));
        }
    }
    return jum[fst][lst]=mn;
}
int main()
{
    int i,j,k,T,prev,t=0;
    cin >> T;
    while(T--)
    {
        t++;
        cin >> n;
        mp.clear();
        for(i=1;i<=n;i++)
            s[i].clear();
        v.clear();
        memset(hsh,0,sizeof hsh);
        memset(jum,-1,sizeof jum);
        for(i=1;i<=n;i++)
        {
            cin >> s[i];
            v.emplace_back(s[i]);
        }
        sort(v.begin(),v.end());
        auto it=unique(v.begin(),v.end());
        v.resize(distance(v.begin(),it));

        for(i=0;i<v.size();i++)
        {
            mp[v[i]]=i;
            if(v[i][0]>='A'&&v[i][0]<='Z')
                hsh[i]=1;
        }
        for(i=1;i<=n;i++)
        {
            a[i]=mp[s[i]];
        }
        int sum=0;
        for(i=1;i<=n;i++)
        {
            if(hsh[a[i]]==0)
            {
//                printf("!%d\n",i);
                for(j=i+1;j<=n;j++)
                {
                    if(hsh[a[j]])
                    {
//                        printf("%d %d\n",i,j-1);
                        sum+=dp(i,j-1);
                        i=j;
                        break;
                    }
                }
                if(j==n+1)
                {
//                    printf("%d %d\n",i,n);
                    sum+=dp(i,n);
                    i=j;
                    break;
                }
            }
        }
        printf("Case %d: %d\n",t,sum);
    }
}
