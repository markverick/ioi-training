#include<bits/stdc++.h>
using namespace std;
int hsh[333],state[333],n,x;
vector<int> adj[333];
int dfs(int idx,int cot)
{
    int i,j,c=0,v;
    if(cot>=x)
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
        v=adj[idx][i];
        if(hsh[v])
            continue;
        hsh[v]=1;
        int c=0;
        for(j=0;j<adj[v].size();j++)
        {
            if(hsh[adj[v][j]])
                c++;
        }
        if(c>=cot)
        {
            if(dfs(v,cot+1))
                return 1;
        }
        hsh[v]=0;
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
    x=n/4;
    for(i=1;i<=n;i++)
    {
        hsh[i]=1;
        if(dfs(i,0));
            break;
        hsh[i]=0;
    }
}
