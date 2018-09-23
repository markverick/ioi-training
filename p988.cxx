#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1000135];
int n;
int jum[1000135];
int dp(int idx)
{
    if(jum[idx]>=0)return jum[idx];
    if(adj[idx].size()==0)
        return 1;
    int sum=0;
    for(int i=0;i<adj[idx].size();i++)
    {
        sum+=dp(adj[idx][i]);
    }
    return jum[idx]=sum;
}
int main()
{
    int i,j,k,a,b,T=0;
    while(scanf("%d",&n)!=EOF)
    {
        T++;
        if(T>1)
            printf("\n");
        memset(jum,-1,sizeof jum);
        for(i=0;i<=1000000;i++)
        {
            adj[i].clear();
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&a);
            for(j=0;j<a;j++)
            {
                scanf("%d",&b);
                adj[i].emplace_back(b);
            }
        }
        printf("%d\n",dp(0));
    }
}
