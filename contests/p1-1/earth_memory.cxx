#include<bits/stdc++.h>
using namespace std;
vector<long long> x,y;
int main()
{
    long long T,i,j,k,r,c,n,mnX,mcX,mcY,mnY,a,b;
    scanf("%lld",&T);
    while(T--)
    {
        mnX=1000000000000000000;
        mcX=0;
        mnY=1000000000000000000;
        mcY=0;
        x.clear();y.clear();
        scanf("%lld %lld %lld",&r,&c,&n);
        x.emplace_back(1);
        x.emplace_back(r);
        y.emplace_back(1);
        y.emplace_back(c);
        for(i=1;i<=n;i++)
        {
            scanf("%lld %lld",&a,&b);
            x.emplace_back(a);
            y.emplace_back(b);
        }
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        auto it=unique(x.begin(),x.end());
        x.resize(distance(x.begin(),it));        it=unique(y.begin(),y.end());
        y.resize(distance(y.begin(),it));
        for(i=0;i<x.size()-1;i++)
        {
            mcX=max(mcX,x[i+1]-x[i]);
            mnX=min(mnX,x[i+1]-x[i]);
        }
        for(i=0;i<y.size()-1;i++)
        {
            mcY=max(mcY,y[i+1]-y[i]);
            mnY=min(mnY,y[i+1]-y[i]);
        }
        printf("%lld %lld %lld\n",(long long)(x.size()-1)*(y.size()-1),mnX*mnY,mcX*mcY);
    }

}
