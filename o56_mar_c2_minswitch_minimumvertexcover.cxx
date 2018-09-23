#include<bits/stdc++.h>
using namespace std;
set<int> adj[110000];
set<int>::iterator it;
int ck=0,n,m;
int result[110000],state[110000];
void dfs(int idx,int C)
{
    int i;
    if(idx==n+m+1)
    {
        for(i=1;i<C;i++)
        {
//            printf("%d ",result[i]);
            if(adj[result[i]].find(result[i+1])!=adj[result[i]].end())
            {
                adj[result[i]].erase(result[i+1]);
                adj[result[i+1]].insert(result[i]);
            }
        }
//        printf("\n");
//        system("pause");
        ck=1;
        return;
    }
    state[idx]=1;
    for(it=adj[idx].begin();it!=adj[idx].end();it++)
    {
        if(state[*it])
            continue;
        result[C+1]=*it;
        dfs(*it,C+1);
        if(ck==1)
            return;
    }
}
int main()
{
    int a,b,i,j,k;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
        adj[0].insert(i);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&a,&b);
        adj[a].insert(n+i);
        adj[b].insert(n+i);
    }
    for(i=n+1;i<=n+m;i++)
        adj[i].insert(n+m+1);
    ck=1;
    while(ck==1)
    {
        ck=0;
        memset(state,0,sizeof state);
        result[1]=0;
        dfs(0,1);
    }
    int sum=0;
//    printf("%d\n",adj[n+m+1].size());
//    for(it=adj[n+m+1].begin();it!=adj[n+m+1].end();it++)
//    {
//        printf("%d\n",*it-n);
//    }
    for(i=1;i<=n;i++)
    {
        printf("- - %d - -\n",i);
        for(it=adj[i].begin();it!=adj[i].end();it++)
            printf("%d\n",*it-n);
//        if(adj[i].find(0)!=adj[i].end())
//            sum++;
    }
}
