#include<bits/stdc++.h>
using namespace std;
vector<long long> a;
long long n,b;
int main()
{
    int i,j,k;
    scanf("%lld",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&b);
        a.emplace_back(b);
    }
    if(n<3)
    {
        printf("0\n");
        return 0;
    }
    sort(a.begin(),a.end());
    long long mc=0;
    auto it=a.begin();
    for(i=0;i<n-1;i++)
    {
        mc=max(mc,(long long)(lower_bound(a.begin(),a.end(),a[i]+a[i+1])-it));
        it++;
    }
    printf("%lld\n",mc);
}
