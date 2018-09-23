#include<bits/stdc++.h>
#define X first
#define Y second
#define MAX_INT 1000000000000000000
using namespace std;
long long small[100135],state[100135];
pair<int,int> jum[100135][5];
vector<pair<long long,long long> > adj[100135];
pair<long long,long long> dp(long long idx,long long can) ///return cost ways
{
    if(jum[idx][can].X>=0)
    {
        return jum[idx][can];
    }
    long long i,j,prod=1,mn=MAX_INT,sum=0,cot=0;//000000000;
    pair<long long,long long> tmp,a,b;
    state[idx]=1;
    printf("%lld %lld\n",idx,can);
    if(can==0)
    {
        for(i=0;i<adj[idx].size();i++)
        {
            if(state[adj[idx][i].X])
                continue;
            tmp=dp(adj[idx][i].X,1);
            sum+=tmp.X;
            prod*=tmp.Y;prod%=1000000007;
        }
        state[idx]=0;
        return jum[idx][can]={sum,prod};
    }
    else
    {
        for(i=0;i<adj[idx].size();i++)
        {
            if(state[adj[idx][i].X])
                continue;
            tmp=dp(adj[idx][i].X,0);
            tmp.X+=adj[idx][i].Y;
            prod=tmp.Y;sum=tmp.X;
            for(j=0;j<adj[idx].size();j++)
            {
                if(state[adj[idx][j].X]||i==j)continue;
                a=dp(adj[idx][j].X,1);
                prod*=a.Y;prod%=1000000007;
                sum+=a.X;
            }
            if(mn>sum)
                mn=sum,cot=prod;
            else if(mn==sum)
                cot+=prod;
            cot%=1000000007;
        }
        sum=small[idx];prod=1;
        for(i=0;i<adj[idx].size();i++)
        {
            if(state[adj[idx][i].X])
                continue;
            tmp=dp(adj[idx][i].X,1);
            sum+=tmp.X;
            prod*=tmp.Y;prod%=1000000007;
        }
        if(mn>sum)
            mn=sum,cot=prod;
        else if(mn==sum)
            cot+=prod;
        cot%=1000000007;
    }
    state[idx]=0;
    if(cot==0)
    {
        if(can==1)
            return {small[idx],1};
        else
            return {0,1};
    }
    return jum[idx][can]={mn,cot};
}
int main()
{
    freopen("in.txt","r",stdin);
    long long n,i,j,k,a,b,c;
    for(i=0;i<=100005;i++)
    {
        jum[i][1]={-1,-1};jum[i][0]={-1,-1};
    }
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&small[i]);
    }
    for(i=1;i<n;i++)
    {
        scanf("%lld %lld %lld",&a,&b,&c);
        adj[a].emplace_back(b,c);
        adj[b].emplace_back(a,c);
    }
    pair<long long,long long> tmp=dp(1,1);
    printf("%lld %lld",tmp.X,tmp.Y);
}
