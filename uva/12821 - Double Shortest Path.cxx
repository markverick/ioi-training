#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int n,m;
multiset<int> adj[531][531];
multiset<int>::iterator it;
queue<int> q;
vector<int> v;
vector<int> out;
int dist[531],teema[531],hsh[531];
//int dfs(int idx)
//{
//    if(idx==0)
//    {
//        return 0;
//    }
//    int i,j,tmp;
//    for(i=0;i<=n+1;i++)
//    {
//        if(idx==i)
//            continue;
//        if(!adj[idx][i].empty())
//        {
//            tmp=*adj[idx][i].begin();
//            adj[idx][i].erase(adj[idx][i].begin());
//            return dfs(i)+tmp;
//        }
//    }
//    return 1000000000;
//}
int main()
{
//    freopen("out.txt","w",stdout);
//    freopen("in.txt","r",stdin);
    int i,j,k,a,b,c,d,ck=1,u,w,T=0,fu;
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
        out.clear();
        while(135)
        {
            memset(hsh,0,sizeof hsh);
            v.clear();
            for(i=1;i<=n+1;i++)
                dist[i]=1000000000;
            dist[0]=0;
            q.emplace(0);
            while(!q.empty())
            {
                u=q.front();
                q.pop();
                hsh[u]--;
                for(i=0;i<=n+1;i++)
                {
                    if(i==u)
                        continue;
                    if(adj[u][i].empty())
                        continue;
                    it=adj[u][i].begin();
                    if(dist[u]+*it<dist[i])
                    {
                        dist[i]=dist[u]+*it;
                        teema[i]=u;
                        if(hsh[i]==0)
                        {
                            q.emplace(i);
                            hsh[i]++;
                        }
                    }
                }
            }
            if(dist[n+1]==1000000000)
                break;
            out.emplace_back(dist[n+1]);
            j=n+1;
            while(j>0)
            {
                v.emplace_back(j);
                j=teema[j];
            }
            v.emplace_back(j);
            for(i=v.size()-1;i>0;i--)
            {
                it=adj[v[i]][v[i-1]].begin();

                adj[v[i-1]][v[i]].insert(-*it);
                adj[v[i]][v[i-1]].erase(it);
            }
        }
        sort(out.begin(),out.end());
        if(out.size()>=2)
            printf("Case %d: %d\n",T,out[0]+out[1]);
        else
            printf("Case %d: 0\n",T);
    }
}
