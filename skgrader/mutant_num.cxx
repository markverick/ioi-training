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
    int hsh[1505],ha[1505];
    memset(hsh,0,sizeof hsh);
    memset(ha,0,sizeof ha);
    for(i=0;i<a.size();i++)
    {
        for(j=0;j<a.size();j++)
        {
            hsh[(a[i]*a[j])%m]=1;
        }
    }
    if(p%2)
    {
        for(i=0;i<m;i++)
        {
            if(hsh[i])
            {
                for(j=0;j<v.size();j++)
                {
                    ha[(v[j]*i)%m]=1;
                }
            }
        }
        for(i=0;i<m;i++)
        {
            if(ha[i])
                b.emplace_back(i);
        }
        return b;
    }
    for(i=0;i<m;i++)
    {
        if(hsh[i])
            b.emplace_back(i);
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
