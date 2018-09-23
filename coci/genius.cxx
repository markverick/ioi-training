#include<bits/stdc++.h>
using namespace std;
long long p[500135],G=0,hsh[500135],cot[500135];
int main()
{
	long long n,a,b,c,d,i,j,k;
	scanf("%lld %lld %lld %lld %lld",&n,&a,&b,&c,&d);
	for(i=1;i<=n;i++)
        scanf("%lld",&p[i]);
    for(i=1;i<=n;i++)
    {
        if(hsh[i])
            continue;
        hsh[i]=++G;
        k=p[i];
        while(k!=i)
        {
            hsh[k]=G;
            k=p[k];
        }
    }
    for(i=1;i<=n;i++)
        cot[hsh[i]]++;
    vector<long long> v;
    for(i=1+c;i<=n-d;i++)
        v.emplace_back(cot[hsh[i]]);
    sort(v.begin(),v.end());
    auto it=unique(v.begin(),v.end());
    v.resize(it-v.begin());
    long long g=v[0];
    for(i=1;i<v.size();i++)
        g=v[i]*g/__gcd(g,v[i]);
    printf("%lld\n",(b+g-1)/g-(a+g-2)/g);
}
