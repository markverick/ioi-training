#include<bits/stdc++.h>
using namespace std;
int m;
vector<int> v;
inline vector<int> Pow(long long p)
{
    int i,j;
    if(p==1)
    {
        return v;
    }
    vector<int> a=Pow(p/2),b;
    for(i=0;i<a.size();i++)
    {
        for(j=0;j<a.size();j++)
        {
            b.emplace_back((a[i]*a[j])%m);
        }
    }
    sort(b.begin(),b.end());
    auto it=unique(b.begin(),b.end());
    b.resize(distance(b.begin(),it));
    if(p%2)
    {
        a.clear();
        for(i=0;i<b.size();i++)
        {
            for(j=0;j<v.size();j++)
            {
                a.emplace_back((b[i]*v[j])%m);
            }
        }
        sort(a.begin(),a.end());
        it=unique(a.begin(),a.end());
        a.resize(distance(a.begin(),it));
        return a;
    }
    return b;
}
int main()
{
    int n,i,j;
    long long k;
    scanf("%lld %d %d",&k,&m,&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&j);
        v.emplace_back(j);
    }
    vector<int> out=Pow(k);
    for(i=0;i<out.size();i++)
    {
        printf("%d ",out[i]);
    }
}
