#include<bits/stdc++.h>
using namespace std;
long long a[100135],qs[100135];
int main()
{
    int n,i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        qs[i]=qs[i-1]+a[i];
//        printf("%d\n",qs[i]);
    }
    vector<long long> pp;
    vector<long long>::iterator it;
    for(i=1;i<=n;i++)
    {
        if(qs[i]<=0||qs[i]>=qs[n])
            continue;
        it=lower_bound(pp.begin(),pp.end(),qs[i]);
        if(it==pp.end())
            pp.push_back(qs[i]);
        else
            pp[it-pp.begin()]=qs[i];
    }
    printf("%d\n",pp.size()+1);
}
