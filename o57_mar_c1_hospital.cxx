#include<bits/stdc++.h>
using namespace std;
vector<long long> adj[100135];
vector<long long> rim;
long long num[100135];
queue<long long> q;
int main()
{
    long long n,i,j,k,a,b,u;
    scanf("%lld",&n);
    for(i=1;i<n;i++)
    {
        scanf("%lld %lld",&a,&b);
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    num[1]=1;
    if(adj[1].size()==1)
    {
        rim.emplace_back(1);
    }
    q.emplace(1);
    long long fu=0;
    while(!q.empty())
    {
        fu=0;
        u=q.front();
        q.pop();
        for(i=0;i<adj[u].size();i++)
        {
            if(num[adj[u][i]])
                continue;
            num[adj[u][i]]=num[u]+1;
            fu=1;
            q.emplace(adj[u][i]);
        }
        if(fu==0)
        {
            rim.emplace_back(u);
        }
    }
    memset(num,0,sizeof num);
    for(i=0;i<rim.size();i++)
    {
        num[rim[i]]=1;
        q.emplace(rim[i]);
    }
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(i=0;i<adj[u].size();i++)
        {
            if(num[adj[u][i]])
                continue;
            q.emplace(adj[u][i]);
            num[adj[u][i]]=num[u]+1;
        }
    }
    long long mc=0;
    for(i=1;i<=n;i++)
    {
        mc=max(mc,num[i]);
    }
    for(i=1;i<=n;i++)
    {
        if(num[i]==mc)
        {
            u=i;
            break;
        }
    }
    memset(num,0,sizeof num);
    num[u]=1;
    q.emplace(u);
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(i=0;i<adj[u].size();i++)
        {
            if(num[adj[u][i]])
                continue;
            num[adj[u][i]]=num[u]+1;
            q.emplace(adj[u][i]);
        }
    }
    long long sum=0;
    for(i=1;i<=n;i++)
    {
        sum+=num[i]-1;
    }
    printf("%lld",sum);
}
