#include<bits/stdc++.h>
using namespace std;
int n,m,a,b;
int main()
{
    int i,j,k;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n-1;i++)
    {
        scanf("%d %d",&a,&b);
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
}
