#include<bits/stdc++.h>
using namespace std;
int a[100135],b[100135],d[100135],color[100135];
vector<int> adj[100135],x,y;
int C=1;
void dfs(int idx)
{
    color[idx]=C;
    for(int i=0;i<adj[idx].size();i++)
    {
        if(color[adj[idx][i]]!=0)
            continue;
        dfs(adj[idx][i]);
    }
}
int main()
{
    int n,i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&d[i]);
    }
    for(i=1;i<=n-2;i++)
    {
        scanf("%d %d",&a[i],&b[i]);
        adj[a[i]].emplace_back(b[i]);
        adj[b[i]].emplace_back(a[i]);
    }
    for(i=1;i<=n;i++)
    {
        if(color[i]==0)
        {
            //color[i]=C;
            dfs(i);
            C++;
        }
    }
    for(i=1;i<=n;i++)
    {
        if(color[i]==1)
            x.emplace_back(d[i]);
        else
            y.emplace_back(d[i]);
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    int mn=1000000005;
    for(i=0;i<x.size();i++)
    {
        auto it=lower_bound(y.begin(),y.end(),x[i]);
        if(it!=y.end())
            mn=min(mn,abs(*it-x[i]));
        if(it!=y.begin())
        {
            it--;
            mn=min(mn,abs(x[i]-*it) );
        }
    }
    printf("%d",mn);
//    for(i=1;i<=n;i++)
//    {
//        printf("%d\n",color[i]);
//    }
}
