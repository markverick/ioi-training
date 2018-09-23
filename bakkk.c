#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int n,m;
multiset<int> adj[531][531];
multiset<int>::iterator it;
priority_queue<tuple<int,int,int> > pq;
vector<int> v;
int dist[531],teema[531];
int dfs(int idx)
{
    if(idx==0)
    {
        return 0;
    }
    int i,j;
//    hsh[idx]=1;
    for(i=0;i<=n+1;i++)
    {
//        if(hsh[i]==1)
//            continue;
        if(idx==i)
            continue;
        for(j=0;j<adj[idx][i].size();j++)
        {
            if(adj[idx][i][j].Y>0)
            {
                adj[idx][i][j].Y--;
                return dfs(i)+adj[idx][i][j].X;
                break;
            }
        }
    }
    return 1000000000;
}
int main()
{
//    freopen("out.txt","w",stdout);
//    freopen("in.txt","r",stdin);
    int i,j,k,a,b,c,d,ck=1,u,w,T=0,fu,mn,Min;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        for(i=0;i<=n+1;i++)
        {
            for(j=0;j<=n+1;j++)
            {
                adj[i][j].clear();
            }
        }
        T++;
        memset(adj,0,sizeof adj);
        memset(teema,0,sizeof teema);
        adj[0][1].insert(0);
        adj[0][1].insert(0);
        adj[n][n+1].insert(0);
        adj[n][n+1].insert(0);
        for(i=1;i<=m;i++)
        {
            scanf("%d %d %d %d",&a,&b,&c,&d);
            adj[a][b].insert(c);
            adj[a][b].insert(c+d);
        }
        while(135)
        {
            v.clear();
            for(i=1;i<=n+1;i++)
                dist[i]=1000000000;
            dist[0]=0;
            pq.emplace(0,0,1000000000);
            Min=1000000000;
            while(!pq.empty())
            {
                tie(w,u,mn)=pq.top();
                w=-w;
                pq.pop();
                if(u==n+1)
                    Min=mn;
                for(i=0;i<=n+1;i++)
                {
                    if(i==u)
                        continue;
                    if(!adj[u][i].empty())
                    {
                        it=adj[u][i].begin();
                        if(w+*it<dist[i])
                        {
                            dist[i]=w+*it
                            pq.emplace(-dist[i],i,min(mn,*it));
                            teema[i]=u;
                        }
                        break;
                    }
                }
            }
            if(dist[n+1]==1000000000)
                break;
            j=n+1;
            while(j>0)
            {
                v.emplace_back(j);
                j=teema[j];
            }
            v.emplace_back(j);
            for(i=v.size()-1;i>0;i--)
            {
                adj[v[i]][v[i-1]].erase(adj[v[i]][v[i-1]].begin());
                adj[v[i-1]][v[i]].insert(Min);
            }
////            system("pause");
        }
//        for(i=0;i<=n+1;i++)
//        {
//            for(j=0;j<adj[n+1][i].size();j++)
//                printf("==%d\n",adj[n+1][i][j].Y);
//            printf("\n");
//        }
        int sum=dfs(n+1)+dfs(n+1);
        if(sum<1000000000)
            printf("Case %d: %d\n",T,sum);
        else
            printf("NO VALID WAY\n");
    }
}
