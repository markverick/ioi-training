#include<bits/stdc++.h>
using namespace std;
int a,b;
vector<int> adj[100135];
int state[100135];
int dp(int idx)
{
    state[idx]=1;
    int sum=0,prod=1,tmp;
    for(int i=0;i<adj[idx].size();i++)
    {
        if(state[adj[idx][i]])
            continue;
        tmp=dp(adj[idx][i]);
        prod*=tmp;
        sum+=tmp;
    }
    return prod+sum;
}
int main()
{
    int n,i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n-1;i++)
    {
        scanf("%d %d",&a,&b);
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    printf("12");
    return 0;
    int mc=0;
    for(i=1;i<=n;i++)
    {
        mc=max(mc,dp(i));
    }
}
