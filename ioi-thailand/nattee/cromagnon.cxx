#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int mat[22][22],jum[105][105][22],a[135];
vector<pair<int,int> > adj[22];
inline int dp(int fs,int ls,int ch)
{
    if(jum[fs][ls][ch]>=0)
        return jum[fs][ls][ch];
    if(fs==ls)
    {
        if(ch==a[fs])
            return 1;
        return 0;
    }
    int sm=0,i,j;
    for(i=fs;i<ls;i++)
    {
        for(j=0;j<adj[ch].size();j++)
            sm+=dp(fs,i,adj[ch][j].X)*dp(i+1,ls,adj[ch][j].Y),sm%=2009;
    }
    return jum[fs][ls][ch]=sm;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,m,i,j,k,mc=0;
	memset(jum,-1,sizeof jum);
	scanf("%d",&n);
	for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&mat[i][j]),adj[mat[i][j]].emplace_back(i,j);
    scanf("%d",&m);
    for(i=1;i<=m;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    {
        printf("%d\n",dp(1,m,i));
    }
}
