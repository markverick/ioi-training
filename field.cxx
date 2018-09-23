#include<bits/stdc++.h>
using namespace std;
long long L[100135];
long long H[100135];
long long man[100135];
long long passed[100135];
int n,m;
int main()
{
    int i,j,k;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%lld %lld",&L[i],&H[i]);
    }
    for(i=1;i<=m;i++)
    {
        scanf("%lld",&man[i]);
    }
    long long sum=0;
    sort(&man[1],&man[m+1]);
    passed[0]=m;
    for(i=1;i<=n;i++)
    {
        passed[i]=&man[m+1]-lower_bound(&man[1],&man[m+1],H[i]);
        sum+=passed[i]*L[i];
    }
    long long mc=0;
    for(i=1;i<=n;i++)
    {
        mc=max(mc,(passed[i-1]-passed[i])*(L[i]));
    }
    printf("%lld",sum+mc);
}
