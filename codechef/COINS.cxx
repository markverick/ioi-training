#include<bits/stdc++.h>
using namespace std;
unordered_map<long long,long long> jum;
long long dfs(long long x)
{
    if(jum.find(x)!=jum.end())
        return jum[x];
    if(x/2+x/3+x/4<x)
    {
        return x;
    }
    return jum[x]=dfs(x/2)+dfs(x/3)+dfs(x/4);
}
int main()
{
    long long T,t,i,j,k,n;
    while(scanf("%lld",&n)!=EOF)
    {
        printf("%lld\n",dfs(n));
    }
}
