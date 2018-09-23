#include<bits/stdc++.h>
#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;
int n,m;
int id[500];
vector<char> adj[500];
char result[17];
char s,t;
int dfs(int idx,int bit,int C)
{
    if(idx==n)
    {
        if(__builtin_popcount(bit)==n)
            return 1;
        else
            return 0;
    }
    for(int i=0;i<adj[idx].size();i++)
    {
        if((bit|(1<<(id[adj[idx][i]]-1)))==bit )
            continue;
        result[C]=adj[idx][i];
        if(dfs(id[adj[idx][i]],bit|(1<<(id[adj[idx][i]]-1)),C+1))
            return 1;
    }
    return 0;
}
int main()
{
    int t,T,i,j,k;
    char a[3],b[3];
    scanf("%d",&T);
    for(k=1;k<=T;k++)
    {
        memset(id,0,sizeof id);
        memset(result,0,sizeof result);
        scanf("%d %d",&n,&m);
        for(i=0;i<=n;i++)
            adj[i].clear();
        for(i=1;i<=n;i++)
        {
            scanf("%s",a);
            if(i==1)
                s=a[0];
            else if(i==n)
                t=a[0];
            id[a[0]]=i;
        }
        for(i=1;i<=m;i++)
        {
            scanf("%s %s",a,b);
            adj[id[a[0]]].emplace_back(b[0]);
            adj[id[b[0]]].emplace_back(a[0]);
        }
        for(i=1;i<=n;i++)
            sort(adj[i].begin(),adj[i].end());
        result[0]=s;
        int bit=0;
        dfs(1,1,1);
        if(strlen(result)==n)
            printf("Case %d: %s\n",k,result);
        else
            printf("Case %d: impossible\n",k);
    }
}
