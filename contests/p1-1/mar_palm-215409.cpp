#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> adj[5135];
unordered_map<int,int> jum[5135][3];
int dp(int idx,int use,int p,int q)
{
    if(jum[idx][use].find(q)!=jum[idx][use].end())
        return jum[idx][use][q];
    int mn=1000000000,i,j,sum=0,fu=0;
    if(use==0)
    {
        for(i=0;i<adj[idx].size();i++)
        {
            if(adj[idx][i]==p)
                continue;
            fu=1;
            mn=min(mn,dp(idx,1,p,adj[idx][i])+dp(adj[idx][i],1,idx,idx)+1);
        }
    }
    else
    {
        for(i=0;i<adj[idx].size();i++)
        {
            if(adj[idx][i]==p||adj[idx][i]==q)
                continue;
            sum=0;
            for(j=0;j<adj[idx].size();j++)
            {
                if(adj[idx][j]==p||adj[idx][j]==q)
                    continue;
                fu=1;
                if(i==j)
                {
                    sum+=dp(adj[idx][j],1,idx,idx);
                }
                else
                {
                    sum+=dp(adj[idx][j],0,idx,idx);
                }
            }
            mn=min(mn,sum);
        }
    }
    if(fu==0)
    {
        if(use==1)
            return 0;
        else
            return 1;
    }
    return jum[idx][use][q]=mn;
}
int main()
{
    int i,j,k,a,b;
    scanf("%d",&n);
    for(i=1;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    printf("%d",dp(1,0,0,0));
}
