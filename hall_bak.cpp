#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
using namespace std;
vector<pair<int,long long> > adj[20];
//        vertex,weight
// adj[Vstart][MP(Vend,Weight)
//
// WWWW   WWWW TTTTTTT FFFFF
//  WW     WW  T  T  T F
//  WW WWW WW     T    FFF
//   WWW WWW     TTT   F
int n,l;//            FFF
int chk[20];
long long jum[20];
long long dp(int vert)
{
    if(vert==n)
    {
        return 0;
    }
    if(jum[vert]>=0)
        return jum[vert];
    //printf("%d\n",vert);
    int i,j;
    long long lo=922337203685477000;
    for(i=0;i<adj[vert].size();i++)
    {
        if(chk[adj[vert][i].first]==1)
            continue;
        chk[adj[vert][i].first]=1;
        lo=min(lo,dp(adj[vert][i].first)+adj[vert][i].second);
        chk[adj[vert][i].first]=0;
    }
    return jum[vert]=lo;
}
int main()
{
    long long a,b,m;
    scanf("%d %d",&n,&l);
    int i,j,k;
    memset(jum,-1,sizeof jum);
    for(i=0;i<l;i++)
    {
        scanf("%lld %lld %lld",&a,&b,&m);
        adj[a].PB(MP(b,m));
        adj[b].PB(MP(a,m));
    }
    long long out=dp(1);
    printf("%lld\n",(out-1)/5+1);

}
