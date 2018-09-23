#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
#define PB emplace_back
#define X first
#define Y second
using namespace std;
vector<int> adj[500005];
vector<int> adjG[500005];
vector<int> group[500005];
stack<int> stk;
int money[500005];
bool chk[500005];
int moneyG[500005];
int groupNai[500005];
int num[500005];
vector<int> pubLst;
int low[500005];
int T=1,C=1,S,P,n,m;
bool state[500005];
//bool isPubG[500135];
priority_queue<pair<int,int> >pq;
int d[500005];
inline void dfs(int idx)
{
    num[idx]=low[idx]=T++;
    stk.emplace(idx);
    chk[idx]=1;
    int i;
    for(i=0;i<adj[idx].size();i++)
    {
        if(num[adj[idx][i]]==0)
        {
            dfs(adj[idx][i]);
            low[idx]=min(low[idx],low[adj[idx][i]]);
        }
        else if(chk[adj[idx][i]]==1)
        {
            low[idx]=min(low[idx],num[adj[idx][i]]);
        }
    }
    if(low[idx]==num[idx])
    {
        while(!stk.empty()&&stk.top()!=idx)
        {
            group[C].PB(stk.top());
            chk[stk.top()]=0;
            stk.pop();
        }
        if(!stk.empty())
        {
            group[C].PB(stk.top());
            chk[stk.top()]=0;
            stk.pop();
        }
        C++;
    }
    state[idx]=1;
}

int main()
{
    int i,j,k,a,b;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&a,&b);
        adj[a].PB(b);
    }
    for(i=1;i<=n;i++)
    {
        scanf("%d",&money[i]);
    }
    scanf("%d %d",&S,&P);
    for(i=1;i<=P;i++)
    {
        scanf("%d",&a);
        pubLst.PB(a);
    }
    dfs(S);
    for(i=1;i<C;i++)
    {
        for(j=0;j<group[i].size();j++)
        {
            groupNai[group[i][j]]=i;
            moneyG[i]+=money[group[i][j]];
            //printf("%d ",group[i][j]);
        }
        //printf("MoneyG[%d] = %d\n",i,moneyG[i]);
    }
    for(i=1;i<=n;i++)
    {
        for(j=0;j<adj[i].size();j++)
        {
            //adjG[groupNai[i]].insert(groupNai[adj[i][j]]);
            adjG[groupNai[i]].emplace_back(groupNai[adj[i][j]]);
        }
    }
    /*for(i=1;i<=n;i++)
    {
        if(isPub[i]==1)
            isPubG[groupNai[i]]=1;
    }*/
    /*for(i=1;i<C;i++)
    {
        for(auto it=adjG[i].begin();it!=adjG[i].end();it++)
        {
            printf("%d => %d\n",i,*it);
        }
        printf("======\n");
    }*/
    for(i=1;i<C;i++)
    {
        auto it=unique(adjG[i].begin(),adjG[i].end());
        adjG[i].resize(distance(adjG[i].begin(),it) );
    }
    pq.emplace(moneyG[groupNai[S]],groupNai[S]);
    int u,w,v;
    while(!pq.empty())
    {
        w=pq.top().X;
        u=pq.top().Y;
        pq.pop();
        //printf("%d %d\n",w,u);
        for(i=0;i!=adjG[u].size();i++)
        {
            v=adjG[u][i];
            if(v!=u&&d[v]<w+moneyG[v])
            {
                d[v]=w+moneyG[v];
                pq.emplace(w+moneyG[v],v);
            }
        }
    }
    int mc=0;
    for(i=0;i<pubLst.size();i++)
    {
        mc=max(mc,d[groupNai[pubLst[i]]]);
    }
    printf("%d",mc);
}
