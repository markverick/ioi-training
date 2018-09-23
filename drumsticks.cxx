#include<bits/stdc++.h>
#define M 1000000007
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
vector<pair<int,int> > adj[1531],adt[1531],adg[1531],adgt[1531];
vector<int> topo;
vector<int> grp[1531];
int state[1531],G=0,in[1531][1531],out[1531][1531],way[1531],a[1531],b[1531],c[1531],d[1531];
priority_queue<pair<int,int> > pq;
void tp(int idx)
{
    state[idx]=1;
    for(int i=0;i<adt[idx].size();i++)
    {
        if(state[adt[idx][i].X])
            continue;
        tp(adt[idx][i].X);
    }
    topo.emplace_back(idx);
}
void dfs(int idx)
{
    state[idx]=G;
    grp[G].emplace_back(idx);
    for(int i=0;i<adj[idx].size();i++)
    {
        if(state[adj[idx][i].X])
            continue;
        dfs(adj[idx][i].X);
    }
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,m,i,j,k,u,w;
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;i++)
    {
        scanf("%d %d %d",&a[i],&b[i],&c[i]);
        adj[a[i]].emplace_back(b[i],c[i]);
        adt[b[i]].emplace_back(a[i],c[i]);
    }
    for(i=1;i<=n;i++)
    {
        if(state[i])
            continue;
        tp(i);
    }
    memset(state,0,sizeof state);
    for(i=topo.size()-1;i>=0;i--)
    {
        if(state[topo[i]])
            continue;
        G++;
        dfs(topo[i]);
    }
//    for(i=1;i<=G;i++)
//    {
//        for(j=0;j<grp[i].size();j++)
//            printf("%d ",grp[i][j]);
//        printf("\n");
//    }
    for(i=1;i<=m;i++)
    {
        if(state[a[i]]!=state[b[i]])
        {
            adg[state[a[i]]].emplace_back(state[b[i]],c[i]);            adgt[state[b[i]]].emplace_back(state[a[i]],c[i]);
        }
    }
    for(i=1;i<=G;i++)
    {
        memset(way,0,sizeof way);
        for(j=1;j<=G;j++)
            d[j]=MI;
        pq.emplace(0,i);
        way[i]=1;
        while(!pq.empty())
        {
            tie(w,u)=pq.top();
            pq.pop();
            w=-w;
            for(j=0;j<adg[u].size();j++)
            {
                if(w+adg[u][j].Y<d[adg[u][j].X])
                {
                    d[adg[u][j].X]=w+adg[u][j].Y;
                    way[adg[u][j].X]=way[u];
                    pq.emplace(-d[adg[u][j].X],adg[u][j].X);
                }
                else if(w+adg[u][j].Y==d[adg[u][j].X])
                    way[adg[u][j].X]+=way[u];
            }
        }
        for(j=1;j<=G;j++)
            in[i][j]=way[j],in[i][j]%=M;
        for(j=1;j<=G;j++)
            printf("%d ",way[j]);
        printf("\n");
        for(k=1;k<=G;k++)
        {
            out[i][k]=1;
            for(j=0;j<adg[k].size();j++)
            {
                if(d[k]+adg[k][j].Y==d[adg[k][j].X])
                    out[i][k]+=way[adg[k][j].X];
            }
        }
    }
//    for(i=G;i>=1;i--)
//    {
//        printf("%d %d\n",in[i],out[i]);
//    }
    int sum=0;
    for(i=1;i<=m;i++)
    {
        sum=0;
        for(j=1;j<=G;j++)
        {
            sum+=in[j][state[a[i]]]*out[j][state[b[i]]];
            printf("%d %d\n",in[j][state[a[i]]],out[j][state[b[i]]]);
        }
        printf("%d\n",sum);
//        printf("%d\n",(in[state[a[i]]])*(out[state[b[i]]]));
    }
}
