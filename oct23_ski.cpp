#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int jum[2135][1135],s,t,n,g,mn=1000000000;
vector<pair<int,int> > adj[1135];
void dfs(int money,int idx)
{
    if(idx<=g)
    {
        mn=min(mn,money);
    }
    int i;
    for(i=0;i<adj[idx].size();i++)
    {
        if(money-adj[idx][i].Y>=0&&jum[money-adj[idx][i].Y][adj[idx][i].X]==0)
        {
            jum[money-adj[idx][i].Y][adj[idx][i].X]=1;
            dfs(money-adj[idx][i].Y,adj[idx][i].X);
        }
    }
    return;
}
int main()
{
    int i,j,k,P,m,a,b,c;
//    memset(jum,-1,sizeof jum);
    scanf("%d %d",&n,&g);
    scanf("%d",&P);
    for(i=1;i<=P;i++)
    {
        scanf("%d %d",&a,&b);
        adj[a].emplace_back(b,0);
    }
    scanf("%d",&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        adj[a].emplace_back(b,c);
    }
    scanf("%d %d",&s,&t);
    jum[t][s]=1;
    dfs(t,s);
    printf("%d",mn);

}
