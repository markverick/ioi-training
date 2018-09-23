#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> adj[15000],adk[15000],adG[15000],adR[15000],v;
int groupnai[15000];
int hsh[15000];
int val[15000];
int ord[15000];
int mn=0,mc=0;
queue<int> q;
vector<vector<int> >scc;
vector<int> emp;
vector<pair<int,int> > lst;
void dfs(int idx)
{
    //printf("F");
    hsh[idx]=1;
    for(int i=0;i<adk[idx].size();i++)
    {
        if(hsh[adk[idx][i]])
            continue;
        dfs(adk[idx][i]);
    }
    scc[scc.size()-1].emplace_back(idx);
}
void dep(int idx)
{
    hsh[idx]=1;
    for(int i=0;i<adj[idx].size();i++)
    {
        if(hsh[adj[idx][i]])
            continue;
        dep(adj[idx][i]);
    }
    v.emplace_back(idx);
}
int main()
{
    int i,j,k,u,a,b;
    scanf("%d %d",&n,&m);
    for(i=0;i<=n;i++)
        val[i]=1000000000;
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&a,&b);
        adj[a].emplace_back(b);
        adk[b].emplace_back(a);
    }
    for(i=0;i<n;i++)
    {
        if(hsh[i])
            continue;
        dep(i);
    }
    memset(hsh,0,sizeof hsh);
    for(i=v.size()-1;i>=0;i--)
    {
        if(hsh[v[i]]==1)
            continue;
        scc.emplace_back(emp);
        dfs(v[i]);
    }
    for(i=0;i<scc.size();i++)
    {
        for(j=0;j<scc[i].size();j++)
        {
            groupnai[scc[i][j]]=i;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<adj[i].size();j++)
        {
            adG[groupnai[i]].emplace_back(groupnai[adj[i][j]]);
            adR[groupnai[adj[i][j]]].emplace_back(groupnai[i]);
        }
    }
    for(i=0;i<scc.size();i++)
    {
        auto it = unique (adG[i].begin(), adG[i].end());
        adG[i].resize(distance(adG[i].begin(),it) );
        it = unique (adR[i].begin(), adR[i].end());
        adR[i].resize(distance(adR[i].begin(),it) );
    }
    memset(hsh,0,sizeof hsh);
    for(i=0;i<=n;i++)
    {
        if(adR[i].size()==0||(adR[i].size()==1&&adR[i][0]==i) )
        {
            if(ord[i]==0)
            {
                q.emplace(i);
                ord[i]=1;
                while(!q.empty())
                {
                    u=q.front();
                    q.pop();
                    //hsh[u]=1;
                    //printf("%d %d\n",u,ord[u]);
                    for(j=0;j<adG[u].size();j++)
                    {
                        if(adG[u][j]==u)
                            continue;
                        if(ord[u]+1>ord[adG[u][j]])
                        {
                            ord[adG[u][j]]=max(ord[adG[u][j]],ord[u]+1);
                            hsh[adG[u][j]]=1;
                            q.emplace(adG[u][j]);
                            hsh[adG[u][j]]=0;
                        }
                    }
                }
            }
        }
    }
    for(j=0;j<scc.size();j++)
    {
        hsh[ord[j]]+=scc[j].size();
    }
    for(i=1;i<=n;i++)
    {
        if(hsh[i]>0)
            printf("%d ",hsh[i]);
    }
}
