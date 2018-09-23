#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int x[200135],ste[200135];
vector<int> v,adj[200135];
void dfs(int idx)
{
    ste[idx]=1;
    v.emplace_back(x[idx]);
    for(int i=0;i<adj[idx].size();i++)
    {
        if(ste[adj[idx][i]])continue;
        dfs(adj[idx][i]);
    }
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,m,i,j,k,a,b,c,mc=0,sum=0,su=0;
	scanf("%d %d %d",&n,&m,&c);
    for(i=1;i<=n;i++)
        scanf("%d",&x[i]);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&a,&b);
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    for(i=1;i<=n;i++)
    {
        if(ste[i])continue;
        v.clear();
        dfs(i);
        sort(v.begin(),v.end());
        mc=1;su=1;
        for(i=1;i<v.size();i++)
        {
            if(v[i]!=v[i-1])
                su=1;
            else
                su++;
            mc=max(mc,su);
        }
        sum+=v.size()-mc;
    }
    printf("%d",sum);
}
