#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
vector<long long> adj[100135];
pair<pair<long long,long long> ,pair<long long,long long> > mx[100135];
long long s[100135],a[100135],b[100135],pa[100135];
void dfs(long long idx,long long p)
{
    long long sm=1,i;
    for(i=0;i<adj[idx].size();i++)
    {
        if(adj[idx][i]==p)continue;
        pa[adj[idx][i]]=idx;
        dfs(adj[idx][i],idx);
        sm+=s[adj[idx][i]];
        if(s[adj[idx][i]]>mx[idx].X.X)
            swap(mx[idx].X,mx[idx].Y),mx[idx].X=MP(s[adj[idx][i]],adj[idx][i]);
        else if(s[adj[idx][i]]>mx[idx].Y.X)
            mx[idx].Y=MP(s[adj[idx][i]],adj[idx][i]);
    }
    s[idx]=sm;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	long long n,i,j,k;
	scanf("%lld",&n);
	for(i=1;i<n;i++)
    {
        scanf("%lld %lld",&a[i],&b[i]);
        adj[a[i]].emplace_back(b[i]);
        adj[b[i]].emplace_back(a[i]);
    }
    dfs(1,0);
//    for(i=1;i<=n;i++)
//        printf("%lld %lld -> %lld\n",mx[i].X,mx[i].Y,s[i]);
    long long mc=0,M=0;
    for(i=1;i<n;i++)
    {
        if(pa[a[i]]==b[i])
            swap(a[i],b[i]);
        mc=n-s[a[i]];
        if(mx[a[i]].X.Y!=b[i])
            mc=max(mc,mx[a[i]].X.X);
        else
            mc=max(mc,mx[a[i]].Y.X);
        M=max(M,mc*(mx[b[i]].X.X));
    }
    printf("%lld\n",M);
}
