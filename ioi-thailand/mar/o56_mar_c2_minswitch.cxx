#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
set<pair<int,int> > adj[110000];
int ck=0,n,m;
int result[110000],state[110000];
void dfs(int idx,int C)
{
    set<pair<int,int> >::iterator it;
    set<pair<int,int> >::iterator itt;
    int i,tmp;
    pair<int,int> p,q;
    state[idx]=1;
    if(idx==n+m+1)
    {
        for(i=1;i<C;i++)
        {
//            printf("%d ",result[i]);
            itt=(adj[result[i]].lower_bound({result[i+1],0}));
            if(itt==adj[result[i]].end())
                p={n+m+2,0};
            else
                p=*itt;
            itt=(adj[result[i+1]].lower_bound({result[i],0}));
            if(itt==adj[result[i+1]].end())
                q={n+m+2,0};
            else
                q=*itt;
            if(p.X==result[i+1])
            {
                adj[result[i]].erase(p);
                if(p.Y>1)
                    adj[result[i]].insert({result[i+1],p.Y-1});
            }
            else if(q.X==result[i])
            {
                adj[result[i+1]].erase(q);
                adj[result[i+1]].insert({result[i],q.Y+1});
            }
            else
            {
                adj[result[i+1]].insert({result[i],1});
            }
        }
//        printf("\n");
//        system("pause");
        ck=1;
        return;
    }
    for(it=adj[idx].begin();it!=adj[idx].end();it++)
    {
        if(state[(*it).X])
            continue;
        result[C+1]=(*it).X;
        dfs((*it).X,C+1);
        if(ck==1)
            return;
    }
}
int main()
{
    set<pair<int,int> >::iterator it;
    int a,b,i,j,k;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
        adj[0].insert({i,m});
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&a,&b);
        adj[a].insert({n+i,1});
        adj[b].insert({n+i,1});
    }
    for(i=n+1;i<=n+m;i++)
        adj[i].insert({n+m+1,1});
    ck=1;
    while(ck==1)
    {
        ck=0;
        memset(state,0,sizeof state);
        result[1]=0;
        dfs(0,1);
    }
    int sum=0;
//    printf("%d\n",adj[0].size());
//    for(it=adj[0].begin();it!=adj[0].end();it++)
//    {
//        printf("%d\n",(*it).Y);
//    }
    for(i=n+1;i<=n+m;i++)
    {
        printf("- - %d - -\n",i);
        for(it=adj[i].begin();it!=adj[i].end();it++)
            printf("%d\n",(*it).X);
//        if(adj[i].find(0)!=adj[i].end())
//            sum++;
    }
}
