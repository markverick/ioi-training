#include<bits/stdc++.h>
using namespace std;
long long x[100135],y[100135],z[100135],l[100135],Sum[100135],Sq[100135];
vector<long long> adj[100135];
long long Pow(long long b,long long p)
{
    if(p==0)
        return 1;
    long long tmp=Pow(b,p/2);
    tmp*=tmp;
    tmp%=9907;
    if(p%2)
        tmp*=b,tmp%=9907;
    return tmp;
}
int main()
{
    long long i,j,k,a,b,sum=0,all=0,n,sq=0;
    scanf("%lld",&n);
    for(i=1;i<n;i++)
    {
        scanf("%lld %lld",&a,&b);
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    for(i=1;i<=n;i++)
    {
        scanf("%lld %lld %lld",&x[i],&y[i],&z[i]);
    }
    long long tmp;
    for(i=1;i<=n;i++)
    {
        sum=0;sq=0;
        for(j=0;j<adj[i].size();j++)
        {
            sq+=x[adj[i][j]]*x[adj[i][j]];
            sq%=9907;
            sum+=x[adj[i][j]];
            sum%=9907;
        }
        for(j=0;j<adj[i].size();j++)
        {
            Sum[adj[i][j]]+=sum-x[adj[i][j]];
            Sum[adj[i][j]]%=9907;
            Sq[adj[i][j]]+=sq-x[adj[i][j]]*x[adj[i][j]];
            Sq[adj[i][j]]%=9907;
        }
    }
    long long tmp2;
    for(i=1;i<=n;i++)
    {
        tmp2=Sum[i]*Sum[i]-Sq[i];
        while(tmp2<0)tmp2+=9907;
        tmp=(tmp2)*Pow(2,9905);
        tmp%=9907;
        all+=tmp*y[i]+z[i];
        all%=9907;
    }
    printf("%lld",all);
}
