#include<bits/stdc++.h>
using namespace std;
vector<long long> v;
int main()
{
    long long n,i=1,c=0;
    while(i<=4594967296)
    {
        if(c%2==0)
            i*=9;
        else
            i*=2;
        v.emplace_back(i);
        c++;
        //printf("%d\n",i);
    }
    long long x=0;
    while(scanf("%lld",&n)!=EOF)
    {
        x=lower_bound(v.begin(),v.end(),n)-v.begin();
        if(x%2==0)
            printf("Aris wins.\n");
        else
            printf("Nontun wins.\n");
    }
}
