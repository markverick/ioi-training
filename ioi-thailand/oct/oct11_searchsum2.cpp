#include<bits/stdc++.h>
using namespace std;
int qs[100135];
vector<pair<int,int> > v;
int main()
{
    int n,k,i,j,a,b;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        qs[i]=qs[i-1]+a;
    }
    for(i=1;i<=n;i++)
        for(j=i;j<=n;j++)
            v.emplace_back(qs[j]-qs[i-1],j-i+1);
    sort(v.begin(),v.end());
    for(i=1;i<=k;i++)
    {
        scanf("%d",&a);
        b=upper_bound(v.begin(),v.end(),make_pair(a,1000000000))-v.begin();
        if(b==0)
            printf("0\n");
        else
            printf("%d\n",v[b-1].second);
    }
}
