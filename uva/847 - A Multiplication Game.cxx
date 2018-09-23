#include<bits/stdc++.h>
using namespace std;
unordered_map<long long,long long> jum;
vector<long long> v;
int main()
{
    long long n,i;
    i=1;
    while(i<=4294967295)
    {
        i*=9;
        v.emplace_back(i);
        i*=2;
        v.emplace_back(i);
    }
    while(scanf("%lld",&n)!=EOF)
    {
        if((lower_bound(v.begin(),v.end(),n)-v.begin())%2)
            printf("Ollie wins.\n");
        else
            printf("Stan wins.\n");
    }
}
