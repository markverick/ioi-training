#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int x[2222],y[2222],d[2222];
vector<int> adj[2222];
vector<int> topo;
int state[2222];
void dfs(int idx)
{
    state[idx]=1;
    for(int i=0;i<adj[idx].size();i++)
    {
        if(state[adj[idx][i]])continue;
        dfs(adj[idx][i]);
    }
    topo.emplace_back(idx);
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,T,cot=0;
	scanf("%d",&T);
	while(T--)
    {
        topo.clear();
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            adj[i].clear();
        for(i=1;i<=n;i++)
        {
            scanf("%d %d %d",&x[i],&y[i],&d[i]);
            x[i]*=2;y[i]*=2;
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(i==j)continue;
                if(x[i]-d[i]<=x[j]&&x[i]+d[i]>=x[j]&&y[i]-d[i]<=y[j]&&y[i]+d[i]>=y[j])
                    adj[i].emplace_back(j);
            }
        }
        memset(state,0,sizeof state);
        for(i=1;i<=n;i++)
        {
            if(state[i])continue;
            dfs(i);
        }
//        for(i=topo.size()-1;i>=0;i--)
//            printf("%d ",topo[i]);
//        printf("\n");
        cot=0;
        memset(state,0,sizeof state);
        for(i=topo.size()-1;i>=0;i--)
        {
            if(state[topo[i]])continue;
            cot++;
            dfs(topo[i]);
        }
        printf("%d\n",cot);
    }
}
