#include<stdio.h>
#include<vector>
#define pb(x) push_back(x)
using namespace std;
vector<char> adj[500];
char str[10];
int chk[500];
int n,a,b;
void dfs(int node)
{
    int i;
    for(i=0;i<adj[node].size();i++)
    {
        chk[node]=1;
        dfs(adj[node][i]);
    }
    return;
}
int main()
{
    int t;
    int i,j,k;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%s",str);
        while(true)
        {
            memset(str,0,sizeof str);
            gets(str);
            if(str[0]=='\0')
            {
                break;
            }
            else
            {
                a=str[0]-'A';
                b=str[1]-'A';
                adj[a].pb(b);
                adj[b].pb(a);
            }
        }


    }
}
