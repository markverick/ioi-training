#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int n,m;
vector<int> adj[10135],adT[10135];
int state[10135],jum[10135],ex=0,poss[10135];
int dp(int idx)
{
    if(jum[idx]>=0)
        return jum[idx];
    if(idx==2)
        return 1;
    int sum=0,i;
    for(i=0;i<adj[idx].size();i++)
    {
        if(poss[adj[idx][i]]==0)
            continue;
        sum+=dp(adj[idx][i]);
        if(sum>=1000000000)
        {
            ex=1;
            sum%=1000000000;
        }
    }
    return jum[idx]=sum;
}
void Fill(int idx)
{
    int i;
    poss[idx]=1;
    for(i=0;i<adT[idx].size();i++)
    {
        if(poss[adT[idx][i]])
            continue;
        Fill(adT[idx][i]);
    }
}
int dfs(int idx)
{
    int mc=0,i;
    state[idx]=1;
    for(i=0;i<adj[idx].size();i++)
    {
        if(poss[adj[idx][i]]==0)
            continue;
        if(state[adj[idx][i]]==1)
            return 1;
        else if(state[adj[idx][i]]==2)
            continue;
        mc=max(mc,dfs(adj[idx][i]));
    }
    state[idx]=2;
    return mc;
}
int main()
{
    memset(jum,-1,sizeof jum);
	int i,j,k,a,b;
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;i++)
    {
        scanf("%d %d",&a,&b);
        adj[a].emplace_back(b);
        adT[b].emplace_back(a);
    }
//    for(i=1;i<=n;i++)
//    {
//        sort(adj[i].begin(),adj[i].end());
//        auto it=unique(adj[i].begin(),adj[i].end());
//        adj[i].resize(distance(adj[i].begin(),it));
//    }
    Fill(2);
//    for(i=1;i<=n;i++)
//    {
//        if(poss[i])
//            printf("%d\n",i);
//    }
    if(dfs(1)==1)
    {
        printf("inf");
        return 0;
    }
//    system("pause");
    int out=dp(1);
    if(ex)
        printf("%09d",out);
    else
        printf("%d",out);
}
