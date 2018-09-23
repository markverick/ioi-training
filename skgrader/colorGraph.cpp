#include<stdio.h>
#include<vector>
using namespace std;
int n,k;
char result[120];
vector<int> adj[120];

int dfs(int vert,char color)
{
    if(result[vert]=='b')
    {
        return 0;
    }
}
int main()
{
    int T,t,i,j,k;
    scanf("%d",&T);
    for(t=0;t<T;t++)
    {
        int a,b;
        scanf("%d %d",&n,&k);
        for(i=0;i<k;i++)
        {
            memset(result,0,sizeof result);
            scanf("%d %d",&a,&b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int hi=0;
        for(i=0;i<n;i++)
        {
            hi=max(hi,dfs(i));
        }
    }
}
