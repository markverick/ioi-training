#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
queue<int> q;
int pw[105][105],now[105],res[105];
vector<pair<int,int> > vec[105];
int main()
{
    int n,m,i,j,u,idx,w;
    memset(now,-1,sizeof now);
    scanf("%d",&n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&pw[i][j]);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            vec[i].emplace_back(-pw[i][j],j);
        sort(vec[i].begin(),vec[i].end());
        q.push(i);
    }
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        if(vec[u].size()==0)
            continue;
        w=vec[u][vec[u].size()-1].Y;
        vec[u].pop_back();
        if(now[w]==-1)
        {
            now[w]=u;
            res[u]=w;
        }
        else if(pw[now[w]][w]<pw[u][w])
        {
            q.push(now[w]);
            now[w]=u;
            res[u]=w;
        }
        else
            q.push(u);
    }
    for(i=0;i<n;i++)
        printf("%d ",res[i]+1);

}
