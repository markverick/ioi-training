#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int deg[70];
int hsh[70][70];
int all[70][70];
int n,st;
vector<pair<int,int> > path;
vector<int> adj[70];
void dfs(int idx)
{
    int i;
    for(i=0;i<adj[idx].size();i++)
    {
        if(hsh[idx][adj[idx][i]]<all[idx][adj[idx][i]])
        {
            hsh[idx][adj[idx][i]]++;
            hsh[adj[idx][i]][idx]++;
            dfs(adj[idx][i]);
            path.emplace_back(idx,adj[idx][i]);
        }
    }
//    if(path.size()==0)
//        path.emplace_back(idx,st);
}
int main()
{
    int T,t,i,j,k,a,b,c;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        if(t>1)
            printf("\n");
        scanf("%d",&n);
        memset(deg,0,sizeof deg);
        memset(hsh,0,sizeof hsh);
        memset(all,0,sizeof all);
        //path.clear();
        path.clear();
        for(i=1;i<=55;i++)
        {
            adj[i].clear();
        }
        for(i=1;i<=n;i++)
        {
            scanf("%d %d",&a,&b);
            adj[a].emplace_back(b);
            adj[b].emplace_back(a);
            all[a][b]++;
            all[b][a]++;
            deg[a]++;deg[b]++;
            c=a;
        }
        int fu=0;st=-1;
        for(i=1;i<=50;i++)
        {
            if(deg[i]%2==1)
            {
                fu++;st=i;
            }
        }
        if(fu!=0&&fu!=2)
        {
            printf("Case #%d\nsome beads may be lost\n",t);
        }
        else
        {
            if(fu==2)
            {
                dfs(st);
            }
            else
            {
                st=c;
                dfs(c);
            }
            printf("Case #%d\n",t);
            if(path.size()!=n||path[path.size()-1].X!=path[0].Y)
            {
                printf("some beads may be lost\n");
            }
//            else for(i=path.size()-1;i>=0;i--)
//            {
//                printf("%d %d\n",path[i].first,path[i].second);
//            }

            else for(i=path.size()-1;i>=0;i--)
            {
                printf("%d %d\n",path[i].X,path[i].Y);
            }
        }
    }
}
