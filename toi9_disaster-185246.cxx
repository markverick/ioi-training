#include<bits/stdc++.h>
#define PB emplace_back
using namespace std;
vector<int> adj[30];
int deg[30];
int hsh[30][30];
vector<int> path;
void dfs(int idx)
{
    int i;
    for(i=0;i<adj[idx].size();i++)
    {
        if(hsh[idx][adj[idx][i]]==0)
        {
            hsh[idx][adj[idx][i]]=1;
            hsh[adj[idx][i]][idx]=1;
            dfs(adj[idx][i]);
            path.PB(idx);
        }
    }
    if(path.size()==0)
    {
        path.PB(idx);
    }
}
int main()
{
    int n,i,j,k;
    char ch[4];
    scanf("%d",&n);
    int xx=0;
    for(i=0;i<n;i++)
    {
        scanf("%s",ch);
        xx=ch[0]-'A';
        adj[ch[1]-'A'].PB(ch[0]-'A');
        adj[ch[0]-'A'].PB(ch[1]-'A');
        deg[ch[0]-'A']++;
        deg[ch[1]-'A']++;
    }
    int fu=1;
    for(i=0;i<26;i++)
    {
        if(deg[i]%2==1)
        {
            //printf("%c\n",i+'A');
            dfs(i);
            fu=0;
            break;
        }
    }
    if(fu==1)
    {
        dfs(xx);
    }
    for(i=0;i<path.size();i++)
    {
        printf("%c ",path[i]+'A');
    }
}
