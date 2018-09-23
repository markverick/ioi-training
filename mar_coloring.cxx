#include<bits/stdc++.h>
using namespace std;
vector<int> adj[200135];
int color[200135],state[200135],C=2,ck;
queue<int> q;
int main()
{
    int n,i,j,k,a,b,u;
    scanf("%d %d",&n,&k);
    for(i=0;i<=n;i++)
        color[i]=1;
    while(135)
    {
        scanf("%d %d",&a,&b);
        if(a==-1&&b==-1)
        {
            break;
        }
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    for(j=1;j<=n;j++)
    {
        q.emplace(j);
        while(!q.empty())
        {
            u=q.front();
            q.pop();ck=0;
            state[u]=1;
            for(i=0;i<adj[u].size();i++)
            {
                if(state[adj[u][i]])continue;
//                if(color[adj[u][i]]==0)
//                    color[adj[u][i]]=C,ck=1;
                if(color[u]==color[adj[u][i]])
                    color[adj[u][i]]=C,ck=1;
                q.emplace(adj[u][i]);
            }
            if(ck)
                C++;
        }
    }
    for(i=1;i<=n;i++)
    {
        printf("%d\n",color[i]);
    }
}
