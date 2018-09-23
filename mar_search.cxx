#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int main()
{
    int n,m,i,j,k,a;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        v.emplace_back(a);
    }
    sort(v.begin(),v.end());
    for(i=0;i<m;i++)
    {
        scanf("%d",&a);
        printf("%d\n",upper_bound(v.begin(),v.end(),a)-v.begin());
    }
}
