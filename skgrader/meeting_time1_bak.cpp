#include<bits/stdc++.h>
#define MP(x,y,z) make_pair(x,make_pair(y,z))
#define PB push_back
using namespace std;
int n,m;
vector<pair<int,pair<int,int> > > adj[1200];
pair<int,int> dp(int x,int y)
{

}
int main()
{
    int i,j,k;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++)
    {
        int a,b,c,d;
        scanf("%d %d %d %d",&a,&b,&c,&d);
        adj[a].PB(MP(b,c,d));
    }
    printf("%d",dp(1,1).first);
}
