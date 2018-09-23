#include<bits/stdc++.h>
using namespace std;
long long x[100135];
long long y[100135];
unordered_map<long long,long long> ha,hb;
int main()
{
    long long n,i,j,k,sum=0;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lld %lld",&x[i],&y[i]);
        ha[x[i]]++;hb[y[i]]++;
    }
    for(i=1;i<=n;i++)
        sum+=(ha[x[i]]-1)*(hb[y[i]]-1);
    printf("%lld",sum);
}
