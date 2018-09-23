#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int deg[70];
int hsh[70];
int all[70][70];
int n,m,st;
vector<int> path;
vector<int> adj[70];
void dfs(int idx,int lst)
{
    int i;
    //printf("%d\n",idx);
    for(i=0;i<adj[idx].size();i++)
    {
        if(adj[idx][i]!=lst&&hsh[adj[idx][i]]==0)
        {
            hsh[adj[idx][i]]=1;
            dfs(adj[idx][i],idx);
            path.emplace_back(adj[idx][i]);
        }
    }
//    if(path.size()==0)
//        path.emplace_back(idx,st);
}
int main()
{
    int T,t,i,j,k,a,b,c,d;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d %d",&a,&b,&d);
        adj[d].emplace_back(a);
        adj[a].emplace_back(b);
//        all[d][a]++;
//        all[a][d]++;
//        all[a][b]++;
//        all[b][a]++;
//        deg[a]+=2;deg[b]++;deg[d]++;
//        c=a;
    }
    int fu=0;
    for(i=1;i<=n;i++)
    {
        path.clear();
        memset(hsh,0,sizeof hsh);
        //hsh[i]=1;
        dfs(i,i);
        path.emplace_back(i);
        if(path.size()==n)
        {
            fu=1;
            printf("YES\n");
            for(i=path.size()-1;i>=0;i--)
            {
                printf("%d ",path[i]);
            }break;
        }
    }
    if(fu==0)printf("NO");
//           else for(i=path.size()-1;i>=0;i--)
//           {
//               printf("%d %d\n",path[i].first,path[i].second);
//           }
}
