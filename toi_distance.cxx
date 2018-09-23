#include<bits/stdc++.h>
using namespace std;
vector<long long> x;
vector<long long> y;
long long qsx[500135];
long long qsy[500135];
int main()
{
    long long n,i,j,k,a,b;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lld %lld",&a,&b);
        x.emplace_back(a);
        y.emplace_back(b);

    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    for(i=0;i<n;i++)
    {
        qsx[i+1]=qsx[i]+x[i];
        qsy[i+1]=qsy[i]+y[i];
    }
    long long sumx=0,sumy=0;
    for(i=1;i<x.size();i++)
    {
        sumx+=i*x[i]-qsx[i];
    }
    for(i=1;i<y.size();i++)
    {
        sumy+=i*y[i]-qsy[i];
    }
    printf("%lld",sumx+sumy);
}
