#include<bits/stdc++.h>
using namespace std;
int c[60005],a[60005],olo[60005];
int teema[60005],state[60005];
int sp[60005][50];
vector<int> adj[60005];
vector<int> adi[60005];
vector<int> v,hi;
queue<int> q;
void dfs(int idx,int h)
{
    for(int i=0;i<adj[idx].size();i++)
    {
        v.emplace_back(adj[idx][i]);
        hi.emplace_back(h+1);
        dfs(adj[idx][i],h+1);
        v.emplace_back(idx);
        hi.emplace_back(h);
    }
}
int main()
{
    int n,i,j,k,m,x,y,T,t=1,a,u,b,sum=0;
    scanf("%d",&n);
    for(i=1;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        adi[a].emplace_back(b);
        adi[b].emplace_back(a);
    }
    q.emplace(1);
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        state[u]=1;
        for(i=0;i<adi[u].size();i++)
        {
            if(state[adi[u][i]])continue;
            adj[u].emplace_back(adi[u][i]);
            q.emplace(adi[u][i]);
        }
    }
    v.emplace_back(1);
    hi.emplace_back(0);
    dfs(1,0);
    for(i=0;i<v.size();i++)
    {
        teema[v[i]]=i;
    }
    for(i=0;i<hi.size();i++)
        sp[i][0]=i;
    for(j=1;(1<<j)<=hi.size();j++)
    {
        for(i=0;i+(1<<j)<=hi.size();i++)
        {
            if(hi[sp[i][j-1]]<hi[sp[i+(1<<(j-1))][j-1]])
                sp[i][j]=sp[i][j-1];
            else
                sp[i][j]=sp[i+(1<<(j-1))][j-1];
        }
    }
    scanf("%d",&m);
    int tmp;
    for(i=1;i<=m;i++)
    {
        scanf("%d",&olo[i]);
    }
    for(i=2;i<=m;i++)
    {
        x=olo[i-1];y=olo[i];
        if(x==y)
        {
            continue;
        }
        x=teema[x];y=teema[y];
        if(x>y)
        {
            tmp=x;x=y;y=tmp;
        }
        //printf("%d %d\n",x,y);
        int sz=(int)floor(log2(y-x+1)),mn;
        if(hi[sp[x][sz]]<hi[sp[y-(1<<(sz))+1][sz]])
            mn=sp[x][sz];
        else
            mn=sp[y-(1<<(sz))+1][sz];
        sum+=hi[x]-hi[mn];
        sum+=hi[y]-hi[mn];
        //printf("%d\n",sum);
    }
    printf("%d",sum);
}
