#include<bits/stdc++.h>
#define PB emplace_back
using namespace std;
int n,m;
int Dlow[30135];
int Dnum[30135];
int C=1;
vector<int> adj[30135];
int pa[30135];
int ch[30135];
int fu=0;
void dfs(int idx)
{
    int i,j,k;
    Dnum[idx]=C++;
    Dlow[idx]=Dnum[idx];
    //printf("%d\n",idx);
    for(i=0;i<adj[idx].size();i++)
    {
        if(Dnum[adj[idx][i]]==0)
        {
            ch[idx]++;
            pa[adj[idx][i]]=pa[idx];
            dfs(adj[idx][i]);
            if(idx!=1&&Dlow[adj[idx][i]]>=Dnum[idx])
            {
                //printf("==%d\n",idx);
                fu=1;
                return;
            }
            Dlow[idx]=min(Dlow[adj[idx][i]],Dlow[idx]);
        }
        else if(pa[idx]!=adj[idx][i])
        {
            Dlow[idx]=min(Dnum[adj[idx][i]],Dlow[idx]);
        }
        if(fu==1)
            return;

    }
}
int main()
{
    int i,j,k,T,t,a,b;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {


        scanf("%d %d",&n,&m);
        C=1;
        fu=0;
        memset(ch,0,sizeof ch);
        memset(pa,0,sizeof pa);
        memset(Dlow,0,sizeof Dlow);
        memset(Dnum,0,sizeof Dnum);
        for(i=0;i<=n;i++)
        {
            adj[i].clear();
        }
        for(i=1;i<=m;i++)
        {
            scanf("%d %d",&a,&b);
            adj[a].PB(b);
            adj[b].PB(a);
        }
        dfs(1);
        if(fu==1||ch[1]>1)
            printf("YES\n");
        else
            printf("NO\n");
    }
}
