#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int olo[1000135],a[1000135],dp[1000135],qs[1000135],mp[1000135];
vector<pair<int,int> > p;
int main()
{
    int i,j,k,n,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        p.clear();
        for(i=1;i<=n;i++)
        {
            mp[i]=1;
            scanf("%d",&olo[i]);
            if(i>1)
                a[i]=olo[i]-olo[i-1];
        }
        for(i=2;i<=n;i++)
        {
            p.emplace_back(a[i],i);
        }
        sort(p.begin(),p.end());
        j=1;
        a[p[0].Y]=j;
        for(i=1;i<p.size();i++)
        {
            if(p[i].X!=p[i-1].X)
                j++;
            a[p[i].Y]=j;
        }
        dp[1]=1;qs[1]=1;
        for(i=2;i<=n;i++)
        {
            dp[i]=qs[i-1]-qs[mp[a[i]]-1];
            if(dp[i]<0)dp[i]+=1000000009;
            dp[i]%=1000000009;
            qs[i]=qs[i-1]+dp[i];
            qs[i]%=1000000009;
            mp[a[i]]=i;
        }
        qs[n]--;
        if(qs[n]<0)qs[n]+=1000000009;
        qs[n]%=1000000009;
        printf("%d\n",qs[n]);
    }
}
