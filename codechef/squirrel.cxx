#include<bits/stdc++.h>
using namespace std;
long long x[10135],y[10135],z[10135];
int main()
{
    long long T,n,m,b,i,j,k,fst,mid,lst,sum=0,mn;
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld %lld %lld",&m,&n,&b);
        for(i=1;i<=m;i++)
            scanf("%lld",&x[i]);
        for(i=1;i<=m;i++)
            scanf("%lld",&y[i]);
        fst=0;lst=1000000005;mn=1000000005;
        while(fst<=lst)
        {
            mid=(fst+lst)/2;sum=0;
            for(i=1;i<=m;i++)
            {
                if(mid<x[i])
                    z[i]=0;
                else
                    z[i]=(mid-x[i])/y[i]+1;
            }
            sort(&z[1],&z[m+1]);
            for(i=m;i>=max(1ll,m-n+1);i--)
            {
                sum+=z[i];
            }
            if(sum>=b)
            {
                mn=min(mn,mid);
                lst=mid-1;
            }
            else
                fst=mid+1;
        }
        printf("%lld\n",mn);
    }
}
