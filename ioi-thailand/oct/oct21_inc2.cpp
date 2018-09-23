#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int main()
{
    int n,i,a;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        auto it=lower_bound(v.begin(),v.end(),a);
        if(it==v.end())
            v.emplace_back(a);
        else
            v[it-v.begin()]=a;
    }
    printf("%d",v.size());
}
