#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int w[100135],jum[100135][3];
vector<int> adj[100135];
int dp(int idx,int aw,int p)
{
    if(jum[idx][aw]>=0)
        return jum[idx][aw];
    int sm=0,i;
    if(aw)
    {
        for(i=0;i<adj[idx].size();i++)
        {
            if(adj[idx][i]==p)continue;
            sm+=dp(adj[idx][i],0,idx);
        }
    }
    else
    {
        for(i=0;i<adj[idx].size();i++)
        {
            if(adj[idx][i]==p)continue;
            sm+=max(dp(adj[idx][i],1,idx)+w[adj[idx][i]],dp(adj[idx][i],0,idx));
        }
    }
    return jum[idx][aw]=sm;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,a,b;
	memset(jum,-1,sizeof jum);
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&w[i]);
    for(i=1;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        a++;b++;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    printf("%d",max(dp(1,0,0),dp(1,1,0)+w[1]));
}
