#include<bits/stdc++.h>
using namespace std;
long long p[2200];

int main()
{
    int n;
    int i,j,k;
    int T,t;
    scanf("%d",&T);
    for(t=0;t<T;t++)
    {
        map<int,bool> hsh;
        long long w,n,l;
        scanf("%lld %lld %lld",&w,&n,&l);
        for(i=0;i<n;i++)
        {
            scanf("%lld",&p[i]);
            hsh[p[i]]=1;
        }
        l=l%w;
        for(i=0;i<n;i++)
        {
            if(hsh[(p[i]+l)%w]==1)
            {
                printf("%d\n",i+1);
                break;
            }
            if(i==n-1)
            {
                printf("-1\n");
            }
        }
    }
}
