#include<bits/stdc++.h>
using namespace std;
int p[100135];
vector<int> adj[100135];
int dfs(int idx)
{
    int i;
    if(adj[idx].empty())
    {
        return 0;
    }
    vector<int> v;
    for(i=0;i<adj[idx].size();i++)
    {
        v.emplace_back(dfs(adj[idx][i]));
    }
    int cot=0,mc=0;
    if(adj[idx].size()>2)
    {
        sort(v.begin(),v.end());
        cot=0;
        for(i=v.size()-1;i>=1;i--)
        {
            cot++;
            v[i]+=cot;
            mc=max(mc,v[i]);
        }
        v[0]+=cot;
        mc=max(mc,v[0]);
    }
    else
    {
        return max(v[0],v[1])+1;
    }
    return mc;
}
int main()
{
    int n,i,j,k;
    scanf("%d",&n);
    for(i=2;i<=n;i++)
    {
        scanf("%d",&p[i]);
        adj[p[i]].emplace_back(i);
    }
    printf("%d",dfs(1));
}
