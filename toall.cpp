#include<bits/stdc++.h>
#define pb(x) push_back(x)
using namespace std;
vector<int> adj[110000];
queue<int> q;
int out[110000];
int jum[110000];
int step[110000];
int main()
{
    int idx;
    int n,c;
    scanf("%d %d",&n,&c);
    int i,j,k;
    int x,a,b;
    for(i=1;i<=c;i++)
    {
        scanf("%d %d %d",&x,&a,&b);
        //adj[x].pb(x);
        adj[x].pb(a);
        adj[x].pb(b);
        adj[a].pb(x);
        adj[b].pb(x);
    }
    q.push(1);
    int h=0;
    int cot=0;
    step[1]=1;
    for(i=1;cot<=n;i++)
    {
        //printf("%d\n",cot);
        idx=q.front();
        /*if(step[idx]>=n)
            break;*/
        out[idx]=step[idx];
        //system("pause");
        for(j=0;j<adj[idx].size();j++)
        {

            if(jum[adj[idx][j]]==0)
            {
                step[adj[idx][j]]=step[idx]+1;
                q.push(adj[idx][j]);
            }

        }
        //cot++;
        cot++;
        if(jum[idx]==0)
        {

            jum[idx]=1;
        }


        q.pop();
    }
    for(i=1;i<=n;i++)
    {
        printf("%d\n",out[i]);
    }

}
