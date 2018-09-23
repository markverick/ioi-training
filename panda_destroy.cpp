#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define X first
#define Y second
using namespace std;
vector<int> adj[12000];
int edge[12000];
set<int>ed;
int main()
{
    int n,i,j,k;
    scanf("%d",&n);
    for(i=0;i<k;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        adj[a].PB(b);
        adj[b].PB(a);
        edge[a]++;
        edge[b]++;
    }
    for(i=1;i<=n;i++)
    {

    }
}

