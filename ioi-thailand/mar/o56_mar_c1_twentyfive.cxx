#include<bits/stdc++.h>
using namespace std;
int hsh[333],state[333],n,x;
vector<int> adj[333];
int dfs(int idx,int cot)
{
    int i,c=0;
    for(i=0;i<adj[idx].size();i++)
    {
        if(hsh[adj[idx][i]])
        {
            c++;
        }
    }
    if(c<x-cot)
        return 0;
    if(cot<=1)
    {
        int sum=0;
        for(i=1;i<=n;i++)
        {
            sum+=hsh[i];
        }
        printf("%d\n",sum);
        for(i=1;i<=n;i++)
        {
            if(hsh[i])
                printf("%d ",i);
        }
        return 1;
    }
    for(i=0;i<adj[idx].size();i++)
    {
        if(state[adj[idx][i]])
            continue;
        state[adj[idx][i]]=1;
        hsh[adj[idx][i]]=1;
        if(dfs(adj[idx][i],cot-1))
            return 1;
        hsh[adj[idx][i]]=0;
        state[adj[idx][i]]=0;
    }
    return 0;
}
int main()
{
    int i,j,k,a,b;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        for(j=1;j<=a;j++)
        {
            scanf("%d",&b);
            adj[i].emplace_back(b);
            adj[b].emplace_back(i);
        }
    }
    x=(n-1)/4+1;
    for(i=1;i<=n;i++)
    {
        state[i]=1;
        hsh[i]=1;
        if(dfs(i,x));
            break;
        hsh[i]=0;
        state[i]=0;    }
}
