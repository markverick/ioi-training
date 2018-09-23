#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int codeFor[80135];
int d[80135];
priority_queue<pair<int,int> > pq;
// -w v
vector<pair<int,int> > adj[80135];
//v w
char ch[5];
int main()
{
    int n,m,i,j,k,a,b,c,q;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%s",ch);
        codeFor[i]=ch[0]*256+ch[1];
        //printf("%d\n",codeFor[i]);
    }
    scanf("%d",&m);
    for(i=1;i<=m;i++)
    {

        scanf("%d %d %d",&a,&b,&c);
        adj[codeFor[a]].emplace_back(codeFor[b],c);
        //adj[codeFor[b]].emplace_back(codeFor[a],c);
    }
    scanf("%d",&q);
    int u,w;
    for(i=0;i<80000;i++)
        d[i]=1000000000;
    for(i=1;i<=q;i++)
    {
        scanf("%d %d",&a,&b);
        a=codeFor[a];
        b=codeFor[b];
        pq.emplace(0,a);
        d[a]=0;
        //int fu=0;
        //if(a==b)
          //  fu=1;
        while(!pq.empty())
        {
            w=-pq.top().X;
            u=pq.top().Y;
            pq.pop();
            //printf("%d %d\n",u,w);

            for(j=0;j<adj[u].size();j++)
            {
                if(d[adj[u][j].X]>w+adj[u][j].Y)
                {
                    d[adj[u][j].X]=w+adj[u][j].Y;
                    pq.emplace(-d[adj[u][j].X],adj[u][j].X);
                }

            }
        }
        if(d[b]==1000000000)
        {
            printf("-1\n");
        }
        else
            printf("%d\n",d[b]);
        while(!pq.empty())
            pq.pop();
        for(j=1;j<=n;j++)
        {
            d[codeFor[j]]=1000000000;
        }

    }

}
