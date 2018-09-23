#include<bits/stdc++.h>
using namespace std;
long long a[300135],b[300135];
deque<long long> dq;
queue<pair<long long,long long> > q;
int main()
{
	long long i,j,k,n,x,co;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(i=1;i<=n;i++)
        scanf("%lld",&b[i]);
    sort(&b[1],&b[n+1]);
    for(i=1;i<=n;i++)
        dq.emplace_back(b[i]);
    for(i=2;i<n;i++)
    {
        if(a[i]>a[i-1]&&a[i]>a[i+1])
            q.emplace(i,2);
        if(a[i]<a[i-1]&&a[i]<a[i+1])
            q.emplace(i,-2);
    }
    q.emplace(1,a[1]>a[2]?1:-1);
    q.emplace(n,a[n]>a[n-1]?1:-1);
    memset(b,-1,sizeof b);
    long long sum=0;
    while(!q.empty())
    {
        tie(x,co)=q.front();
        q.pop();
        if(co>0)
        {
            b[x]=dq.back();
            sum+=co*dq.back();
            dq.pop_back();
        }
        else
        {
            b[x]=dq.front();
            sum+=co*dq.front();
            dq.pop_front();
        }
    }
    for(i=1;i<=n;i++)
    {
        if(b[i]>=0)continue;
        if(a[i]>a[i-1])
        {
            b[i]=dq.front();
            dq.pop_front();
        }
        else
        {
            b[i]=dq.back();
            dq.pop_back();
        }
    }
    printf("%lld\n",sum);
    for(i=1;i<=n;i++)
        printf("%lld ",b[i]);
}
